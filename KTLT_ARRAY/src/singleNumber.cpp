#include "KTLT_array.h"

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
