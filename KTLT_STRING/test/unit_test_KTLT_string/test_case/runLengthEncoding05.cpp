#include "../unit_test_KTLT_string.hpp"
bool UNIT_TEST_KTLT_string::runLengthEncoding05() {
    string name = "runLengthEncoding05";

    //! data ------------------------------------
    string input = "";
    
    //! function call --------------------------
    string result = runLengthEncoding(input);
    
    //! expect ----------------------------------
    string expect = ""; // Kỳ vọng kết quả là chuỗi rỗng

    //! output ----------------------------------
    stringstream output;
    output << result;

    //! result ----------------------------------
    return printResult(output.str(), expect, name);
}