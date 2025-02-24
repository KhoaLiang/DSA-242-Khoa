#include <iostream>
using namespace std;

int findMax(int* arr, int length) {
    // If length is 1:
    //     Return the first element of the array
    // Call findMax recursively with the array and length - 1
    // Compare the result of the recursive call with the last element of the array
    // Return the maximum of the two values
    if (length == 1)
    {
        return arr[0];
    }
    // Call findMax recursively with the array and length - 1
    int maxOfRest = findMax(arr, length - 1);
    
    // Compare the result of the recursive call with the last element of the array
    // Return the maximum of the two values
    if (arr[length - 1] > maxOfRest) {
        return arr[length - 1];
    } else {
        return maxOfRest;
    }
    
}

int main() {
    int arr[] = {10, 5, 7, 9, 15, 6, 11, 8, 12, 2};
    cout << findMax(arr, 10) << endl;  // Expected output: 15

    return 0;
}