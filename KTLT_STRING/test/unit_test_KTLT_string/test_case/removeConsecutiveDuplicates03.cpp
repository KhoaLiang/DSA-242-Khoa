#include "../unit_test_KTLT_string.hpp"
bool UNIT_TEST_KTLT_string::removeConsecutiveDuplicates03() {
    string name = "removeConsecutiveDuplicates03";

    //! data ------------------------------------
    string input = "ab";

    //! function call --------------------------
    string result = removeConsecutiveDuplicates(input);

    //! expect ----------------------------------
    string expect = "ab";

    //! output ----------------------------------
    stringstream output;
    output << result;

    //! result ----------------------------------
    return printResult(output.str(), expect, name);
}