#include "../unit_test_KTLT_string.hpp"
bool UNIT_TEST_KTLT_string::sumOfIntegersInString04() {
    string name = "sumOfIntegersInString04";

    //! data ------------------------------------
    string input = "a1bcd";
    
    //! function call --------------------------
    int result = sumOfIntegersInString(input);
    
    //! expect ----------------------------------
    int expect = 1; // Các số tách được là 1, 2, 3, 4, tổng = 1 + 2 + 3 + 4 = 10

    //! output ----------------------------------
    stringstream output;
    output << result;

    //! result ----------------------------------
    return printResult(output.str(), to_string(expect), name);
}
