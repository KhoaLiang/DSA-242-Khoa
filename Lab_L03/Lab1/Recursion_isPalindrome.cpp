#include <iostream>
#include <string>
using namespace std;

bool isPalindromeHelper(string str, int start, int end) {
    // If start is greater than or equal to end:
    //     Return true
    // If str[start] is not equal to str[end]:
    //     Return false
    // Call isPalindromeHelper with start + 1 and end - 1
    if (start >= end)
    {
        return true;
    }
    if (str[start] != str[end])
    {
        return false;
    }
    return isPalindromeHelper(str, start + 1, end - 1);
}

bool isPalindrome(string str) {
    // Remove spaces from the string
    string cleanedStr;
    for (char c : str) {
        if (c != ' ') {
            cleanedStr += c;
        }
    }
    // Call isPalindromeHelper with the cleaned string, start index 0, and end index str.length() - 1
    return isPalindromeHelper(cleanedStr, 0, cleanedStr.length() - 1);
}
int main() {
    // Test cases
    cout << isPalindrome("mom") << endl;             // Expected output: 1 (true)
    cout << isPalindrome("do geese see god") << endl; // Expected output: 1 (true)
    cout << isPalindrome("hello") << endl;           // Expected output: 0 (false)
    cout << isPalindrome("racecar") << endl;         // Expected output: 1 (true)
    cout << isPalindrome("A man a plan a canal Panama") << endl; // Expected output: 1 (true)

    return 0;
}