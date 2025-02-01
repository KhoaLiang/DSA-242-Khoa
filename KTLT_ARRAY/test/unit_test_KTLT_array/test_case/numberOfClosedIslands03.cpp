#include "../unit_test_KTLT_array.hpp"

bool UNIT_TEST_KTLT_array::numberOfClosedIslands03()
{
  string name = "numberOfClosedIslands03";

  //! data ------------------------------------
  int grid[MAX][MAX] = {
      {1, 0, 1, 0, 0},
      {0, 1, 0, 1, 0},
      {0, 1, 0, 1, 0},
      {1, 0, 1, 0, 0}};
  int n = 4, m = 5;

  int result = numberOfClosedIslands(grid, n, m);

  //! expect ----------------------------------
  string expect = "2";

  //! output ----------------------------------
  stringstream output;
  output << result;

  //! remove data -----------------------------

  //! result ----------------------------------
  return printResult(output.str(), expect, name);
}
