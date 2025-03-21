#include "../unit_test_XArrayList.hpp"

bool UNIT_TEST_XArrayList::XArrayList35()
{
    string name = "XArrayList35";
   //! data
  XArrayList<Point *> list(&XArrayList<Point *>::free, &Point::pointEQ, 0);
  list.add(new Point(23.2f, 25.4f));
  list.add(new Point(24.6f, 23.1f));
  list.add(new Point(12.5f, 22.3f));
  list.add(new Point(23.2f, 25.4f));
  list.add(new Point(24.6f, 23.1f));
  list.add(new Point(12.5f, 22.3f));
  list.add(new Point(23.2f, 25.4f));
  list.add(new Point(24.6f, 23.1f));
  list.add(new Point(12.5f, 22.3f));
  list.add(new Point(23.2f, 25.4f));
  list.add(new Point(24.6f, 23.1f));
  list.add(new Point(12.5f, 22.3f));

  //! expect
  string expect =
      "[P(23.2, 25.4, 0.0), P(24.6, 23.1, 0.0), P(12.5, 22.3, 0.0), P(23.2, "
      "25.4, 0.0), P(24.6, 23.1, 0.0), P(12.5, 22.3, 0.0), P(23.2, 25.4, 0.0), "
      "P(24.6, 23.1, 0.0), P(12.5, 22.3, 0.0), P(23.2, 25.4, 0.0), P(24.6, "
      "23.1, 0.0), P(12.5, 22.3, 0.0), ]";

  //! output
  stringstream output;
  output << "[";
  for (auto it : list) {
    output << *it << ", ";
  }
  output << "]";

  //! remove data

  //! print result
  return printResult(output.str(), expect, name);
}
