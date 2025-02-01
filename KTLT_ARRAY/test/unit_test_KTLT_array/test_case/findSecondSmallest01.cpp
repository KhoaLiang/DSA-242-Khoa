#include "../unit_test_KTLT_array.hpp"

bool UNIT_TEST_KTLT_array::findSecondSmallest01() {
  string name = "findSecondSmallest01";

  //! data ------------------------------------
  int arr[] = {4, 1, 3, 2};
  int size = 4;
  int result = findSecondSmallest(arr, size);

  //! expect ----------------------------------
  string expect = "2";

  //! output ----------------------------------
  stringstream output;
  output << result;

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}
