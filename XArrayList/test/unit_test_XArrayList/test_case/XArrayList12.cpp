#include "../unit_test_XArrayList.hpp"

bool UNIT_TEST_XArrayList::XArrayList12()
{
    string name = "XArrayList12";
  //! data
  XArrayList<int> list;
  list.add(0);

  //! expect
  string expect = "removeItem=1;[];size=0;empty=1";

  //! output
  string output = "removeItem=" + to_string(list.removeItem(0)) + ";";
  output += list.toString() + ";size=" + to_string(list.size()) +
            ";empty=" + to_string(list.empty());

  //! remove data

  //! print result
  return printResult(output, expect, name);
}
