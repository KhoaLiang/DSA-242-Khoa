#include "../unit_test_KTLT_array.hpp"

bool UNIT_TEST_KTLT_array::singleNumber05() {
  string name = "singleNumber05";

  //! data ------------------------------------
  int nums[] = {10, 14, 10, 14, 22};
  int size = 5;
  int result = singleNumber(nums, size);

  //! expect ----------------------------------
  string expect = "22";

  //! output ----------------------------------
  stringstream output;
  output << result;

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}
