#include "../unit_test_XArrayList.hpp"

bool UNIT_TEST_XArrayList::XArrayList09()
{
    string name = "XArrayList09";
    //! data ------------------------------------
    XArrayList<int> list;
    list.add(0, 0);
    list.add(0, 1);
    list.add(0, 2);
  
    //! expect
    string expect = "Error: Out of range exception: Index is out of range!";
  
    //! output
    string output = "";
    try {
      list.removeAt(3);
    } catch (const std::out_of_range &e) {
      output = "Error: Out of range exception: " + string(e.what());
    }
    //! remove data
  
    //! print result
    return printResult(output, expect, name);
}
