#include "KTLT_array.h"

int findMaxSumSubarray(int arr[], int size, int k) {
    // if size < k:
    //     return -1
    if(size < k || size == 0) return 0;
    // max_sum = sum of first k elements
    // window_sum = max_sum
    int max_sum = 0;
    int window_sum = 0;
    for (int i = 0; i < k; i++)
    {
        max_sum += arr[i];
    }
    window_sum = max_sum;
    // for i from k to size - 1:
    //     window_sum = window_sum + arr[i] - arr[i - k]
    //     if window_sum > max_sum:
    //         max_sum = window_sum

    // return max_sum
    for (int i = k; i < size; i++)
    {
        window_sum = window_sum + arr[i] - arr[i - k];
        if (window_sum > max_sum)
        {
            max_sum = window_sum;
        }
    }
    return max_sum;
}