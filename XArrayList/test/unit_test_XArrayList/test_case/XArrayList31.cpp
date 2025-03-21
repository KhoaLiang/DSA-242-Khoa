#include "../unit_test_XArrayList.hpp"

bool UNIT_TEST_XArrayList::XArrayList31()
{
    string name = "XArrayList31";
    //! data
  XArrayList<Point *> list(&XArrayList<Point *>::free, &Point::pointEQ);
  list.add(new Point(23.2f, 25.4f));
  list.add(new Point(24.6f, 23.1f));
  list.add(new Point(12.5f, 22.3f));
  list.clear();
  //! expect
  string expect = "[]";

  //! output
  string output = list.toString(&Point::point2str);

  //! remove data

  //! print result
  return printResult(output, expect, name);
}
