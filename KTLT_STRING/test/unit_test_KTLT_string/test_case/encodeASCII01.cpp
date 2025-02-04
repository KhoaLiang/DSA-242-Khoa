#include "../unit_test_KTLT_string.hpp"
bool UNIT_TEST_KTLT_string::encodeASCII01() {
    string name = "encodeASCII01";

    //! data ------------------------------------
    string input = "hello";
    int k = 3;

    //! function call --------------------------
    string result = encodeASCII(input, k);

    //! expect ----------------------------------
    string expect = "khoor"; // Kỳ vọng sau khi dịch 3 bước

    //! output ----------------------------------
    stringstream output;
    output << result;

    //! result ----------------------------------
    return printResult(output.str(), expect, name);
}