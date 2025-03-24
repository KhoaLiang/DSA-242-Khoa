#include "../unit_test_DLinkedList.hpp"

bool UNIT_TEST_DLinkedList::DLinkedList12()
{
    string name = "DLinkedList12";
    //! data
  DLinkedList<int> list;
  list.add(0);

  //! expect
  string expect = "removeItem=1;[];size=0;empty=1";

  //! output
  string output = "removeItem=" + to_string(list.removeItem(0)) + ";";
  output += list.toString() + ";size=" + to_string(list.size()) +
            ";empty=" + to_string(list.empty());

  //! remove data

  //! print result
  return printResult(output, expect, name);
}
