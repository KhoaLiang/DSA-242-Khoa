#include "../unit_test_List2D.hpp"

bool UNIT_TEST_List2D::List2D04()
{
    string name = "List2D04";
     //! data ------------------------------------
     List1D<int> row;
     row.add(11);
     row.add(22);
     row.add(33);
 
     List2D<int> matrix;
     matrix.setRow(0, row);
     List1D<int> fetchedRow = matrix.getRow(0);
     string result = fetchedRow.toString();
 
     //! expect ----------------------------------
     string expect = "[11, 22, 33]";
 
     //! output ----------------------------------
     stringstream output;
     output << result;
 
     //! result ----------------------------------
     return printResult(output.str(), expect, name);
}
