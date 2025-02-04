#include "../unit_test_KTLT_string.hpp"
bool UNIT_TEST_KTLT_string::runLengthEncoding01() {
    string name = "runLengthEncoding01";

    //! data ------------------------------------
    string input = "aabbbaac";
    
    //! function call --------------------------
    string result = runLengthEncoding(input);
    
    //! expect ----------------------------------
    string expect = "a2b3a2c1"; // Kỳ vọng kết quả là "a2b3a2c1"

    //! output ----------------------------------
    stringstream output;
    output << result;

    //! result ----------------------------------
    return printResult(output.str(), expect, name);
}