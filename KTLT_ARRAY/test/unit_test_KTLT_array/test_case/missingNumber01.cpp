#include "../unit_test_KTLT_array.hpp"

bool UNIT_TEST_KTLT_array::missingNumber01() {
  string name = "missingNumber01";

  //! data ------------------------------------
  int nums[] = {3, 0, 1};
  int size = 3;
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
