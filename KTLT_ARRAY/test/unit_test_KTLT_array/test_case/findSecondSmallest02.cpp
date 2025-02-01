#include "../unit_test_KTLT_array.hpp"

bool UNIT_TEST_KTLT_array::findSecondSmallest02() {
  string name = "findSecondSmallest02";

  //! data ------------------------------------
  int arr[] = {10, 10, 10};
  int size = 3;
  int result = findSecondSmallest(arr, size);

  //! expect ----------------------------------
  string expect = "-1";

  //! output ----------------------------------
  stringstream output;
  output << result;

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}
