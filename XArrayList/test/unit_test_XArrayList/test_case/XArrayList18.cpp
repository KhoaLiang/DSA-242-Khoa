#include "../unit_test_XArrayList.hpp"

bool UNIT_TEST_XArrayList::XArrayList18()
{
    string name = "XArrayList18";
    //! data
  XArrayList<int> list;

  //! expect
  string expect = "Error: Out of range exception: Index is out of range!";

  //! output
  string output = "";
  try {
    list.get(0);
  } catch (const std::out_of_range &e) {
    output = "Error: Out of range exception: " + string(e.what());
  }
  //! remove data

  //! print result
  return printResult(output, expect, name);
}
