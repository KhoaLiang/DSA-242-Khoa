#include "../unit_test_KTLT_string.hpp"

bool UNIT_TEST_KTLT_string::removeConsecutiveDuplicates02() {
    string name = "removeConsecutiveDuplicates02";

    //! data ------------------------------------
    string input = "aaaa";

    //! function call --------------------------
    string result = removeConsecutiveDuplicates(input);

    //! expect ----------------------------------
    string expect = "a";

    //! output ----------------------------------
    stringstream output;
    output << result;

    //! result ----------------------------------
    return printResult(output.str(), expect, name);
}