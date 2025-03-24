#include "../unit_test_DLinkedList.hpp"

bool UNIT_TEST_DLinkedList::DLinkedList41()
{
    string name = "DLinkedList41";
    //! data
  DLinkedList<float> dList;
  dList.add(3.2);
  dList.add(5.5);

  //! expect
  string expect = "[3.2, 5.5]\nindex of 5.5: 1\nindex of 15.5: -1\n";

  //! output
  stringstream output;
  output << dList.toString() << endl;
  output << "index of 5.5: " << dList.indexOf(5.5) << endl;
  output << "index of 15.5: " << dList.indexOf(15.5) << endl;

  //! print result
  return printResult(output.str(), expect, name);
}
