#include "../unit_test_List1D.hpp"

bool UNIT_TEST_List1D::List1D01()
{
    string name = "List1D01";
    //! data ------------------------------------
    string result = "";

    //! expect ----------------------------------
    string expect = "[1, 2, 3, 4, 5]\n";

    //! output ----------------------------------
    stringstream output;
    output << result;
    int arr[] = {1, 2, 3, 4, 5};
    List1D<int> list1D(arr, 5);
    
    output << list1D << endl;
    //! remove data -----------------------------

    //! result ----------------------------------
    return printResult(output.str(), expect, name);
}
