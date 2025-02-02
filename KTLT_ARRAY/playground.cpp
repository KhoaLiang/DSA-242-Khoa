#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

#define MAX 100
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
int firstPosition(int arr[], int size, int valueToBeFind){
    for (int i = 0; i < size; i++)
    {
        if (valueToBeFind == arr[i])
        {
            return i;
        }
    }
    return 0;
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
// Function to perform DFS and calculate the area of an island
int dfs(int grid[][MAX], int x, int y, int n, int m, vector<vector<bool>>& visited) {
    // Check for out of bounds or if the cell is water or already visited
    if (x < 0 || x >= n || y < 0 || y >= m || grid[x][y] == 0 || visited[x][y]) {
        return 0;
    }

    // Mark the cell as visited
    visited[x][y] = true;

    // Initialize area
    int area = 1;

    // Explore all four directions (up, down, left, right)
    area += dfs(grid, x + 1, y, n, m, visited);
    area += dfs(grid, x - 1, y, n, m, visited);
    area += dfs(grid, x, y + 1, n, m, visited);
    area += dfs(grid, x, y - 1, n, m, visited);

    return area;
}

int maxAreaOfIsland(int grid[][MAX], int n, int m) {
    // Initialize visited array
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    int max_area = 0;

    // Iterate through each cell in the grid
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // If the cell is land and not visited, perform DFS
            if (grid[i][j] == 1 && !visited[i][j]) {
                int area = dfs(grid, i, j, n, m, visited);
                max_area = max(max_area, area);
            }
        }
    }

    return max_area;
}
int numberOfClosedIslands(int grid[][MAX], int n, int m) {
    return 1;
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

    // //maxSubArray
    // //! data ------------------------------------
    // int arr[] = {5, 4, -1, 7, 8};
    // int size = 5;
    // int result = maxSubArray(arr, size);

    // //! expect ----------------------------------
    // string expect = "-1";

    // //! output ----------------------------------
    // stringstream output;
    // output << result;
    // //mountainArray bool function
    // //! data ------------------------------------
    // int arr[] = {0, 1, 2, 3, 4, 9, 8, 7, 6, 5};
    // int size = 10;
    // int result = isMountainArray(arr, size);

    // //! expect ----------------------------------
    // string expect = "1";

    // //! output ----------------------------------
    // stringstream output;
    // output << result;
    // //find max sum of sub array
    // //! data ------------------------------------
    // int arr[] = {1, 2, 3, 4, 5, 6};
    // int size = 6;
    // int k = 3;
    // int result = findMaxSumSubarray(arr, size, k);

    // //! expect ----------------------------------
    // string expect = "15";

    // //! output ----------------------------------
    // stringstream output;
    // output << result;
    //max area of islands
    // //! data ------------------------------------
    // int grid[MAX][MAX] = {
    //     {0, 1, 0, 0}, 
    //     {1, 1, 1, 0}, 
    //     {0, 0, 0, 0}, 
    //     {1, 0, 0, 0}
    // };
    // int n = 4, m = 4;

    // int result = maxAreaOfIsland(grid, n, m);

    // //! expect ----------------------------------
    // string expect = "4";

    // //! output ----------------------------------
    // stringstream output;
    // output << result;

    //number of closed island
    //! data ------------------------------------
    int grid[MAX][MAX] = {
        {1, 1, 1, 1, 0},
        {1, 0, 0, 1, 0},
        {1, 1, 1, 1, 0},
        {0, 0, 0, 0, 0}};
    int n = 4, m = 5;

    int result = numberOfClosedIslands(grid, n, m);

    //! expect ----------------------------------
    string expect = "0";

    //! output ----------------------------------
    stringstream output;
    output << result;
    cout << "expect: " << expect << '\n';
    cout << "result: " << output.str() << '\n';
    return 0;

}