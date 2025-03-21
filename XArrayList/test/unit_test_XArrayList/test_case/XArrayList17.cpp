#include "../unit_test_XArrayList.hpp"

bool UNIT_TEST_XArrayList::XArrayList17()
{
    string name = "XArrayList17";
   //! data
  XArrayList<int> list;
  list.clear();
  list.add(0);
  list.add(1);
  list.add(2);
  list.add(1);
  list.clear();
  list.add(2);
  list.add(1);
  list.clear();
  //! expect
  string expect = "[];size=0;empty=1";

  //! output
  string output = list.toString() + ";size=" + to_string(list.size()) +
                  ";empty=" + to_string(list.empty());

  //! remove data

  //! print result
  return printResult(output, expect, name);
}
