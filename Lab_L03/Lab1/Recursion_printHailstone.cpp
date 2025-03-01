void printHailstone(int number) {
    // Print the current number
    cout << number;
    
    // Base case: if the number is 1, return
    if (number == 1) {
        return;
    }
    
    // Recursive case: determine the next number in the sequence
    if (number % 2 == 0) {
        cout << " ";
        printHailstone(number / 2);
    } else {
        cout << " ";
        printHailstone(number * 3 + 1);
    }
}