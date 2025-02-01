#include "../unit_test_KTLT_array.hpp"

bool UNIT_TEST_KTLT_array::singleNumber02() {
  string name = "singleNumber02";

  //! data ------------------------------------
  int nums[] = {4, 1, 2, 1, 2};
  int size = 5;
  int result = singleNumber(nums, size);

  //! expect ----------------------------------
  string expect = "4";

  //! output ----------------------------------
  stringstream output;
  output << result;

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}
