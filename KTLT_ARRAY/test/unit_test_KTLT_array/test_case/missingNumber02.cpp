#include "../unit_test_KTLT_array.hpp"

bool UNIT_TEST_KTLT_array::missingNumber02() {
  string name = "missingNumber02";

  //! data ------------------------------------
  int nums[] = {0, 1};
  int size = 2;
  int result = missingNumber(nums, size);

  //! expect ----------------------------------
  string expect = "2";

  //! output ----------------------------------
  stringstream output;
  output << result;

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}
