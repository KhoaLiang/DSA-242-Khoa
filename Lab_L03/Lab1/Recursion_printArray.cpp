#include <iostream>
using namespace std;




void printArrayHelper(int current, int n) {
    // If current > n:
    //     Return
    // Condition: If current is greater than n.
    // Action: The function returns without doing anything further.
    // Purpose: This stops the recursion when current exceeds n, ensuring that the function does not continue indefinitely.

    if (current > n)
    {
        return;
    }
    
    if (current != 0)
    {
        cout << ", ";
    }
    cout << current;
    // If current is not 0:
    //     Print ", "
    // Print current
    printArrayHelper(current + 1, n);
    // Call printArrayHelper(current + 1, n)
}

void printArray(int n) {
    // Call printArrayHelper(0, n)
    printArrayHelper(0, n);
}
int main() {
    // Test cases
    printArray(5);  // Expected output: 0, 1, 2, 3, 4, 5
    cout << endl;
    printArray(10); // Expected output: 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
    cout << endl;

    return 0;
}