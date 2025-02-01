#include "../unit_test_KTLT_array.hpp"

bool UNIT_TEST_KTLT_array::isMountainArray04() {
  string name = "isMountainArray04";

  //! data ------------------------------------
  int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  int size = 10;
  int result = isMountainArray(arr, size);

  //! expect ----------------------------------
  string expect = "0";

  //! output ----------------------------------
  stringstream output;
  output << result;

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}
