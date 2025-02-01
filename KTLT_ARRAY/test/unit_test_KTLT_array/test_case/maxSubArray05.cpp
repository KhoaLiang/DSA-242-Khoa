#include "../unit_test_KTLT_array.hpp"

bool UNIT_TEST_KTLT_array::maxSubArray05() {
  string name = "maxSubArray05";

  //! data ------------------------------------
  int arr[] = {-5, 4, 6, -3, 2, -1, 2};
  int size = 7;
  int result = maxSubArray(arr, size);

  //! expect ----------------------------------
  string expect = "10";

  //! output ----------------------------------
  stringstream output;
  output << result;

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}
