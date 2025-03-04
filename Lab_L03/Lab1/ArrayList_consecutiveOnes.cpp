#include <iostream>
#include <vector>
using namespace std;

// bool consecutiveOnes(vector<int>& nums) {
//     // If the array is empty, return true
//     if (nums.size() == 0) {
//         return true;
//     }

//     // Initialize a boolean variable to track if we are in a sequence of 1s
//     bool inSequenceOfOnes = false;
//     int checkposition = 0;
//     int firstOnePosition = 0;
//     for (int i = 0; i < nums.size(); i++)
//     {
//         if (nums[i] == 1)
//         {
//             firstOnePosition = i;
//             break;
//         }
//     }
    
//     // Iterate through the array
//     for (int j = 0; j < nums.size() - 1; j++){
//         if ((nums[j] == 1) && (nums[j] == nums[j+1]))
//         {
//             inSequenceOfOnes == true;
//         }
//         if ((inSequenceOfOnes == true) && (firstOnePosition != j))
//         {
//             return false;
//         }
//         checkposition = j+1;
//     }

//     // Check if there are any 1s left in the array after the sequence
//     for (int i = checkposition + 1; i < nums.size(); i++) {
//         if (nums[i] == 1) {
//             return false;
//         }
//     }

//     // If no 1s are found after the sequence, return true
//     return true;
// }
bool consecutiveOnes(vector<int>& nums) {
    if (nums.empty()) return true;  // If the array is empty, return true.

    bool foundOne = false;  // Track if we have started seeing 1s.
    bool ended = false;      // Track if we have encountered a non-1 after seeing 1s.

    for (int num : nums) {
        if (num == 1) {
            if (ended) return false;  // If we already saw a non-1, and now see 1 again -> return false.
            foundOne = true;          // Mark that we have started seeing 1s.
        } else {
            if (foundOne) ended = true;  // Mark that a non-1 has ended the sequence of 1s.
        }
    }
    
    return true;  // If we never broke the sequence, return true.
}

int main() {
    vector<int> nums1 {0, 1, 1, 1, 9, 8};
    cout << consecutiveOnes(nums1) << "\n"; // Expected output: 1 (true)

    vector<int> nums2 {0, 1, 0, 1, 1, 9, 8};
    cout << consecutiveOnes(nums2) << "\n"; // Expected output: 0 (false)

    vector<int> nums3 {1, 1, 1, 1, 1};
    cout << consecutiveOnes(nums3) << "\n"; // Expected output: 1 (true)

    vector<int> nums4 {0, 0, 0, 0, 0};
    cout << consecutiveOnes(nums4) << "\n"; // Expected output: 1 (true)

    vector<int> nums5 {};
    cout << consecutiveOnes(nums5) << "\n"; // Expected output: 1 (true)

    return 0;
}