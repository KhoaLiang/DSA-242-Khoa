#include "../unit_test_inventory.hpp"

bool UNIT_TEST_inventory::inventory03()
{
    string name = "inventory03";
    //! data ------------------------------------
    int row0[] = {1, 2, 3};
    int row1[] = {4, 5, 6};
    int row2[] = {7, 8, 9};
    
    List1D<int> arr2D[] = { List1D<int>(row0, 3), List1D<int>(row1, 3), List1D<int>(row2, 3) };
    
    List2D<int> matrix(arr2D, 3);

    //! expect ----------------------------------
    string expect = "[[1, 2, 3], [4, 5, 6], [7, 8, 9]]\n";

    //! output ----------------------------------
    stringstream output;
   
    output << matrix.toString() << endl;
    //! remove data -----------------------------

    //! result ----------------------------------
    return printResult(output.str(), expect, name);
}
