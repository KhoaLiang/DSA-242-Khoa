#include <iostream>
#include <string>
#include <sstream>
#include "app/inventory_compressor.h"
#include "app/inventory.h"

using namespace std;

typedef HuffmanTree<3> HTree;
typedef HTree::HuffmanNode HNode;
typedef InventoryCompressor<4> InvCompressor;

int charHashFunc(char& key, int tablesize) {
    return (int)key % tablesize;
}

void tc_huffman1001() {
    XArrayList<pair<char, int>> symbolFreqs;
    symbolFreqs.add(make_pair('A', 5));
    
    HTree tree;
    tree.build(symbolFreqs);
    
    xMap<char, string> codeTable(&charHashFunc);
    tree.generateCodes(codeTable);
    
    string codeA = codeTable.get('A');
    cout << "Code for A: " << codeA << endl;
    
    string decoded = tree.decode(codeA);
    cout << "Decoded string: " << decoded << endl;
}

void tc_huffman1002() {
    XArrayList<pair<char, int>> symbolFreqs;
    symbolFreqs.add(make_pair('A', 5));
    symbolFreqs.add(make_pair('B', 3));
    symbolFreqs.add(make_pair('C', 7));
    symbolFreqs.add(make_pair('D', 2));
    
    HTree tree;
    tree.build(symbolFreqs);
    
    xMap<char, string> codeTable(&charHashFunc);
    tree.generateCodes(codeTable);
    
    cout << "Generated codes:" << endl;
    for (char ch = 'A'; ch <= 'D'; ++ch) {
        string code = codeTable.get(ch);
        cout << "Code for " << ch << ": " << code << endl;
    }
}

void tc_huffman1003() {    
    XArrayList<pair<char, int>> symbolFreqs;
    symbolFreqs.add(make_pair('X', 4));
    symbolFreqs.add(make_pair('Y', 6));
    symbolFreqs.add(make_pair('Z', 2));
    
    HTree tree;
    tree.build(symbolFreqs);
    
    xMap<char, string> codeTable(&charHashFunc);
    tree.generateCodes(codeTable);
    
    string codeZ = codeTable.get('Z');
    cout << "Code for Z: " << codeZ << endl;
    
    string decoded = tree.decode(codeZ);
    cout << "Decoded string: " << decoded << endl;
}

void tc_huffman1004() {
    XArrayList<pair<char, int>> symbolFreqs;
    symbolFreqs.add(make_pair('M', 3));
    symbolFreqs.add(make_pair('N', 5));
    
    HTree tree;
    tree.build(symbolFreqs);
    
    xMap<char, string> codeTable(&charHashFunc);
    tree.generateCodes(codeTable);

    string decoded = tree.decode("0");
    cout << "Decoded string from invalid code: " << decoded << endl;
}

void tc_huffman1005() {
    XArrayList<pair<char, int>> symbolFreqs;
    const string symbols = "ABCDEFGHIJ";
    int n = symbols.size();
    for (int i = 0; i < n; ++i) {
        symbolFreqs.add(make_pair(symbols[i], (i + 1) * 2));
    }
    
    HTree tree;
    tree.build(symbolFreqs);
    
    xMap<char, string> codeTable(&charHashFunc);
    tree.generateCodes(codeTable);
    
    for (char ch : symbols) {
        string code = codeTable.get(ch);
        string decoded = tree.decode(code);
        cout << ch << " with code " << code << " decodes as: " << decoded << endl;
    }
}

void tc_compressor1001() {    
    InventoryManager manager;
    List1D<InventoryAttribute> attrs;
    attrs.add(InventoryAttribute("weight", 2.5));
    attrs.add(InventoryAttribute("voltage", 12.0));
    manager.addProduct(attrs, "Gadget", 50);
    
    InvCompressor compressor(&manager);
    compressor.buildHuffman();
    
    string encoded = compressor.encodeHuffman(attrs, "Gadget");
    cout << "Encoded product: " << encoded << endl;
}

void tc_compressor1002() {    
    InventoryManager manager;
    
    List1D<InventoryAttribute> carAttrs;
    carAttrs.add(InventoryAttribute("speed", 88.0));
    manager.addProduct(carAttrs, "Car", 1);
    
    List1D<InventoryAttribute> batteryAttrs;
    batteryAttrs.add(InventoryAttribute("capacity", 250.0));
    batteryAttrs.add(InventoryAttribute("voltage", 12.0));
    manager.addProduct(batteryAttrs, "Battery", 5);
    
    InvCompressor compressor(&manager);
    compressor.buildHuffman();
    compressor.printHuffmanTable(); 
    
    string encodedCar = compressor.encodeHuffman(carAttrs, "Car");
    string encodedBattery = compressor.encodeHuffman(batteryAttrs, "Battery");
    
    cout << "Encoded Car: " << encodedCar << endl;
    cout << "Encoded Battery: " << encodedBattery << endl;
}