#include "../unit_test_XArrayList.hpp"

bool UNIT_TEST_XArrayList::XArrayList30()
{
    string name = "XArrayList30";
     //! data
  XArrayList<Point *> list(&XArrayList<Point *>::free, &Point::pointEQ);
  list.add(new Point(23.2f, 25.4f));
  list.add(new Point(24.6f, 23.1f));
  list.add(new Point(12.5f, 22.3f));
  XArrayList<Point *> list1(list);
  list1.setDeleteUserDataPtr(nullptr);
  //! expect
  string expect = "[P(23.2, 25.4, 0), P(24.6, 23.1, 0), P(12.5, 22.3, 0)]";

  //! output
  string output = list.toString(&Point::point2str);

  //! remove data

  //! print result
  return printResult(output, expect, name);
}
