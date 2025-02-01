#include "../unit_test_KTLT_array.hpp"

bool UNIT_TEST_KTLT_array::isMountainArray05() {
  string name = "isMountainArray05";

  //! data ------------------------------------
  int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
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
