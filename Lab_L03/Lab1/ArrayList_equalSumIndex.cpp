#include <iostream>
#include <vector>
using namespace std;

int equalSumIndex(vector<int>& nums) {
    // Calculate the total sum of the array
    int totalSum = 0;
    for (int num : nums) {
        totalSum += num;
    }

    // Initialize left sum to 0
    int leftSum = 0;

    // Iterate through the array
    for (int i = 0; i < nums.size(); i++) {
        // Calculate the right sum by subtracting the left sum and the current element from the total sum
        int rightSum = totalSum - leftSum - nums[i];

        // If the left sum is equal to the right sum, return the current index
        if (leftSum == rightSum) {
            return i;
        }

        // Update the left sum by adding the current element
        leftSum += nums[i];
    }

    // If no such index exists, return -1
    return -1;
}

int main() {
    vector<int> nums {3, 5, 2, 7, 6, 4};
    cout << equalSumIndex(nums) << "\n"; // Expected output: 3

    vector<int> nums2 {1, 2, 3, 4, 6};
    cout << equalSumIndex(nums2) << "\n"; // Expected output: -1

    vector<int> nums3 {1, 2, 3, 3};
    cout << equalSumIndex(nums3) << "\n"; // Expected output: 2

    return 0;
}