#include <iostream> // For input/output
#include <cmath>    // For pow function
#include <string>   // For std::string and to_string
using namespace std;

long int to_int(string s) {
    long int base = 1;
    long int res = 0;
    for (int i = s.size() - 1; i >= 0; i--) {
        res += (s[i] - 48) * base;
        base *= 10;
    }
    return res;
}

int foldShift(long long key, int addressSize) {
    string s = "";
    string num = to_string(key);
    long int sum = 0;
    for (int i = 0; i < int(num.size());) {
        s = "";
        for (int j = 0; j < addressSize && i + j < int(num.size()); j++) {
            s += num[i + j];
        }
        i = i + addressSize;
        sum += to_int(s);
    }
    long int mod = pow(10, addressSize);
    return sum % mod;
}

int rotation(long long key, int addressSize) {
    string num = to_string(key);
    string s1 = num.substr(0, num.size() - 1);

    num = num[num.size() - 1] + s1;

    long int n = to_int(num);
    return foldShift(n, addressSize);
}

// Test function
int main() {
    // Test foldShift
    cout << "Testing foldShift:" << endl;
    cout << "foldShift(123456789, 3): " << foldShift(123456789, 3) << endl;
    cout << "foldShift(987654321, 4): " << foldShift(987654321, 4) << endl;

    // Test rotation
    cout << "\nTesting rotation:" << endl;
    cout << "rotation(123456789, 3): " << rotation(123456789, 3) << endl;
    cout << "rotation(987654321, 4): " << rotation(987654321, 4) << endl;

    return 0;
}