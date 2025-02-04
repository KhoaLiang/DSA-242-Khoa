#include "../unit_test_KTLT_string.hpp"

bool UNIT_TEST_KTLT_string::isPalindrome05() { 
    string name = "isPalindrome05";

    //! data ------------------------------------
    string input = "111122221111";

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
