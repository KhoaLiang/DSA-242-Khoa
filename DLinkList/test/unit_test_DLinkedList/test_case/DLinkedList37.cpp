#include "../unit_test_DLinkedList.hpp"

bool UNIT_TEST_DLinkedList::DLinkedList37()
{
    string name = "DLinkedList37";
    //! data
  List<int> dlist;
  for (int i = 0; i < 20; i++)
      dlist.add(i, i * i);

  //! expect
  string expect = "[0, 1, 4, 9, 16, 25, 36, 49, 64, 81, 100, 121, 144, 169, 196, 225, 256, 289, 324, 361]\n"
                  "0 1 4 9 16 25 36 49 64 81 100 121 144 169 196 225 256 289 324 361 ";

  //! output
  stringstream output;
  output << dlist.toString() << endl;
  for (List<int>::Iterator it = dlist.begin(); it != dlist.end(); it++)
      output << *it << " ";

  //! print result
  return printResult(output.str(), expect, name);
}
