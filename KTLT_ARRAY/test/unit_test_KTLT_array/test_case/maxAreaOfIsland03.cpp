#include "../unit_test_KTLT_array.hpp"

bool UNIT_TEST_KTLT_array::maxAreaOfIsland03() {
  string name = "maxAreaOfIsland03";

  //! data ------------------------------------
  int grid[MAX][MAX] = {{1, 1, 0, 0}, {1, 0, 0, 1}, {1, 0, 1, 1}, {0, 0, 1, 1}};
  int n = 4, m = 4;

  int result = maxAreaOfIsland(grid, n, m);

  //! expect ----------------------------------
  string expect = "5";

  //! output ----------------------------------
  stringstream output;
  output << result;

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}
