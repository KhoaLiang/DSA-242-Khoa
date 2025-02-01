#include "../unit_test_KTLT_array.hpp"

bool UNIT_TEST_KTLT_array::maxSubArray01() {
  string name = "maxSubArray01";

  //! data ------------------------------------
  int arr[] = {1};
  int size = 1;
  int result = maxSubArray(arr, size);

  //! expect ----------------------------------
  string expect = "1";

  //! output ----------------------------------
  stringstream output;
  output << result;

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}
