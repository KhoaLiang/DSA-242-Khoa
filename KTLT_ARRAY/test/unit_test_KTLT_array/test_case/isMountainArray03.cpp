#include "../unit_test_KTLT_array.hpp"

bool UNIT_TEST_KTLT_array::isMountainArray03() {
  string name = "isMountainArray03";

  //! data ------------------------------------
  int arr[] = {3, 5, 5};
  int size = 3;
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
