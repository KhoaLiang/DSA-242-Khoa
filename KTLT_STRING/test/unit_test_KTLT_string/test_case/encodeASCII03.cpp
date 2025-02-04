#include "../unit_test_KTLT_string.hpp"

bool UNIT_TEST_KTLT_string::encodeASCII03() {
    string name = "encodeASCII03";

    //! data ------------------------------------
    string input = "abcXYZ";
    int k = 2;

    //! function call --------------------------
    string result = encodeASCII(input, k);

    //! expect ----------------------------------
    string expect = "cdeZAB"; // Kỳ vọng sau khi dịch 2 bước

    //! output ----------------------------------
    stringstream output;
    output << result;

    //! result ----------------------------------
    return printResult(output.str(), expect, name);
}