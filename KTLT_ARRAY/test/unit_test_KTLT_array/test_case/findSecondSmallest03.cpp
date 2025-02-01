#include "../unit_test_KTLT_array.hpp"

bool UNIT_TEST_KTLT_array::findSecondSmallest03() {
  string name = "findSecondSmallest03";

  //! data ------------------------------------
  int arr[] = {8, 6, 7, 6};
  int size = 4;
  int result = findSecondSmallest(arr, size);

  //! expect ----------------------------------
  string expect = "7";

  //! output ----------------------------------
  stringstream output;
  output << result;

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}
