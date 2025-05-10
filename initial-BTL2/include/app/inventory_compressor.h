#ifndef INVENTORY_COMPRESSOR_H
#define INVENTORY_COMPRESSOR_H

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <stdexcept>
#include <utility>
#include "inventory.h"
#include "hash/xMap.h"
#include "heap/Heap.h"
#include "list/XArrayList.h"

template<int treeOrder>
class HuffmanTree {
public:
    struct HuffmanNode {
        char symbol;
        int freq;
        XArrayList<HuffmanNode*> children;

        HuffmanNode(char s, int f); //Leaf node
        HuffmanNode(int f, const  XArrayList<HuffmanNode*>& childs); //Internal node
    };

    HuffmanTree();
    ~HuffmanTree();

    void build(XArrayList<pair<char, int>>& symbolsFreqs);
    void generateCodes(xMap<char, std::string>& table);
    std::string decode(const std::string& huffmanCode);
    void deleteSubtree(HuffmanNode* node);

private:
    HuffmanNode* root;

    // Helper method for recursive traversal
    void traverse(HuffmanNode* node, const std::string& code, xMap<char, std::string>& table);
};

// Constructor for leaf nodes
template <int treeOrder>
HuffmanTree<treeOrder>::HuffmanNode::HuffmanNode(char s, int f)
    : symbol(s), freq(f), children() {}

// Constructor for internal nodes
template <int treeOrder>
HuffmanTree<treeOrder>::HuffmanNode::HuffmanNode(int f, const XArrayList<HuffmanNode*>& childs)
    : symbol('\0'), freq(f), children(childs) {}

template<int treeOrder>
class InventoryCompressor {
public:
    InventoryCompressor(InventoryManager* manager);
    ~InventoryCompressor();

    void buildHuffman();
    void printHuffmanTable();
    std::string productToString(const List1D<InventoryAttribute>& attributes, const std::string& name);
    std::string encodeHuffman(const List1D<InventoryAttribute>& attributes, const std::string& name);
    std::string decodeHuffman(const std::string& huffmanCode, List1D<InventoryAttribute>& attributesOutput, std::string& nameOutput);

private:
    xMap<char, std::string>* huffmanTable;
    InventoryManager* invManager;
    HuffmanTree<treeOrder>* tree;
};


#endif // INVENTORY_COMPRESSOR_H

template <int treeOrder>
HuffmanTree<treeOrder>::HuffmanTree() : root(nullptr) {
    // Initialize the root pointer to nullptr
}

template <int treeOrder>
HuffmanTree<treeOrder>::~HuffmanTree() {
    // Recursively delete all nodes in the Huffman tree
    if (root != nullptr) {
        deleteSubtree(root);
    }
}

// Helper function to recursively delete all nodes in the tree
template <int treeOrder>
void HuffmanTree<treeOrder>::deleteSubtree(HuffmanNode* node) {
    if (node == nullptr) {
        return;
    }

    // Recursively delete all child nodes
    for (int i = 0; i < node->children.size(); i++) {
        deleteSubtree(node->children.get(i));
    }

    // Delete the current node
    delete node;
}

//another helper function
template <int treeOrder>
void HuffmanTree<treeOrder>::traverse(HuffmanNode* node, const std::string& code, xMap<char, std::string>& table) {
    if (node->children.empty()) {
        // Skip dummy nodes
        if (node->symbol != '\0') {
            table.put(node->symbol, code);
        }
        return;
    }

    // Internal node: Traverse each child
    for (int i = 0; i < node->children.size(); ++i) {
        traverse(node->children.get(i), code + std::to_string(i), table);
    }
}

template <int treeOrder>
void HuffmanTree<treeOrder>::build(XArrayList<pair<char, int>>& symbolsFreqs) {
    // Step 1: Create a heap from the given list
    Heap<HuffmanNode*> heap([](HuffmanNode*& a, HuffmanNode*& b) {
        return a->freq < b->freq ? -1 : (a->freq > b->freq ? 1 : 0);
    });

    for (auto& symbolFreq : symbolsFreqs) {
        heap.push(new HuffmanNode(symbolFreq.first, symbolFreq.second));
    }

    // Step 2: Add dummy nodes if needed
    int L = symbolsFreqs.size();
    int dummiesNeeded = (treeOrder - ((L - 1) % (treeOrder - 1) + 1)) % (treeOrder - 1);
    for (int i = 0; i < dummiesNeeded; ++i) {
        heap.push(new HuffmanNode('\0', 0)); // Dummy node with frequency 0
    }

    // Debug: Print dummy node count
    // std::cout << "Added " << dummiesNeeded << " dummy nodes." << std::endl;

    // Step 3: Build the tree
    while (heap.size() > 1) {
        XArrayList<HuffmanNode*> children;
        int totalFreq = 0;

        // Select up to treeOrder nodes with the lowest frequencies
        for (int i = 0; i < treeOrder && !heap.empty(); ++i) {
            HuffmanNode* node = heap.pop();
            children.add(node);
            totalFreq += node->freq;
        }

        // Create a new internal node
        HuffmanNode* internalNode = new HuffmanNode(totalFreq, children);
        heap.push(internalNode);
    }

    // Step 4: The last remaining node becomes the root
    root = heap.pop();

    // Debug: Print the root frequency
    // if (root != nullptr) {
    //     std::cout << "Huffman tree built successfully. Root frequency: " << root->freq << std::endl;
    // } else {
    //     std::cerr << "Error: Huffman tree root is null." << std::endl;
    // }
}

template <int treeOrder>
void HuffmanTree<treeOrder>::generateCodes(xMap<char, std::string>& table) {
    if (root != nullptr) {
        // Handle single-node tree
        if (root->children.empty()) {
            table.put(root->symbol, ""); // Single symbol gets an empty code
        } else {
            traverse(root, "", table);
        }

        // Debug: Print the generated codes
        // DLinkedList<char> keys = table.keys();
        // for (char key : keys) {
        //     std::cout << "Generated code for '" << key << "': " << table.get(key) << std::endl;
        // }
    } else {
        std::cerr << "Error: Huffman tree root is null. Tree might not be built correctly." << std::endl;
    }
}
template <int treeOrder>
std::string HuffmanTree<treeOrder>::decode(const std::string& huffmanCode) {
    std::string result;
    HuffmanNode* currentNode = root;

    for (char ch : huffmanCode) {
        if (currentNode == nullptr) {
            return "\x00"; // Invalid code
        }

        int index = ch - '0'; // Convert character to integer
        if (index < 0 || index >= currentNode->children.size()) {
            return "\x00"; // Invalid code
        }

        currentNode = currentNode->children.get(index);

        // If we reach a leaf node, append the symbol to the result
        if (currentNode->children.empty()) {
            if (currentNode->symbol == '\0') {
                return "\x00"; // Invalid code (dummy node)
            }
            result += currentNode->symbol;
            currentNode = root; // Reset to root for the next character
        }
    }

    // If the traversal ends without reaching a leaf node, the code is invalid
    if (currentNode != root) {
        return "\x00"; // Invalid code
    }

    return result;
}
template <int treeOrder>
InventoryCompressor<treeOrder>::InventoryCompressor(InventoryManager *manager)
{
    //TODO
}

template <int treeOrder>
InventoryCompressor<treeOrder>::~InventoryCompressor()
{
    //TODO
}

template <int treeOrder>
void InventoryCompressor<treeOrder>::buildHuffman()
{
    //TODO
}

template <int treeOrder>
void InventoryCompressor<treeOrder>::printHuffmanTable() {
    DLinkedList<char> keys = huffmanTable->keys();
    for (char ch : keys) {
        std::cout << "'" << ch << "' : " << huffmanTable->get(ch) << std::endl;
    }
}

template <int treeOrder>
std::string InventoryCompressor<treeOrder>::productToString(const List1D<InventoryAttribute> &attributes, const std::string &name)
{
    //TODO
    return std::string();
}

template <int treeOrder>
std::string InventoryCompressor<treeOrder>::encodeHuffman(const List1D<InventoryAttribute> &attributes, const std::string &name)
{
    //TODO
    return std::string();
}

template <int treeOrder>
std::string InventoryCompressor<treeOrder>::decodeHuffman(const std::string &huffmanCode, List1D<InventoryAttribute> &attributesOutput, std::string &nameOutput)
{
    //TODO
    return std::string();
}