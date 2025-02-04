#include "../unit_test_KTLT_string.hpp"
bool UNIT_TEST_KTLT_string::encodeASCII02() {
    string name = "encodeASCII02";

    //! data ------------------------------------
    string input = "HELLO";
    int k = 5;

    //! function call --------------------------
    string result = encodeASCII(input, k);

    //! expect ----------------------------------
    string expect = "MJQQT"; // Kỳ vọng sau khi dịch 5 bước

    //! output ----------------------------------
    stringstream output;
    output << result;

    //! result ----------------------------------
    return printResult(output.str(), expect, name);
}
