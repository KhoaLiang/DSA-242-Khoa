#include "../unit_test_KTLT_array.hpp"

bool UNIT_TEST_KTLT_array::maxSubArray04() {
  string name = "maxSubArray04";

  //! data ------------------------------------
  int arr[] = {5, 4, -1, 7, 8};
  int size = 5;
  int result = maxSubArray(arr, size);

  //! expect ----------------------------------
  string expect = "23";

  //! output ----------------------------------
  stringstream output;
  output << result;

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}
