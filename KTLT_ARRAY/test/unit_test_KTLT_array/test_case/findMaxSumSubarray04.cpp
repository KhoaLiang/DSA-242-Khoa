#include "../unit_test_KTLT_array.hpp"

bool UNIT_TEST_KTLT_array::findMaxSumSubarray04() {
  string name = "findMaxSumSubarray04";

  //! data ------------------------------------
  int arr[] = {5, 4, -1, 7, 8};
  int size = 5;
  int k = 1;
  int result = findMaxSumSubarray(arr, size, k);

  //! expect ----------------------------------
  string expect = "8";

  //! output ----------------------------------
  stringstream output;
  output << result;

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}
