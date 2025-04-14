#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

class BSTNode {
public: 
    int val; 
    BSTNode *left; 
    BSTNode *right; 
    BSTNode() {
        this->left = this->right = nullptr;
    } 
    BSTNode(int val) {
        this->val = val;
        this->left = this->right = nullptr;
    } 
    BSTNode(int val, BSTNode*& left, BSTNode*& right) {
        this->val = val;
        this->left = left;
        this->right = right;
    } 

    // Static method to create a binary search tree
    static BSTNode* createBSTree(int* start, int* end) {
        if (start == end) return nullptr;
        BSTNode* root = new BSTNode(*start);
        for (int* it = start + 1; it < end; ++it) {
            root->addNode(*it);
        }
        return root;
    }

    // Method to add a node to the binary search tree
    void addNode(int value) {
        if (value <= this->val) {
            if (this->left) {
                this->left->addNode(value);
            } else {
                this->left = new BSTNode(value);
            }
        } else {
            if (this->right) {
                this->right->addNode(value);
            } else {
                this->right = new BSTNode(value);
            }
        }
    }
};

vector<int> levelAlterTraverse(BSTNode* root) {
    vector<int> result;
    if (!root) return result; // If the tree is empty, return an empty vector.

    queue<BSTNode*> q; // Queue for level-order traversal.
    q.push(root);
    bool leftToRight = true; // Flag to alternate traversal direction.

    while (!q.empty()) {
        int levelSize = q.size(); // Number of nodes at the current level.
        vector<int> levelNodes(levelSize); // Temporary vector to store nodes at the current level.

        for (int i = 0; i < levelSize; ++i) {
            BSTNode* current = q.front();
            q.pop();

            // Insert the node's value into the correct position based on the traversal direction.
            int index = leftToRight ? i : (levelSize - 1 - i);
            levelNodes[index] = current->val;

            // Add the left and right children to the queue for the next level.
            if (current->left) q.push(current->left);
            if (current->right) q.push(current->right);
        }

        // Add the current level's nodes to the result.
        result.insert(result.end(), levelNodes.begin(), levelNodes.end());

        // Alternate the traversal direction for the next level.
        leftToRight = !leftToRight;
    }

    return result;
}

// Helper function to print a vector
void printVector(const vector<int>& vec) {
    for (int val : vec) {
        cout << val << " ";
    }
    cout << endl;
}
int kthSmallest(BSTNode* root, int k) {
    stack<BSTNode*> s;
    BSTNode* current = root;

    while (!s.empty() || current != nullptr) {
        // Traverse to the leftmost node
        while (current != nullptr) {
            s.push(current);
            current = current->left;
        }

        // Process the node at the top of the stack
        current = s.top();
        s.pop();
        k--;

        // If k becomes 0, we have found the k-th smallest element
        if (k == 0) {
            return current->val;
        }

        // Move to the right subtree
        current = current->right;
    }

    return -1; // This should never be reached if k is valid
}

int singleChild(BSTNode* root) {
    if (!root) return 0; // Base case: if the tree is empty, return 0.

    int count = 0;

    // Check if the current node has a single child
    if ((root->left && !root->right) || (!root->left && root->right)) {
        count = 1;
    }

    // Recursively count single children in the left and right subtrees
    return count + singleChild(root->left) + singleChild(root->right);
}
BSTNode* subtreeWithRange(BSTNode* root, int lo, int hi) {
    if (!root) return nullptr; // Base case: if the tree is empty, return nullptr.

    // Recursively process the left and right subtrees
    root->left = subtreeWithRange(root->left, lo, hi);
    root->right = subtreeWithRange(root->right, lo, hi);

    // If the current node's value is outside the range, remove it
    if (root->val < lo) {
        BSTNode* rightSubtree = root->right;
        delete root; // Free the memory of the current node
        return rightSubtree; // Replace the current node with its right subtree
    }
    if (root->val > hi) {
        BSTNode* leftSubtree = root->left;
        delete root; // Free the memory of the current node
        return leftSubtree; // Replace the current node with its left subtree
    }

    // If the current node's value is within the range, keep it
    return root;
}
// Test function for levelAlterTraverse
// int main() {
//     int arr[] = {3, 0, 4, 2, 1};
//     BSTNode* root = BSTNode::createBSTree(arr, arr + sizeof(arr) / sizeof(int));

//     vector<int> result = levelAlterTraverse(root);
//     printVector(result); // Expected output: 3 4 0 2 1

//     return 0;
// }

//test kthSmallest 1
// int main(){
//     int arr[] = {1, 0, 48, 12, 49};
//     int k = 2;
//     BSTNode* root = BSTNode::createBSTree(arr, arr + sizeof(arr) / sizeof(int));
//     cout << kthSmallest(root, k); // Output: 1
// }

//test kthSmallest 2
// int main(){
//     int arr[] = {6, 9, 2, 13, 0, 20};
//     int k = 2;
//     BSTNode* root = BSTNode::createBSTree(arr, arr + sizeof(arr) / sizeof(int));
//     cout << kthSmallest(root, k); // Output: 2
// }

//test singleChild
// int main(){
//     int arr[] = {1, 0, 4, 3, 2};
//     BSTNode* root = BSTNode::createBSTree(arr, arr + sizeof(arr) / sizeof(int));
//     cout << singleChild(root); // Output: 2
// }

//test subtreeWithRange
// int main(){
//     int arr[] = {5, 1, 9, 7, 10, 6, 8};
//     int lo = 7, hi = 10;
//     BSTNode* root = BSTNode::createBSTree(arr, arr + sizeof(arr) / sizeof(int));
//     root = subtreeWithRange(root, lo, hi);
//     BSTNode::printPreorder(root); // Expected output: 9 7 8 10
// }