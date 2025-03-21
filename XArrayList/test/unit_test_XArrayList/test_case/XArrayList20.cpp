#include "../unit_test_XArrayList.hpp"

bool UNIT_TEST_XArrayList::XArrayList20()
{
    string name = "XArrayList20";
    //! data
  XArrayList<int> list;
  list.add(0);
  list.add(10);
  list.add(2);

  //! expect
  string expect = "get=10;[0, 10, 2];size=3;empty=0";

  //! output
  string output = "get=" + to_string(list.get(1)) + ";";
  output += list.toString() + ";size=" + to_string(list.size()) +
            ";empty=" + to_string(list.empty());

  //! remove data

  //! print result
  return printResult(output, expect, name);
}
