#include "../unit_test_KTLT_array.hpp"

bool UNIT_TEST_KTLT_array::maxSubArray02() {
  string name = "maxSubArray02";

  //! data ------------------------------------
  int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  int size = 9;
  int result = maxSubArray(arr, size);

  //! expect ----------------------------------
  string expect = "6";

  //! output ----------------------------------
  stringstream output;
  output << result;

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}
