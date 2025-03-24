#include "../unit_test_DLinkedList.hpp"

bool UNIT_TEST_DLinkedList::DLinkedList16()
{
    string name = "DLinkedList16";
     //! data
  DLinkedList<int> list;
  list.add(0);
  list.add(1);
  list.add(2);
  list.add(1);

  //! expect
  string expect = "removeItem=0;[0, 1, 2, 1];size=4;empty=0";

  //! output
  string output = "removeItem=" + to_string(list.removeItem(-1)) + ";";
  output += list.toString() + ";size=" + to_string(list.size()) +
            ";empty=" + to_string(list.empty());

  //! remove data

  //! print result
  return printResult(output, expect, name);
}
