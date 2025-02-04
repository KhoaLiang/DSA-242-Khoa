#include "../unit_test_KTLT_string.hpp"
bool UNIT_TEST_KTLT_string::countSubsequences02() {
    string name = "countSubsequences02";

    //! data ------------------------------------
    string S = "abcbd";
    string P = "abc";

    //! function call --------------------------
    long long result = countSubsequences(S, P);

    //! expect ----------------------------------
    long long expect = 1; // Số lượng subsequence "abc" trong "abcbd"

    //! output ----------------------------------
    stringstream output;
    output << result;

    //! result ----------------------------------
    return printResult(output.str(), to_string(expect), name);
}
