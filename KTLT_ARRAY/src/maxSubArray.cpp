#include "KTLT_array.h"
int returnMax(int number1, int number2){
    if (number2 > number1)
    {
        return number2;
    }
    return number1;
}
int maxSubArray(int nums[], int size) {
    int max_current = nums[0];
    int max_global = nums[0];

    for (int i = 1; i < size; i++) {
        max_current = returnMax(nums[i], max_current + nums[i]);
        if (max_current > max_global) {
            max_global = max_current;
        }
    }

    return max_global;
}