#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
using namespace std;

string minDiffPairs(int* arr, int n) {
    if (n < 2) return ""; // If there are fewer than 2 elements, no pairs can be formed.

    // Sort the array to find pairs with the smallest absolute difference
    sort(arr, arr + n);

    // Define a large value for the initial minimum difference
    int minDiff = 1e9;

    // Find the smallest absolute difference
    for (int i = 1; i < n; i++) {
        minDiff = min(minDiff, arr[i] - arr[i - 1]);
    }

    // Collect all pairs with the smallest absolute difference
    pair<int, int> pairs[10000]; // Static array to store pairs
    int pairCount = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] - arr[i - 1] == minDiff) {
            pairs[pairCount++] = {arr[i - 1], arr[i]};
        }
    }

    // Convert the pairs to a string for output
    stringstream result;
    for (int i = 0; i < pairCount; i++) {
        result << "(" << pairs[i].first << ", " << pairs[i].second << ")";
        if (i != pairCount - 1) result << ", ";
    }

    return result.str();
}

// Main function for testing
int main() {
    int arr1[] = {10, 5, 7, 9, 15, 6, 11, 8, 12, 2};
    cout << minDiffPairs(arr1, 10) << endl;

    int arr2[] = {10};
    cout << minDiffPairs(arr2, 1) << endl;

    int arr3[] = {10, -1, -150, 200};
    cout << minDiffPairs(arr3, 4) << endl;

    return 0;
}