#include <iostream> // For input/output
using namespace std;

// Mid-Square Method
long int midSquare(long int seed) {
    seed = seed * seed;
    seed /= 100;
    return seed % 10000;
}

// Modulo Division Method
long int moduloDivision(long int seed, long int mod) {
    return seed % mod;
}

// Digit Extraction Method
long int digitExtraction(long int seed, int* extractDigits, int size) {
    int tmp[1000];
    for (int i = 0; i < 1000; i++) tmp[i] = -1;
    int i = 0;
    while (seed > 0) {
        tmp[i] = seed % 10;
        seed /= 10;
        i++;
    }
    long int result = 0;
    int j = 0;
    while (size) {
        result = result * 10 + tmp[i - extractDigits[j] - 1];
        j += 1;
        size--;
    }
    return result;
}

// Test function
int main() {
    // Test midSquare
    cout << "Testing midSquare:" << endl;
    cout << "midSquare(1234): " << midSquare(1234) << endl; // Expected: 5227
    cout << "midSquare(5678): " << midSquare(5678) << endl; // Expected: 2284

    // Test moduloDivision
    cout << "\nTesting moduloDivision:" << endl;
    cout << "moduloDivision(1234, 100): " << moduloDivision(1234, 100) << endl; // Expected: 34
    cout << "moduloDivision(5678, 1000): " << moduloDivision(5678, 1000) << endl; // Expected: 678

    // Test digitExtraction
    cout << "\nTesting digitExtraction:" << endl;
    int extractDigits1[] = {1, 3}; // Extract 2nd and 4th digits from the right
    cout << "digitExtraction(123456, {1, 3}, 2): " 
         << digitExtraction(123456, extractDigits1, 2) << endl; // Expected: 52

    int extractDigits2[] = {0, 2, 4}; // Extract 1st, 3rd, and 5th digits from the right
    cout << "digitExtraction(987654, {0, 2, 4}, 3): " 
         << digitExtraction(987654, extractDigits2, 3) << endl; // Expected: 975

    return 0;
}