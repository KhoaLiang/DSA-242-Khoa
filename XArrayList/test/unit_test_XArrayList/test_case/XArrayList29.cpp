#include "../unit_test_XArrayList.hpp"

bool UNIT_TEST_XArrayList::XArrayList29()
{
    string name = "XArrayList29";
   //! data
  XArrayList<Point> list(0, &Point::pointEQ);
  list.add(Point(3.f, 4.f));
  list.add(Point(4.f, 3.f));

  //! expect
  string expect = "Contains item 1: false";

  //! output
  bool contains = list.contains(Point(3.f, 5.f));
  string output = "Contains item 1: " + string(contains ? "true" : "false");

  //! remove data

  //! print result
  return printResult(output, expect, name);
}
