#include "../unit_test_KTLT_string.hpp"
bool UNIT_TEST_KTLT_string::sumOfIntegersInString02() {
    string name = "sumOfIntegersInString02";

    //! data ------------------------------------
    string input = "abc123xyz45";
    
    //! function call --------------------------
    int result = sumOfIntegersInString(input);
    
    //! expect ----------------------------------
    int expect = 168; // Các số tách được là 123 và 45, tổng = 123 + 45 = 168

    //! output ----------------------------------
    stringstream output;
    output << result;

    //! result ----------------------------------
    return printResult(output.str(), to_string(expect), name);
}