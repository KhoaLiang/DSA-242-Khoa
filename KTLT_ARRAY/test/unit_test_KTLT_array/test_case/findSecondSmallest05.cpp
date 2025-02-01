#include "../unit_test_KTLT_array.hpp"

bool UNIT_TEST_KTLT_array::findSecondSmallest05() {
  string name = "findSecondSmallest05";

  //! data ------------------------------------
  int arr[] = {3, 1, 4, 1, 5};
  int size = 5;
  int result = findSecondSmallest(arr, size);

  //! expect ----------------------------------
  string expect = "3";

  //! output ----------------------------------
  stringstream output;
  output << result;

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}
