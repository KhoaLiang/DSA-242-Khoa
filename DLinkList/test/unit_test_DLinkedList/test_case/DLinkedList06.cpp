#include "../unit_test_DLinkedList.hpp"

bool UNIT_TEST_DLinkedList::DLinkedList06()
{
    string name = "DLinkedList06";
  //! data
  DLinkedList<int> list;

  //! expect
  string expect = "Error: Out of range exception: Index is out of range!";

  //! output
  string output = "";
  try {
    list.add(1, 0);
  } catch (const std::out_of_range &e) {
    output = "Error: Out of range exception: " + string(e.what());
  }

  //! remove data

  //! print result
  return printResult(output, expect, name);
}
