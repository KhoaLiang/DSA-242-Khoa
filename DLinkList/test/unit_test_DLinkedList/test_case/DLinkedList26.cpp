#include "../unit_test_DLinkedList.hpp"

bool UNIT_TEST_DLinkedList::DLinkedList26()
{
    string name = "DLinkedList26";
 
    //! data
  DLinkedList<Point> list;
  list.add(Point(23.2f, 25.4f));
  list.add(Point(24.6f, 23.1f));

  //! expect
  string expect = "[P(23.2, 25.4, 0), P(24.6, 23.1, 0)]";

  //! output
  string output = list.toString(&Point::point2str);

  //! remove data

  //! print result
  return printResult(output, expect, name);
}
