#include "../unit_test_XArrayList.hpp"

bool UNIT_TEST_XArrayList::XArrayList23()
{
    string name = "XArrayList23";
   //! data
  XArrayList<int> list;
  list.clear();
  list.add(0);
  list.add(1);
  list.add(2);

  //! expect
  string expect = "Contains item 1: true";

  //! output
  bool contains = list.contains(1);
  string output = "Contains item 1: " + string(contains ? "true" : "false");

  //! remove data

  //! print result
  return printResult(output, expect, name);
}
