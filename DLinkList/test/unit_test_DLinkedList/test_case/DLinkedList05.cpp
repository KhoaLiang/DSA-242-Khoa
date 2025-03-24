#include "../unit_test_DLinkedList.hpp"

bool UNIT_TEST_DLinkedList::DLinkedList05()
{
    string name = "DLinkedList05";
    //! data
  DLinkedList<int> list;
  list.add(0);
  list.add(0, 1);
  list.add(1, 2);
  list.add(3, 3);
  list.add(2, 4);
  list.add(4, 5);
  list.add(6);
  list.add(6, 7);
  list.add(0, 8);
  list.add(1, 9);
  list.add(2, 10);

  //! expect
  string expect = "[8, 9, 10, 1, 2, 4, 0, 5, 3, 7, 6]\nsize=11";

  //! output
  string output = list.toString() + "\nsize=" + to_string(list.size());

  //! remove data

  //! print result
  return printResult(output, expect, name);
}
