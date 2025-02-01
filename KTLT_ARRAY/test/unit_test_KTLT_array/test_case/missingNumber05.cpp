#include "../unit_test_KTLT_array.hpp"

bool UNIT_TEST_KTLT_array::missingNumber05() {
  string name = "missingNumber05";

  //! data ------------------------------------
  int nums[] = {1};
  int size = 1;
  int result = missingNumber(nums, size);

  //! expect ----------------------------------
  string expect = "0";

  //! output ----------------------------------
  stringstream output;
  output << result;

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}
