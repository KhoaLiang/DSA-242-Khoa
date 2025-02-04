#include "../unit_test_KTLT_string.hpp"
bool UNIT_TEST_KTLT_string::countSubsequences05() {
    string name = "countSubsequences05";

    //! data ------------------------------------
    string S = "abcabc";
    string P = "abc";

    //! function call --------------------------
    long long result = countSubsequences(S, P);

    //! expect ----------------------------------
    long long expect = 4; // Số lượng subsequence "abc" trong "abcabc"

    //! output ----------------------------------
    stringstream output;
    output << result;

    //! result ----------------------------------
    return printResult(output.str(), to_string(expect), name);
}