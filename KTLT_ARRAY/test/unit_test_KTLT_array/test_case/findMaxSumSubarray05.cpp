#include "../unit_test_KTLT_array.hpp"

bool UNIT_TEST_KTLT_array::findMaxSumSubarray05() {
  string name = "findMaxSumSubarray05";

  //! data ------------------------------------
  int arr[] = {1, 2, 3};
  int size = 3;
  int k = 4;
  int result = findMaxSumSubarray(arr, size, k);

  //! expect ----------------------------------
  string expect = "0";

  //! output ----------------------------------
  stringstream output;
  output << result;

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}
