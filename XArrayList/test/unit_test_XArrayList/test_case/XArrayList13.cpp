#include "../unit_test_XArrayList.hpp"

bool UNIT_TEST_XArrayList::XArrayList13()
{
    string name = "XArrayList13";
   //! data
  XArrayList<int> list;
  list.add(0);

  //! expect
  string expect = "removeItem=0;[0];size=1;empty=0";

  //! output
  string output = "removeItem=" + to_string(list.removeItem(1)) + ";";
  output += list.toString() + ";size=" + to_string(list.size()) +
            ";empty=" + to_string(list.empty());

  //! remove data

  //! print result
  return printResult(output, expect, name);
}
