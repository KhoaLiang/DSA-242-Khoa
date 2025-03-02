#include <iostream>
#include <algorithm>
using namespace std;

int buyCar(int* nums, int length, int k) {
    // Sort the array nums in ascending order
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length - 1; j++)
        {
            int temp = nums[j];
            if (nums[j] > nums[j + 1])
            {
                nums[j] = nums[j+1];
                nums[j+1] = temp;
            }
        }
    }
    // for (int i = 0; i < length; i++)
    // {
    //     cout << nums[i] << " ";
    // }
    // return 1;
    // Initialize a variable to keep track of the total cost
    // Initialize a variable to keep track of the number of cars bought
    int carBought = 0;
    int totalCost = 0;

    // Iterate through the sorted array
        // If the total cost plus the current car's price is less than or equal to k
            // Add the current car's price to the total cost
            // Increment the number of cars bought
        // Else
            // Break the loop as we cannot buy more cars

    // Return the number of cars bought
    for (int i = 0; i < length; i++)
    {
        if ((totalCost + nums[i]) <= k)
        {
            totalCost += nums[i];
            carBought += 1;
        }
        else break;
    }
    return carBought;
}

int main() {
    int nums[] = {90, 30, 40, 90, 20};
    int length = sizeof(nums) / sizeof(nums[0]);
    int k = 90;

    cout << buyCar(nums, length, k) << "\n"; // Expected output: 3

    return 0;
}