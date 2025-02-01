#include "../unit_test_KTLT_array.hpp"

bool UNIT_TEST_KTLT_array::findSecondSmallest04() {
  string name = "findSecondSmallest04";

  //! data ------------------------------------
  int arr[] = {5};
  int size = 1;
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
