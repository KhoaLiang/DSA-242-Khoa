#include "../unit_test_DLinkedList.hpp"

bool UNIT_TEST_DLinkedList::DLinkedList32()
{
    string name = "DLinkedList32";
 //! data
 DLinkedList<Point *> list(&DLinkedList<Point *>::free, &Point::pointEQ);
 list.add(new Point(23.2f, 25.4f));
 list.add(new Point(24.6f, 23.1f));
 list.add(new Point(12.5f, 22.3f));
 Point p = Point(23.2f, 25.4f);

 //! expect
 string expect = "removeItem=1";

 //! output

 string output =
     "removeItem=" + to_string(list.removeItem(&p, &Point::pointRemove));

 //! remove data

 //! print result
 return printResult(output, expect, name);
}

