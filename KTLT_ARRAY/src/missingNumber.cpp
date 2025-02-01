#include "KTLT_array.h"
//
// Function to print the elements of an array
// void printArray(int arr[], int size) {
//     for (int i = 0; i < size; i++) {
//         cout << arr[i] << " ";
//     }
//     cout << endl;
// }
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
    //printArray(ReNums, size); // Print the sorted array
    for (int i = 0; i < size; i++)
    {
        if (ReNums[i] != i)
        {
            return i;
        }
        
    }
    
    // If all numbers from 0 to size-1 are present, the missing number is size
    return size;
}