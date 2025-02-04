#include "../unit_test_KTLT_string.hpp"
bool UNIT_TEST_KTLT_string::encodeASCII04() {
    string name = "encodeASCII04";

    //! data ------------------------------------
    string input = "123!@#";
    int k = 4;

    //! function call --------------------------
    string result = encodeASCII(input, k);

    //! expect ----------------------------------
    string expect = "123!@#"; // Ký tự không thuộc alphabet giữ nguyên

    //! output ----------------------------------
    stringstream output;
    output << result;

    //! result ----------------------------------
    return printResult(output.str(), expect, name);
}
