#include "../unit_test_DLinkedList.hpp"

bool UNIT_TEST_DLinkedList::DLinkedList29()
{
    string name = "DLinkedList29";
     //! data
  DLinkedList<Point> list(0, &Point::pointEQ_X);
  list.add(Point(3.f, 4.f));
  list.add(Point(4.f, 3.f));

  //! expect
  string expect = "Contains item 1: true";

  //! output
  bool contains = list.contains(Point(3.f, 5.f));
  string output = "Contains item 1: " + string(contains ? "true" : "false");

  //! remove data

  //! print result
  return printResult(output, expect, name);
}
