#include <iostream>
#include <vector>
using namespace std;

vector<int> updateArrayPerRange(vector<int>& nums, vector<vector<int>>& operations) {
    //Psudocode
    // Iterate through each operation in operations
    // for each operation in operations:
    //     // Extract L, R, and X from the operation
    //     L = operation[0]
    //     R = operation[1]
    //     X = operation[2]

    //     // Apply the operation to the range [L, R]
    //     for i from L to R:
    //         nums[i] = nums[i] + X

    // // Return the updated nums array
    // return nums

    // Iterate through each operation
    for (const auto& operation : operations) {
        int L = operation[0];
        int R = operation[1];
        int X = operation[2];

        // Apply the operation to the range [L, R]
        for (int i = L; i <= R; ++i) {
            nums[i] += X;
        }
    }

    // Return the updated array
    return nums;
}

void printVector(const vector<int>& vec) {
    cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << vec[i];
        if (i < vec.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

int main() {
    vector<int> nums {13, 0, 6, 9, 14, 16};
    vector<vector<int>> operations {{5, 5, 16}, {3, 4, 0}, {0, 2, 8}};
    printVector(updateArrayPerRange(nums, operations)); // Expected output: [21, 8, 14, 9, 14, 32]

    return 0;
}