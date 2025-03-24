#include "../unit_test_DLinkedList.hpp"

bool UNIT_TEST_DLinkedList::DLinkedList27()
{
    string name = "DLinkedList27";
 //! data
 DLinkedList<Point> list(0, &Point::pointEQ);
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
