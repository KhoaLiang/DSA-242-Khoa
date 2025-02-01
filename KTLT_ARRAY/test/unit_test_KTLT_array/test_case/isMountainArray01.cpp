#include "../unit_test_KTLT_array.hpp"

bool UNIT_TEST_KTLT_array::isMountainArray01() {
  string name = "isMountainArray01";

  //! data ------------------------------------
  int arr[] = {0, 3, 2, 1};
  int size = 4;
  int result = isMountainArray(arr, size);

  //! expect ----------------------------------
  string expect = "1";

  //! output ----------------------------------
  stringstream output;
  output << result;

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}
