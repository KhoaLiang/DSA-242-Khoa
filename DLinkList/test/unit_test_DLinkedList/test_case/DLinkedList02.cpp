#include "../unit_test_DLinkedList.hpp"

bool UNIT_TEST_DLinkedList::DLinkedList02()
{
    string name = "DLinkedList02";
      //! data
  DLinkedList<int> list;
  list.add(0);
 
  DLinkedList<int> list1 = list;
  //! expect
  string expect = "[0]\nsize=1\nempty=0";

  //! output
  string output = list1.toString() + "\nsize=" + to_string(list.size()) +
                  "\nempty=" + to_string(list.empty());

  //! remove data

  //! print result
  return printResult(output, expect, name);
}
