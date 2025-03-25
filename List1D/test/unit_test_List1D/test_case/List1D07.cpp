#include "../unit_test_List1D.hpp"

bool UNIT_TEST_List1D::List1D07()
{
    string name = "List1D07";
     //! data ------------------------------------
     List1D<int> list;
     list.add(5);
     list.add(6);
     list.add(7);
     list.add(8);
     
  
     //! expect ----------------------------------
     string expect = "[5, 6, 7, 8, 99]";
  
     //! output ----------------------------------
     stringstream output;
     try
     {

         list.set(4,99);

     }
     catch(const std::exception& e)
     {
         output << e.what()<<list.size() << '\n';
     }
    
   output << list;
     
     //! result ----------------------------------

    //! result ----------------------------------
    return printResult(output.str(), expect, name);
}
