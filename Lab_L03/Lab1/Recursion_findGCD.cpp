int findGCD(int a, int b) {
    // Base case: if b is 0, return a
    if (b == 0) {
        return a;
    }
    // Recursive case: call findGCD with b and a % b
    return findGCD(b, a % b);
}