#include <iostream>
using namespace std;


void printPatternHelper(int cur, int n, bool increasing) {
    // Print cur
    // If cur is less than or equal to 0:
    //     Set increasing to true
    // If increasing is true and cur is equal to n:
    //     Return
    // If increasing is true:
    //     Call printPatternHelper(cur + 5, n, true)
    // Else:
    //     Call printPatternHelper(cur - 5, n, false)
    cout << cur;
    if (cur <= 0)
    {
        increasing = true;
    }
    if (increasing == true && cur == n){
        return;
    }
    cout << " ";
    if (increasing == true)
    {
        printPatternHelper(cur + 5, n, true);
    }
    else printPatternHelper(cur - 5, n, false);
}

void printPattern(int n) {
    // Call printPatternHelper(n, n, false)
    printPatternHelper(n, n, false);
}

int main() {
    // Test cases
    printPattern(16);  // Expected output: 16, 11, 6, 1, -4, 1, 6, 11, 16
    cout << endl;
    printPattern(10);  // Expected output: 10, 5, 0, 5, 10
    cout << endl;
    printPattern(14);  // Expected output: 14, 9, 4, -1, 4, 9, 14
    cout << endl;

    return 0;
}