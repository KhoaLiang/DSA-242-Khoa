#include "../unit_test_XArrayList.hpp"

bool UNIT_TEST_XArrayList::XArrayList33()
{
    string name = "XArrayList33";
    //! data
  XArrayList<Point *> list(&XArrayList<Point *>::free, &Point::pointEQ);
  list.add(new Point(23.2f, 25.4f));
  list.add(new Point(24.6f, 23.1f));
  list.add(new Point(12.5f, 22.3f));

  //! expect
  string expect =
      "[P(23.2, 25.4, 0.0), P(24.6, 23.1, 0.0), P(12.5, 22.3, 0.0)]";

  //! output
  stringstream output;
  output << "[";
  for (auto it = list.begin(); it != list.end(); ++it) {
    if (it != list.begin()) output << ", ";
    output << **it;
  }
  output << "]";

  //! remove data
  list.clear();  // Clear list to avoid memory leaks

  //! print result
  return printResult(output.str(), expect, name);
}
