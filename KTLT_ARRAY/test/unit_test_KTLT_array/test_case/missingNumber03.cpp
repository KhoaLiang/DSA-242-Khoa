#include "../unit_test_KTLT_array.hpp"

bool UNIT_TEST_KTLT_array::missingNumber03() {
  string name = "missingNumber03";

  //! data ------------------------------------
  int nums[] = {9, 6, 4, 2, 3, 5, 7, 0, 1};
  int size = 9;
  int result = missingNumber(nums, size);

  //! expect ----------------------------------
  string expect = "8";

  //! output ----------------------------------
  stringstream output;
  output << result;

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}
