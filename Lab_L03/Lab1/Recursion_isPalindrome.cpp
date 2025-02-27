#include <iostream>
#include <string>
using namespace std;

bool isPalindromeHelper(string str, int start, int end) {
    // If start is greater than or equal to end:
    if (start >= end) {
        return true;
    }
    // If str[start] is not equal to str[end]:
    if (str[start] != str[end]) {
        return false;
    }
    // Call isPalindromeHelper with start + 1 and end - 1
    return isPalindromeHelper(str, start + 1, end - 1);
}

string removeSpaces(string str, string::size_type index = 0) {
    // Base case: if index reaches the end of the string
    if (index == str.length()) {
        return "";
    }
    // Recursive case: if the current character is not a space, include it in the result
    if (str[index] != ' ') {
        return str[index] + removeSpaces(str, index + 1);
    }
    // Recursive case: if the current character is a space, skip it
    return removeSpaces(str, index + 1);
}

bool isPalindrome(string str) {
    // Remove spaces from the string using the recursive function
    string cleanedStr = removeSpaces(str);
    // Call isPalindromeHelper with the cleaned string, start index 0, and end index cleanedStr.length() - 1
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