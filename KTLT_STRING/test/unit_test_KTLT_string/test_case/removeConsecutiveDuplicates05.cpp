#include "../unit_test_KTLT_string.hpp"
bool UNIT_TEST_KTLT_string::removeConsecutiveDuplicates05() {
    string name = "removeConsecutiveDuplicates05";

    //! data ------------------------------------
    string input = "";

    //! function call --------------------------
    string result = removeConsecutiveDuplicates(input);

    //! expect ----------------------------------
    string expect = "";

    //! output ----------------------------------
    stringstream output;
    output << result;

    //! result ----------------------------------
    return printResult(output.str(), expect, name);
}