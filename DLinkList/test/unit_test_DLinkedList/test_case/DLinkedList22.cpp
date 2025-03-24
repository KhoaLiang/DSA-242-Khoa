#include "../unit_test_DLinkedList.hpp"

bool UNIT_TEST_DLinkedList::DLinkedList22()
{
    string name = "DLinkedList22";
   //! data
  DLinkedList<int> list;
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
