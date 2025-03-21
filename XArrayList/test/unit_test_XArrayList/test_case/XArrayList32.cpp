#include "../unit_test_XArrayList.hpp"
void pointRemove(Point* point) { delete point; }
bool UNIT_TEST_XArrayList::XArrayList32()
{
    string name = "XArrayList32";
//! data
XArrayList<Point *> list(&XArrayList<Point *>::free, &Point::pointEQ);
list.add(new Point(23.2f, 25.4f));
list.add(new Point(24.6f, 23.1f));
list.add(new Point(12.5f, 22.3f));
Point p = Point(23.2f, 25.4f);

//! expect
string expect = "removeItem=1";

//! output

string output =
    "removeItem=" + to_string(list.removeItem(&p,pointRemove));

//! remove data

//! print result
return printResult(output, expect, name);
}
