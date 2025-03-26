#include "../unit_test_List2D.hpp"

bool UNIT_TEST_List2D::List2D01()
{
    string name = "List2D01";
    
    //! data ------------------------------------
    int row1[] = {1, 2, 3};
    int row2[] = {4, 5, 6};
    int row3[] = {7, 8, 9};
    
    List1D<int> rows[] = {
        List1D<int>(row1, 3),
        List1D<int>(row2, 3),
        List1D<int>(row3, 3)
    };
    
    List2D<int> matrix(rows, 3);
    
    

    //! expect ----------------------------------
    string expect = "[[1, 2, 3], [4, 5, 6], [7, 8, 9]]";

    //! output ----------------------------------
    stringstream output;
    output << matrix;

    //! remove data -----------------------------

    //! result ----------------------------------
    return printResult(output.str(), expect, name);
}
