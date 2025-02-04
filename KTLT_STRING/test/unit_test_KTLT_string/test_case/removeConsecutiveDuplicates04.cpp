#include "../unit_test_KTLT_string.hpp"
bool UNIT_TEST_KTLT_string::removeConsecutiveDuplicates04() {
    string name = "removeConsecutiveDuplicates04";

    //! data ------------------------------------
    string input = "abcc";

    //! function call --------------------------
    string result = removeConsecutiveDuplicates(input);

    //! expect ----------------------------------
    string expect = "abc";

    //! output ----------------------------------
    stringstream output;
    output << result;

    //! result ----------------------------------
    return printResult(output.str(), expect, name);
}