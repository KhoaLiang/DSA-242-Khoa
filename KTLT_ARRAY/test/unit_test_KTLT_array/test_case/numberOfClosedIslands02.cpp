#include "../unit_test_KTLT_array.hpp"

bool UNIT_TEST_KTLT_array::numberOfClosedIslands02() {
  string name = "numberOfClosedIslands02";

  //! data ------------------------------------
  int grid[MAX][MAX] = {
      {0, 0, 0, 0, 0}, 
      {0, 1, 1, 0, 0}, 
      {0, 1, 1, 0, 0}, 
      {0, 0, 0, 0, 0}};
  int n = 4, m = 5;

  int result = numberOfClosedIslands(grid, n, m);

  //! expect ----------------------------------
  string expect = "1";

  //! output ----------------------------------
  stringstream output;
  output << result;

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}
