#include "../unit_test_DLinkedList.hpp"

bool UNIT_TEST_DLinkedList::DLinkedList25()
{
    string name = "DLinkedList25";
   //! data
  DLinkedList<Point> list;
  list.add(Point(23.2f, 25.4f));
  list.add(Point(24.6f, 23.1f));

  //! expect
  string expect = "[X: 23.2, X: 24.6]";

  //! output
  string output = list.toString(&Point::point2str_X);

  //! remove data

  //! print result
  return printResult(output, expect, name);
}
