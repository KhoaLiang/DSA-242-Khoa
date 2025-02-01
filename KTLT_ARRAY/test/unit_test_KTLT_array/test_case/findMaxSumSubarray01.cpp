#include "../unit_test_KTLT_array.hpp"

bool UNIT_TEST_KTLT_array::findMaxSumSubarray01() {
  string name = "findMaxSumSubarray01";

  //! data ------------------------------------
  int arr[] = {1, 2, 3, 4, 5, 6};
  int size = 6;
  int k = 3;
  int result = findMaxSumSubarray(arr, size, k);

  //! expect ----------------------------------
  string expect = "15";

  //! output ----------------------------------
  stringstream output;
  output << result;

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}
