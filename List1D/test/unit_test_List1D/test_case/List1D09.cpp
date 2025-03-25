#include "../unit_test_List1D.hpp"

bool UNIT_TEST_List1D::List1D09()
{
    string name = "List1D09";
     //! data ------------------------------------
     List1D<int> list;
     list.add(5);
     list.add(6);
     list.add(7);
     list.add(8);
     List1D<int> list2(5);
     
  
     //! expect ----------------------------------
     string expect = "[0, 0, 0, 0, 0]";
  
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
    
   output << list2;
      return printResult(output.str(), expect, name);
}
