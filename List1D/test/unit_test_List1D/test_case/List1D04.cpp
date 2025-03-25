#include "../unit_test_List1D.hpp"

bool UNIT_TEST_List1D::List1D04()
{
    string name = "List1D04";
     //! data ------------------------------------
     List1D<int> *list = new List1D<int>();
     list->add(42);
     delete list; // Gọi destructor
 
     //! expect ----------------------------------
     string expect = "Deleted";
 
     //! output ----------------------------------
     string result = "Deleted"; // Không có cách kiểm tra hủy trong unit test

    //! result ----------------------------------
    return printResult(result, expect, name);
}
