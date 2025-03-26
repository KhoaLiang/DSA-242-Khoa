#include "../unit_test_List2D.hpp"

bool UNIT_TEST_List2D::List2D07()
{
    string name = "List2D07";
     //! data ------------------------------------
     List2D<int> original;
     List1D<int> row1;
     row1.add(1); row1.add(2); row1.add(3);
     List1D<int> row2;
     row2.add(4); row2.add(5); row2.add(6);
     stringstream output;
     original.setRow(0, row1);
     original.setRow(1, row2);
     try {
        output <<  original.getRow(1);
     } catch (const out_of_range &e) {
         output << e.what() << endl;
     }
     // Copy constructor
     List2D<int> copy(original);
     
     //! expect ----------------------------------
     string expect = "[4, 5, 6][[1, 2, 3], [4, 5, 6]]";
     
     //! output ----------------------------------
     
     output << copy;
     
     //! remove data -----------------------------
    
     
     //! result ----------------------------------
     return printResult(output.str(), expect, name);
}
