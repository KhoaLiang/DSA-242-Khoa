#include "../unit_test_DLinkedList.hpp"

bool UNIT_TEST_DLinkedList::DLinkedList34()
{
    string name = "DLinkedList34";
   //! data
  DLinkedList<Point *> list(&DLinkedList<Point *>::free, &Point::pointEQ);
  list.add(new Point(23.2f, 25.4f));
  list.add(new Point(24.6f, 23.1f));
  list.add(new Point(12.5f, 22.3f));

  auto interator = list.begin();
  interator.remove(&Point::pointRemove);
  interator++;
  interator.remove(&Point::pointRemove);

  //! expect
  string expect = "[P(12.5, 22.3, 0.0)]";

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
