#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

// Function to print the elements of an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

//missingNumber exercise
int missingNumber(int nums[], int size) {
    int ReNums[size];
    for (int i = 0; i < size; i++)
    {
        ReNums[i] = nums[i];
    }
    bubbleSort(ReNums, size); // Sort the array in ascending order
    printArray(ReNums, size); // Print the sorted array
    for (int i = 0; i < size; i++)
    {
        if (ReNums[i] != i)
        {
            return i;
        }
        
    }
    
    return 1;
}
int singleNumber(int nums[], int size) {
    // result = 0
    // for i from 0 to size-1:
    //     result = result XOR nums[i]
    // return result
    int result = 0;
    for (int i = 0; i < size; i++)
    {
        result = result ^ nums[i];
    }
    
    return result;
}
int findSecondSmallest(int arr[], int size) {
    int ReNums[size];
    for (int i = 0; i < size; i++)
    {
        ReNums[i] = arr[i];
    }
    bubbleSort(ReNums, size); // Sort the array in ascending order
    printArray(ReNums, size); // Print the sorted array
    int Min = ReNums[0];
    int Min2 = ReNums[0];
    for (int i = 0; i < size; i++)
    {
        if (ReNums[i] > Min)
        {
            Min2 = ReNums[i];
            return Min2;
        }
    }
    return Min;
}
int maxSubArray(int nums[], int size) {
    int max_current = nums[0];
    int max_global = nums[0];

    for (int i = 1; i < size; i++) {
        max_current = max(nums[i], max_current + nums[i]);
        if (max_current > max_global) {
            max_global = max_current;
        }
    }

    return max_global;
}
int main() {
    // //missing number test
    // //! data ------------------------------------
    // int nums[] = {3, 0, 1};
    // int size = 3;
    // int result = missingNumber(nums, size);

    // //! expect ----------------------------------
    // string expect = "2";

    // //! output ----------------------------------
    // stringstream output;
    // output << result;

    // //single number test
    // //! data ------------------------------------
    // int nums[] = {4, 1, 2, 1, 2};
    // int size = 5;
    // int result = singleNumber(nums, size);

    // //! expect ----------------------------------
    // string expect = "4";

    // //! output ----------------------------------
    // stringstream output;
    // output << result;

    // //second smallest
    // //! data ------------------------------------
    // int arr[] = {4, 1, 3, 2};
    // int size = 4;
    // int result = findSecondSmallest(arr, size);

    // //! expect ----------------------------------
    // string expect = "2";

    // //! output ----------------------------------
    // stringstream output;
    // output << result;

    //maxSubArray
    //! data ------------------------------------
    int arr[] = {5, 4, -1, 7, 8};
    int size = 5;
    int result = maxSubArray(arr, size);

    //! expect ----------------------------------
    string expect = "-1";

    //! output ----------------------------------
    stringstream output;
    output << result;
    cout << "expect: " << expect << '\n';
    cout << "result: " << output.str() << '\n';
    return 0;

}