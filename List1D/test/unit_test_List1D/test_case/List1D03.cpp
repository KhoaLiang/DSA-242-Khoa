#include "../unit_test_List1D.hpp"

bool UNIT_TEST_List1D::List1D03()
{
    string name = "List1D03";
    //! data ------------------------------------
    List1D<int> original;
    original.add(10);
    original.add(20);
   
    List1D<int> copy(original);

    //! expect ----------------------------------
    string expect = "get index 0 10[10, 20]";

    //! output ----------------------------------
    stringstream output;
    output <<"get index 0 "<<original.get(0);
    output << copy;
    //! result ----------------------------------
    return printResult(output.str(), expect, name);
}
