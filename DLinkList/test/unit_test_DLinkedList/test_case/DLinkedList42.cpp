#include "../unit_test_DLinkedList.hpp"

bool UNIT_TEST_DLinkedList::DLinkedList42()
{
    string name = "DLinkedList42";
    //! data
  List<int> list;
  for (int i = 0; i < 10; i++)
      list.add(i, i * i);

  //! expect
  string expect = "Original list:           [0, 1, 4, 9, 16, 25, 36, 49, 64, 81]\n"
                  "After changing an item:  [0, 1, 4, 9, 16, 999, 36, 49, 64, 81]\n";

  //! output
  stringstream output;
  output << setw(25) << left << "Original list: ";
  output << list.toString() << endl;

  int& item = list.get(5);
  item = 999;
  output << setw(25) << left << "After changing an item: ";
  output << list.toString() << endl;

  //! print result
  return printResult(output.str(), expect, name);
}
