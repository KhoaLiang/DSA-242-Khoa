#include "../unit_test_XArrayList.hpp"

bool UNIT_TEST_XArrayList::XArrayList22()
{
    string name = "XArrayList22";
     //! data
  XArrayList<int> list;
  list.clear();
  list.add(0);
  list.add(1);
  list.add(2);
  list.add(1);

  //! expect
  string expect = "Index of item 1: -1";

  //! output
  int index = list.indexOf(-1);
  string output = "Index of item 1: " + to_string(index);

  //! remove data

  //! print result
  return printResult(output, expect, name);
}
