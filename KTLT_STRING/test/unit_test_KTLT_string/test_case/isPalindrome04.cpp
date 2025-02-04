#include "../unit_test_KTLT_string.hpp"

bool UNIT_TEST_KTLT_string::isPalindrome04() { 
    string name = "isPalindrome04";

    //! data ------------------------------------
    string input = "1";

    //! function call --------------------------
    bool result = isPalindrome(input);

    //! expect ----------------------------------
    string expect = "1"; // 1 = true, 0 = false

    //! output ----------------------------------
    stringstream output;
    output << result;

    //! remove data -----------------------------

    //! result ----------------------------------
    return printResult(output.str(), expect, name);
}
