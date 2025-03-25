#include "../unit_test_List1D.hpp"

bool UNIT_TEST_List1D::List1D06()
{
    string name = "List1D06";
    //! data ------------------------------------
    List1D<int> list;
    list.add(5);
    list.add(6);
    list.add(7);
    list.add(8);
    
 
    //! expect ----------------------------------
    string expect = "[5, 6, 7, 8]Index is out of range!\n";
 
    //! output ----------------------------------
    stringstream output;
    output << list;
    try
    {
        list.get(4);
    }
    catch(const std::exception& e)
    {
        output << e.what() << '\n';
    }
    
    
    //! result ----------------------------------
 
     //! result ----------------------------------
     return printResult(output.str(), expect, name);
}
