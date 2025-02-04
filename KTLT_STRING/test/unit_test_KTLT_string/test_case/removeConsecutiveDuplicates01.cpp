#include "../unit_test_KTLT_string.hpp"
bool UNIT_TEST_KTLT_string::removeConsecutiveDuplicates01() {
    string name = "removeConsecutiveDuplicates01";

    //! data ------------------------------------
    string input = "aabbbaac";

    //! function call --------------------------
    string result = removeConsecutiveDuplicates(input);

    //! expect ----------------------------------
    string expect = "abac";

    //! output ----------------------------------
    stringstream output;
    output << result;

    //! result ----------------------------------
    return printResult(output.str(), expect, name);
}