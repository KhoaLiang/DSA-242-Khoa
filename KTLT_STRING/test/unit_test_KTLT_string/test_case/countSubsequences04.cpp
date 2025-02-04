#include "../unit_test_KTLT_string.hpp"
bool UNIT_TEST_KTLT_string::countSubsequences04() {
    string name = "countSubsequences04";

    //! data ------------------------------------
    string S = "ababc";
    string P = "abc";

    //! function call --------------------------
    long long result = countSubsequences(S, P);

    //! expect ----------------------------------
    long long expect = 3; // Số lượng subsequence "abc" trong "ababc"

    //! output ----------------------------------
    stringstream output;
    output << result;

    //! result ----------------------------------
    return printResult(output.str(), to_string(expect), name);
}