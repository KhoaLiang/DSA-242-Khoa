#include "../unit_test_XArrayList.hpp"

bool UNIT_TEST_XArrayList::XArrayList24()
{
    string name = "XArrayList24";
     //! data
  XArrayList<int> list;
  list.clear();
  list.add(0);
  list.add(1);
  list.add(2);

  //! expect
  string expect = "Contains item 1: false";

  //! output
  bool contains = list.contains(3);
  string output = "Contains item 1: " + string(contains ? "true" : "false");

  //! remove data

  //! print result
  return printResult(output, expect, name);
}
