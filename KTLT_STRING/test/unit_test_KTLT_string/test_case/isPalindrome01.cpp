#include "../unit_test_KTLT_string.hpp"

bool UNIT_TEST_KTLT_string::isPalindrome01() { 
    string name = "isPalindrome01";

    //! data ------------------------------------
    string input = "A man, a plan, a canal: Panama1";

    //! function call --------------------------
    bool result = isPalindrome(input);

    //! expect ----------------------------------
    string expect = "0"; // 1 = true, 0 = false

    //! output ----------------------------------
    stringstream output;
    output << result;

    //! remove data -----------------------------

    //! result ----------------------------------
    return printResult(output.str(), expect, name);
}
