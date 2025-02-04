#include "../unit_test_KTLT_string.hpp"
bool UNIT_TEST_KTLT_string::runLengthEncoding03() {
    string name = "runLengthEncoding03";

    //! data ------------------------------------
    string input = "abcd";
    
    //! function call --------------------------
    string result = runLengthEncoding(input);
    
    //! expect ----------------------------------
    string expect = "a1b1c1d1"; // Kỳ vọng kết quả là "a1b1c1d1"

    //! output ----------------------------------
    stringstream output;
    output << result;

    //! result ----------------------------------
    return printResult(output.str(), expect, name);
}