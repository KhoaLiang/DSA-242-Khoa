#include "../unit_test_DLinkedList.hpp"

bool UNIT_TEST_DLinkedList::DLinkedList24()
{
    string name = "DLinkedList24";
     //! data
  DLinkedList<int> list;
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
