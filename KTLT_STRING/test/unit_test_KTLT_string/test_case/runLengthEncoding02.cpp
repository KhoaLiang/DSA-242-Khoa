#include "../unit_test_KTLT_string.hpp"
bool UNIT_TEST_KTLT_string::runLengthEncoding02() {
    string name = "runLengthEncoding02";

    //! data ------------------------------------
    string input = "aaaabbbcc";
    
    //! function call --------------------------
    string result = runLengthEncoding(input);
    
    //! expect ----------------------------------
    string expect = "a4b3c2"; // Kỳ vọng kết quả là "a4b3c2"

    //! output ----------------------------------
    stringstream output;
    output << result;

    //! result ----------------------------------
    return printResult(output.str(), expect, name);
}