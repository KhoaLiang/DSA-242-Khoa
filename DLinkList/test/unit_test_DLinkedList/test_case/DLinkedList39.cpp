#include "../unit_test_DLinkedList.hpp"

bool UNIT_TEST_DLinkedList::DLinkedList39()
{
    string name = "DLinkedList39";
   //! data
  DLinkedList<Point> dList;
  dList.add(Point(1.5, 3.5));
  dList.add(Point(2.5, 4.5));
  dList.add(Point(1.6, 3.1));
  

//! expect
string expect = "test for indexOf: \nP(1.6, 3.1, 0.0) at: 2";

//! output
stringstream output;
output << "test for indexOf: " << endl;
Point p(1.6, 3.1);
output << p << " at: " << dList.indexOf(p);

//! print result
return printResult(output.str(), expect, name);
}
