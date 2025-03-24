#include "../unit_test_DLinkedList.hpp"

bool UNIT_TEST_DLinkedList::DLinkedList10()
{
    string name = "DLinkedList10";
    //! data
  DLinkedList<int> list;
  list.add(0);
  list.removeAt(0);
  //! expect
  string expect = "[]\nsize=0\nempty=1";

  //! output
  string output = list.toString() + "\nsize=" + to_string(list.size()) +
                  "\nempty=" + to_string(list.empty());

  //! remove data

  //! print result
  return printResult(output, expect, name);
}
