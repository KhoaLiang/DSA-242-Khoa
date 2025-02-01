#include "../unit_test_KTLT_array.hpp"

bool UNIT_TEST_KTLT_array::singleNumber03() {
  string name = "singleNumber03";

  //! data ------------------------------------
  int nums[] = {1, 1, 2, 2, 3, 3, 4};
  int size = 7;
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
