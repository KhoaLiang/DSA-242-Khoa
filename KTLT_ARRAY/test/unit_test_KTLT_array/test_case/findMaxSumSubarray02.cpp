#include "../unit_test_KTLT_array.hpp"

bool UNIT_TEST_KTLT_array::findMaxSumSubarray02() {
  string name = "findMaxSumSubarray02";

  //! data ------------------------------------
  int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  int size = 9;
  int k = 2;
  int result = findMaxSumSubarray(arr, size, k);

  //! expect ----------------------------------
  string expect = "3";

  //! output ----------------------------------
  stringstream output;
  output << result;

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}
