#include "../unit_test_KTLT_string.hpp"
bool UNIT_TEST_KTLT_string::sumOfIntegersInString03() {
    string name = "sumOfIntegersInString03";

    //! data ------------------------------------
    string input = "a1b2c3d4";
    
    //! function call --------------------------
    int result = sumOfIntegersInString(input);
    
    //! expect ----------------------------------
    int expect = 10; // Các số tách được là 1, 2, 3, 4, tổng = 1 + 2 + 3 + 4 = 10

    //! output ----------------------------------
    stringstream output;
    output << result;

    //! result ----------------------------------
    return printResult(output.str(), to_string(expect), name);
}
