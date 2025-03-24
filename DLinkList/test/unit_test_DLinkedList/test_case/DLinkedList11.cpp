#include "../unit_test_DLinkedList.hpp"

bool UNIT_TEST_DLinkedList::DLinkedList11()
{
    string name = "DLinkedList11";
    //! data
  DLinkedList<int> list;
  list.add(0);
  list.add(1);
  list.add(2);
  list.removeAt(1);
  list.add(1, 1);
  list.removeAt(2);
  //! expect
  string expect = "[0, 1];size=2;empty=0";

  //! output
  string output = list.toString() + ";size=" + to_string(list.size()) +
                  ";empty=" + to_string(list.empty());

  //! remove data

  //! print result
  return printResult(output, expect, name);
}
