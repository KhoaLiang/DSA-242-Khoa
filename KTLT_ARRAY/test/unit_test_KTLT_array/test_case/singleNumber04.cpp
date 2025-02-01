#include "../unit_test_KTLT_array.hpp"

bool UNIT_TEST_KTLT_array::singleNumber04() {
  string name = "singleNumber04";

  //! data ------------------------------------
  int nums[] = {0};
  int size = 1;
  int result = singleNumber(nums, size);

  //! expect ----------------------------------
  string expect = "0";

  //! output ----------------------------------
  stringstream output;
  output << result;

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}
