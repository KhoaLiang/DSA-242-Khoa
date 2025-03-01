int recursivePow(int base, int exp) {
    // Base case: if exponent is 0, return 1
    if (exp == 0) {
        return 1;
    }
    // Recursive case: multiply base by the result of recursivePow with exponent - 1
    return base * recursivePow(base, exp - 1);
}

int myArrayToIntHelper(char* str, int n, int index) {
    // Base case: if index reaches the length of the string, return 0
    if (index == n) {
        return 0;
    }
    // Recursive case: convert the current character to its integer value and add it to the result of the recursive call
    return (str[index] - '0') * recursivePow(10, n - index - 1) + myArrayToIntHelper(str, n, index + 1);
}

int myArrayToInt(char* str, int n) {
    return myArrayToIntHelper(str, n, 0);
}