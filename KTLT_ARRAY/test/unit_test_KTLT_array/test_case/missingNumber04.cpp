#include "../unit_test_KTLT_array.hpp"

bool UNIT_TEST_KTLT_array::missingNumber04() {
  string name = "missingNumber04";

  //! data ------------------------------------
  int nums[] = {0};
  int size = 1;
  int result = missingNumber(nums, size);

  //! expect ----------------------------------
  string expect = "1";

  //! output ----------------------------------
  stringstream output;
  output << result;

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}
