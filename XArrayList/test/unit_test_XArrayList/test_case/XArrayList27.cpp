#include "../unit_test_XArrayList.hpp"

bool UNIT_TEST_XArrayList::XArrayList27()
{
    string name = "XArrayList27";
    //! data
  XArrayList<Point> list(0, &Point::pointEQ);
  list.add(Point(3.f, 4.f));
  list.add(Point(4.f, 3.f));

  //! expect
  string expect = "Index of item 1: -1";

  //! output
  int index = list.indexOf(Point(3.f, 5.f));
  string output = "Index of item 1: " + to_string(index);

  //! remove data

  //! print result
  return printResult(output, expect, name);
}
