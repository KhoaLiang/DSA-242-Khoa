#include "../unit_test_KTLT_array.hpp"

bool UNIT_TEST_KTLT_array::singleNumber01() {
  string name = "singleNumber01";

  //! data ------------------------------------
  int nums[] = {2, 2, 1};
  int size = 3;
  int result = singleNumber(nums, size);

  //! expect ----------------------------------
  string expect = "1";

  //! output ----------------------------------
  stringstream output;
  output << result;

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}
