#include "KTLT_array.h"

void bubbleSort1(int arr[], int size) {
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

int findSecondSmallest(int arr[], int size) {
    int ReNums[size];
    for (int i = 0; i < size; i++)
    {
        ReNums[i] = arr[i];
    }
    bubbleSort1(ReNums, size); // Sort the array in ascending order
    //printArray(ReNums, size); // Print the sorted array
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
    return -1;
}