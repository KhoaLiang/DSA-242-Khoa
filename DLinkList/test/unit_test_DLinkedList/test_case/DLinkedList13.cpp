#include "../unit_test_DLinkedList.hpp"

bool UNIT_TEST_DLinkedList::DLinkedList13()
{
    string name = "DLinkedList13";
   //! data
  DLinkedList<int> list;
  list.add(0);

  //! expect
  string expect = "removeItem=0;[0];size=1;empty=0";

  //! output
  string output = "removeItem=" + to_string(list.removeItem(1)) + ";";
  output += list.toString() + ";size=" + to_string(list.size()) +
            ";empty=" + to_string(list.empty());

  //! remove data

  //! print result
  return printResult(output, expect, name);
}
