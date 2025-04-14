#include <iostream>
#include <queue>
#include <vector>
#include <utility>
using namespace std;

class BTNode {
public:
    int val;
    BTNode *left;
    BTNode *right;

    BTNode() {
        this->left = this->right = nullptr;
    }
    BTNode(int val) {
        this->val = val;
        this->left = this->right = nullptr;
    }
    BTNode(int val, BTNode*& left, BTNode*& right) {
        this->val = val;
        this->left = left;
        this->right = right;
    }

    static BTNode* createTree(int* parent, int* parentEnd, int* value) {
        int n = parentEnd - parent;
        vector<BTNode*> nodes(n, nullptr);

        BTNode* root = nullptr;
        for (int i = 0; i < n; ++i) {
            nodes[i] = new BTNode(value[i]);
        }

        for (int i = 0; i < n; ++i) {
            if (parent[i] == -1) {
                root = nodes[i];
            } else {
                BTNode* parentNode = nodes[parent[i]];
                if (!parentNode->left) {
                    parentNode->left = nodes[i];
                } else {
                    parentNode->right = nodes[i];
                }
            }
        }

        return root;
    }
};
// Helper function for DFS
void dfs(BTNode* node, int currentSum, int currentDepth, int& maxSum, int& maxDepth) {
    if (!node) return;

    currentSum += node->val;
    if (!node->left && !node->right) { // Leaf node
        if (currentDepth > maxDepth || (currentDepth == maxDepth && currentSum > maxSum)) {
            maxDepth = currentDepth;
            maxSum = currentSum;
        }
    }

    dfs(node->left, currentSum, currentDepth + 1, maxSum, maxDepth);
    dfs(node->right, currentSum, currentDepth + 1, maxSum, maxDepth);
}
int longestPathSum(BTNode* root) {
    if (!root) return 0;

    int maxSum = 0;
    int maxDepth = 0;

    // Start DFS from the root
    dfs(root, 0, 0, maxSum, maxDepth);
    return maxSum;
}
int lowestAncestor(BTNode* root, int a, int b) {
    if (!root) return -1; // Base case: if the root is null, return -1 (not found)

    // If the current node matches either a or b, return its value
    if (root->val == a || root->val == b) {
        return root->val;
    }

    // Recursively search for a and b in the left and right subtrees
    int left = lowestAncestor(root->left, a, b);
    int right = lowestAncestor(root->right, a, b);

    // If both left and right are not -1, the current node is the lowest ancestor
    if (left != -1 && right != -1) {
        return root->val;
    }

    // Otherwise, return the non-null result (either left or right)
    return (left != -1) ? left : right;
}

// Helper function for DFS
void dfs(BTNode* node, long long currentNumber, int& totalSum) {
    if (!node) return;
    const int MOD = 27022001; // Modulo value
    // Update the current number by appending the current node's value
    currentNumber = (currentNumber * 10 + node->val) % MOD;

    // If it's a leaf node, add the current number to the total sum
    if (!node->left && !node->right) {
        totalSum = (totalSum + currentNumber) % MOD;
        return;
    }

    // Recur for left and right subtrees
    dfs(node->left, currentNumber, totalSum);
    dfs(node->right, currentNumber, totalSum);
}
int sumDigitPath(BTNode* root) {
    int totalSum = 0;
    // Start DFS from the root
    dfs(root, 0, totalSum);
    return totalSum;
}
// Function to count nodes in the range [lo, hi]
int rangeCount(BTNode* root, int lo, int hi) {
    if (!root) return 0;

    // If the current node's value is within the range, count it
    if (root->val >= lo && root->val <= hi) {
        return 1 + rangeCount(root->left, lo, hi) + rangeCount(root->right, lo, hi);
    }

    // If the current node's value is less than the range, skip the left subtree
    if (root->val < lo) {
        return rangeCount(root->right, lo, hi);
    }

    // If the current node's value is greater than the range, skip the right subtree
    return rangeCount(root->left, lo, hi);
}
//test longestPathSum
// int main(){
//     int arr[] = {-1, 0, 0, 2, 2, 3, 3, 5};
//     int value[] = {1, 5, 4, 7, 12, 4, 8, 2};
//     BTNode* root = BTNode::createTree(arr, arr + sizeof(arr)/sizeof(int), value);
//     cout << longestPathSum(root); // Output: 18
// }

//test lowestAncestor 1
// int main(){
//     int arr[] = {-1, 0, 0, 2, 2, 3, 3};
//     int value[] = {0, 1, 2, 3, 4, 5, 6};
//     BTNode* root = BTNode::createTree(arr, arr + sizeof(arr) / sizeof(int), value);
//     cout << lowestAncestor(root, 4, 5); // Output: 2
// }

//test lowestAncestor 2
// int main(){
//     int arr[] = {-1, 0, 1, 1, 0, 4, 4, 2, 5, 6};
//     int value[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
//     BTNode* root = BTNode::createTree(arr, arr + sizeof(arr) / sizeof(int), value);
//     cout << lowestAncestor(root, 4, 9); // Output: 4
// }

//test sumDigitPath
int main(){
    int arr[] = {-1, 0, 0, 2, 2};
    int value[] = {3, 5, 2, 1, 4};
    BTNode* root = BTNode::createTree(arr, arr + sizeof(arr)/sizeof(int), value);
    cout << sumDigitPath(root); // Output: 680
}