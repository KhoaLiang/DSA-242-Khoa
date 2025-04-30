#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <queue>
using namespace std;

template<class K, class V>
class BinaryTree
{
public:
    class Node;
private:
    Node* root;
public:
    BinaryTree() : root(nullptr) {}
    ~BinaryTree()
    {
        // You have to delete all Nodes in BinaryTree. However in this task, you can ignore it.
    }
    class Node
    {
    private:
        K key;
        V value;
        Node* pLeft, * pRight;
        friend class BinaryTree<K, V>;
    public:
        Node(K key, V value) : key(key), value(value), pLeft(NULL), pRight(NULL) {}
        ~Node() {}
    };
    void addNode(string posFromRoot, K key, V value)
    {
        if (posFromRoot == "")
        {
            this->root = new Node(key, value);
            return;
        }
        Node* walker = this->root;
        int l = posFromRoot.length();
        for (int i = 0; i < l - 1; i++)
        {
            if (!walker)
                return;
            if (posFromRoot[i] == 'L')
                walker = walker->pLeft;
            if (posFromRoot[i] == 'R')
                walker = walker->pRight;
        }
        if (posFromRoot[l - 1] == 'L')
            walker->pLeft = new Node(key, value);
        if (posFromRoot[l - 1] == 'R')
            walker->pRight = new Node(key, value);
    }
    // STUDENT ANSWER BEGIN 
    // You can define other functions here to help you.

    int getHeight() {
        // TODO: return height of the binary tree.
        // If root is NULL:
        //     Return 0  // An empty tree has a height of 0
        if (root == nullptr)
        {
            return 0;
        }
        

        // Define a helper function getHeightRecursive(node):
        //     If node is NULL:
        //         Return 0  // Base case: no height for a null node
        //     Else:
        //         leftHeight = getHeightRecursive(node.pLeft)  // Recursively calculate height of left subtree
        //         rightHeight = getHeightRecursive(node.pRight)  // Recursively calculate height of right subtree
        //         Return 1 + max(leftHeight, rightHeight)  // Add 1 for the current node and return the maximum height

        // Return getHeightRecursive(root)  // Start the recursion from the root node
        return getHeightRecursive(root);
    }
    int getHeightRecursive(Node* node){
        if (node == nullptr)
        {
            return 0;
        }
        else{
            int leftHeight = getHeightRecursive(node->pLeft);
            int rightHeight = getHeightRecursive(node->pRight);
            return 1 + max(leftHeight, rightHeight);
        }
    }
    string preOrder() {
        stringstream result;
        preOrderRecursive(root, result); // Call the helper function
        string output = result.str();
        if (!output.empty()) output.pop_back(); // Remove trailing space
        return output;
    }

    void preOrderRecursive(Node* node, stringstream& result) {
        if (node == nullptr) return;
        result << node->value << " ";// Visit the current node
        preOrderRecursive(node->pLeft, result);// Traverse the left subtree
        preOrderRecursive(node->pRight, result);// Traverse the right subtree
    }

    string inOrder() {
        stringstream result;
        inOrderRecursive(root, result); // Call the helper function
        string output = result.str();
        if (!output.empty()) output.pop_back(); // Remove trailing space
        return output;
    }

    void inOrderRecursive(Node* node, stringstream& result) {
        if (node == nullptr) return;
        inOrderRecursive(node->pLeft, result); // Traverse the left subtree
        result << node->value << " "; // Visit the current node
        inOrderRecursive(node->pRight, result); // Traverse the right subtree
    }

    string postOrder() {
        stringstream result;
        postOrderRecursive(root, result); // Call the helper function
        string output = result.str();
        if (!output.empty()) output.pop_back(); // Remove trailing space
        return output;
    }

    void postOrderRecursive(Node* node, stringstream& result) {
        if (node == nullptr) return;
        postOrderRecursive(node->pLeft, result); // Traverse the left subtree
        postOrderRecursive(node->pRight, result); // Traverse the right subtree
        result << node->value << " "; // Visit the current node
    }
    void BFS(){
        if(root == nullptr) return;

        queue<*Node> q;
        p.push(root);

        while (!q.empty())
        {
            Node* current = q.front();

            q.pop();

            cout << current->value; << " ";

            if (current->pLeft != nullptr)
            {
                q.push(current->pLeft);
            }
            if (current->pRight != nullptr)
            {
                q.push(current->pRight);
            }
        }
        cout << endl;
    }
    // STUDENT ANSWER END
};

int main() {
    BinaryTree<int, string> tree;

    // Adding nodes to the binary tree
    tree.addNode("", 1, "Root");       // Root node
    tree.addNode("L", 2, "Left");      // Left child of root
    tree.addNode("R", 3, "Right");     // Right child of root
    tree.addNode("LL", 4, "LeftLeft"); // Left child of the left node
    tree.addNode("LR", 5, "LeftRight");// Right child of the left node

    // Testing tree height
    cout << "Height of tree: " << tree.getHeight() << endl;

    // Testing traversal methods
    cout << "Pre-order traversal: " << tree.preOrder() << endl;
    cout << "In-order traversal: " << tree.inOrder() << endl;
    cout << "Post-order traversal: " << tree.postOrder() << endl;
    cout << "Breadth First Search traversal: " ; tree.BFS();
    return 0;
}