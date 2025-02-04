#include "../unit_test_KTLT_string.hpp"
bool UNIT_TEST_KTLT_string::sumOfIntegersInString01() {
    string name = "sumOfIntegersInString01";

    //! data ------------------------------------
    string input = "ab12cd3";
    
    //! function call --------------------------
    int result = sumOfIntegersInString(input);
    
    //! expect ----------------------------------
    int expect = 15; // Các số tách được là 12 và 3, tổng = 12 + 3 = 15

    //! output ----------------------------------
    stringstream output;
    output << result;

    //! result ----------------------------------
    return printResult(output.str(), to_string(expect), name);
}
