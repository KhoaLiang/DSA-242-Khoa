#include "../unit_test_List1D.hpp"

bool UNIT_TEST_List1D::List1D10()
{
    string name = "List1D10";
    List1D<int> list;
     list.add(5);
     list.add(6);
     list.add(7);
     list.add(8);
     List1D<int> *list2 = new List1D(list);
     
   
    
     //! expect ----------------------------------
     string expect = "[5, 6, 7, 8]";
  
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
    
   output << *list2;
   delete list2;
      return printResult(output.str(), expect, name);
}
