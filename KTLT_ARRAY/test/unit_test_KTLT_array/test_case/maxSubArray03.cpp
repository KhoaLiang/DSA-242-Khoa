#include "../unit_test_KTLT_array.hpp"

bool UNIT_TEST_KTLT_array::maxSubArray03() {
  string name = "maxSubArray03";

  //! data ------------------------------------
  int arr[] = {-1, -2, -3, -4};
  int size = 4;
  int result = maxSubArray(arr, size);

  //! expect ----------------------------------
  string expect = "-1";

  //! output ----------------------------------
  stringstream output;
  output << result;

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}
