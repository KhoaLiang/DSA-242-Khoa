#include "KTLT_array.h"

int firstPosition(int arr[], int size, int valueToBeFind){
    for (int i = 0; i < size; i++)
    {
        if (valueToBeFind == arr[i])
        {
            return i;
        }
    }
    return -1;
}
bool isMountainArray(int arr[], int size) {
    if(size < 3) return false;
    int max = arr[0];
    //loop to find the peak of the array(max)
    for (int i = 0; i < size; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
    }
    if (max == arr[0] || max == arr[size - 1]) {
        return false;
    }

    int peakOfMountain = firstPosition(arr, size, max);

    // Check if the values before the peak are strictly increasing
    for (int i = 0; i < peakOfMountain; i++) {
        if (arr[i] >= arr[i + 1]) {
            return false;
        }
    }

    // Check if the values after the peak are strictly decreasing
    for (int i = peakOfMountain; i < size - 1; i++) {
        if (arr[i] <= arr[i + 1]) {
            return false;
        }
    }

    return true; 
}