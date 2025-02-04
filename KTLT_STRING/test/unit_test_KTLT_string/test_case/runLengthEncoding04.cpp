#include "../unit_test_KTLT_string.hpp"
bool UNIT_TEST_KTLT_string::runLengthEncoding04() {
    string name = "runLengthEncoding04";

    //! data ------------------------------------
    string input = "zzzzzz";
    
    //! function call --------------------------
    string result = runLengthEncoding(input);
    
    //! expect ----------------------------------
    string expect = "z6"; // Kỳ vọng kết quả là "z6"

    //! output ----------------------------------
    stringstream output;
    output << result;

    //! result ----------------------------------
    return printResult(output.str(), expect, name);
}
