#include "../unit_test_XArrayList.hpp"

bool UNIT_TEST_XArrayList::XArrayList19()
{
    string name = "XArrayList19";
   //! data
  XArrayList<int> list;
  list.add(0);
  list.add(1);
  list.add(2);

  //! expect
  string expect = "Error: Out of range exception: Index is out of range!";

  //! output
  string output = "";
  try {
    list.get(-1);
  } catch (const std::out_of_range &e) {
    output = "Error: Out of range exception: " + string(e.what());
  }
  //! remove data

  //! print result
  return printResult(output, expect, name);
}
