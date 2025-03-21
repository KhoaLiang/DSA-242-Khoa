#include "../unit_test_XArrayList.hpp"

bool UNIT_TEST_XArrayList::XArrayList14()
{
    string name = "XArrayList14";
   //! data
  XArrayList<int> list;
  list.add(0);
  list.add(1);
  list.add(2);
  list.add(1);

  //! expect
  string expect = "removeItem=1;[0, 2, 1];size=3;empty=0";

  //! output
  string output = "removeItem=" + to_string(list.removeItem(1)) + ";";
  output += list.toString() + ";size=" + to_string(list.size()) +
            ";empty=" + to_string(list.empty());

  //! remove data

  //! print result
  return printResult(output, expect, name);
}
