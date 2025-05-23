#include "../unit_test_KTLT_array.hpp"

bool UNIT_TEST_KTLT_array::maxAreaOfIsland02() {
  string name = "maxAreaOfIsland02";

  //! data ------------------------------------
  int grid[MAX][MAX] = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
  int n = 4, m = 4;

  int result = maxAreaOfIsland(grid, n, m);

  //! expect ----------------------------------
  string expect = "0";

  //! output ----------------------------------
  stringstream output;
  output << result;

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}
