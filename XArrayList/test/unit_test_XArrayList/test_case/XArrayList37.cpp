#include "../unit_test_XArrayList.hpp"

bool UNIT_TEST_XArrayList::XArrayList37()
{
    string name = "XArrayList37";
   //! data
   XArrayList<Point> alist;
   alist.add(Point(23.2f, 25.4f));
   alist.add(Point(24.6f, 23.1f));
 
   //! expect
   string expect = "[P(23.2, 25.4, 0.0), P(24.6, 23.1, 0.0)]";
 
   //! output
   string output = alist.toString();
 
   //! print result
   return printResult(output, expect, name);
}
