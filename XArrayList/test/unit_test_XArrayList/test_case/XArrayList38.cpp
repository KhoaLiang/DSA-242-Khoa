#include "../unit_test_XArrayList.hpp"

bool UNIT_TEST_XArrayList::XArrayList38()
{
    string name = "XArrayList38";
     //! data
  XArrayList<Point> alist;
  alist.add(Point(23.2f, 25.4f));
  alist.add(Point(24.6f, 23.1f));

  //! expect
  string expect = "result 1 : 1\nresult 2 : -1";

  //! output
  stringstream output;
  int idx1 = alist.indexOf(Point(24.6f, 23.1f));
  int idx2 = alist.indexOf(Point(24.61f, 23.1f));
  output << "result 1 : " << idx1 << endl;
  output << "result 2 : " << idx2;

  //! print result
  return printResult(output.str(), expect, name);
}
