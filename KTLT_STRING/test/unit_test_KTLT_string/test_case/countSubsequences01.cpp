#include "../unit_test_KTLT_string.hpp"

bool UNIT_TEST_KTLT_string::countSubsequences01() {
    string name = "countSubsequences01";

    //! data ------------------------------------
    string S = "abcbc";
    string P = "abc";

    //! function call --------------------------
    long long result = countSubsequences(S, P);

    //! expect ----------------------------------
    long long expect = 3; // Số lượng subsequence "abc" trong "abcbx"

    //! output ----------------------------------
    stringstream output;
    output << result;

    //! result ----------------------------------
    return printResult(output.str(), to_string(expect), name);
}