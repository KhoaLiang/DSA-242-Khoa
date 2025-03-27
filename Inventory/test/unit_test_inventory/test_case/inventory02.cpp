#include "../unit_test_inventory.hpp"

bool UNIT_TEST_inventory::inventory02()
{
    string name = "inventory02";
    //! data ------------------------------------
    int arr[] = {1, 2, 3, 4, 5};
    List1D<int> list1D(arr, 5);
    
   

    //! expect ----------------------------------
    string expect = "[1, 2, 3, 4, 5]\n";

    //! output ----------------------------------
    stringstream output;
    output << list1D.toString() << endl;

    //! remove data -----------------------------

    //! result ----------------------------------
    return printResult(output.str(), expect, name);
}
