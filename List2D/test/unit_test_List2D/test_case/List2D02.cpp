#include "../unit_test_List2D.hpp"

bool UNIT_TEST_List2D::List2D02()
{
    string name = "List2D02";
    List1D<int> row;
    row.add(1);
    row.add(2);
    row.add(3);

    List2D<int> matrix;
    matrix.setRow(0, row);
    string result = matrix.toString();

    //! expect ----------------------------------
    string expect = "[[1, 2, 3]]";

    //! output ----------------------------------
    stringstream output;
    output << result;

    //! result ----------------------------------
    return printResult(output.str(), expect, name);

   
}
