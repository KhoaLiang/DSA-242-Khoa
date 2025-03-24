#include "../unit_test_DLinkedList.hpp"

bool UNIT_TEST_DLinkedList::DLinkedList04()
{
    string name = "DLinkedList04";
   //! data
  DLinkedList<int> list;
  list.add(0, 0);
  list.add(0, 1);
  list.add(0, 2);
  list.add(2, 3);

  //! expect
  string expect = "[2, 1, 3, 0]\nsize=4";

  //! output
  string output = list.toString() + "\nsize=" + to_string(list.size());

  //! remove data

  //! print result
  return printResult(output, expect, name);
}
