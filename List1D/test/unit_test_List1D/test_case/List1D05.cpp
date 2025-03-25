#include "../unit_test_List1D.hpp"

bool UNIT_TEST_List1D::List1D05()
{
    string name = "List1D05";
   //! data ------------------------------------
   List1D<int> list;
   list.add(5);
   list.add(6);
   list.add(7);
   list.add(8);
   list.set(0, 99);

   //! expect ----------------------------------
   string expect = "[99, 6, 7, 8]";

   //! output ----------------------------------
   stringstream output;
   output << list;

   //! result ----------------------------------

    //! result ----------------------------------
    return printResult(output.str(), expect, name);
}
