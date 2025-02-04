#include "../unit_test_KTLT_string.hpp"
bool UNIT_TEST_KTLT_string::sumOfIntegersInString05() {
    string name = "sumOfIntegersInString05";

    //! data ------------------------------------
    string input = "1234";
    
    //! function call --------------------------
    int result = sumOfIntegersInString(input);
    
    //! expect ----------------------------------
    int expect = 1234; // Chỉ có một số 1234 trong chuỗi, tổng = 1234

    //! output ----------------------------------
    stringstream output;
    output << result;

    //! result ----------------------------------
    return printResult(output.str(), to_string(expect), name);
}