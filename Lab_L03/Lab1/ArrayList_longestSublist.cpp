#include <iostream>
#include <vector>
using namespace std;

int longestSublist(vector<string>& words) {
    // If the array is empty, return 0
    if (words.size() == 0) {
        return 0;
    }

    // Initialize variables to keep track of the longest sublist and the current sublist length
    int longest = 0;
    int currentLength = 1;

    // Iterate through the array
    for (int i = 1; i < words.size(); i++) {
        // If the current word shares the same first letter as the previous word
        if (words[i][0] == words[i - 1][0]) {
            // Increment the current sublist length
            currentLength++;
        } else {
            // Update the longest sublist length if the current sublist is longer
            if (currentLength > longest) {
                longest = currentLength;
            }
            // Reset the current sublist length
            currentLength = 1;
        }
    }

    // Check the last sublist
    if (currentLength > longest) {
        longest = currentLength;
    }

    // Return the length of the longest sublist
    return longest;
}

int main() {
    vector<string> words1 {"faction", "fight", "and", "are", "attitude"};
    cout << longestSublist(words1) << "\n"; // Expected output: 3

    vector<string> words2 {"apple", "banana", "cherry", "date"};
    cout << longestSublist(words2) << "\n"; // Expected output: 1

    vector<string> words3 {"apple", "apricot", "banana", "blueberry", "blackberry"};
    cout << longestSublist(words3) << "\n"; // Expected output: 3

    return 0;
}