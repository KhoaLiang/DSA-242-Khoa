#include "../unit_test_KTLT_string.hpp"
bool UNIT_TEST_KTLT_string::countSubsequences03() {
    string name = "countSubsequences03";

    //! data ------------------------------------
    string S = "aaaaa";
    string P = "aa";

    //! function call --------------------------
    long long result = countSubsequences(S, P);

    //! expect ----------------------------------
    long long expect = 10; // Số lượng subsequence "aa" trong "aaaaa"

    //! output ----------------------------------
    stringstream output;
    output << result;

    //! result ----------------------------------
    return printResult(output.str(), to_string(expect), name);
}
