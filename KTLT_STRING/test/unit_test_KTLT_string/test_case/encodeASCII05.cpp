
#include "../unit_test_KTLT_string.hpp"
bool UNIT_TEST_KTLT_string::encodeASCII05() {
    string name = "encodeASCII05";

    //! data ------------------------------------
    string input = "Zebra123";
    int k = 1;

    //! function call --------------------------
    string result = encodeASCII(input, k);

    //! expect ----------------------------------
    string expect = "Afcsb123"; // Kỳ vọng sau khi dịch 1 bước

    //! output ----------------------------------
    stringstream output;
    output << result;

    //! result ----------------------------------
    return printResult(output.str(), expect, name);
}