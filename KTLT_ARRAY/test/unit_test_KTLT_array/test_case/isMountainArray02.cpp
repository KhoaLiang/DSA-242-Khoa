#include "../unit_test_KTLT_array.hpp"

bool UNIT_TEST_KTLT_array::isMountainArray02() {
  string name = "isMountainArray02";

  //! data ------------------------------------
  int arr[] = {2, 1};
  int size = 2;
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
