#include "../unit_test_KTLT_array.hpp"

bool UNIT_TEST_KTLT_array::findMaxSumSubarray03() {
  string name = "findMaxSumSubarray03";

  //! data ------------------------------------
  int arr[] = {5, 4, -1, 7, 8};
  int size = 5;
  int k = 2;
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
