#include "../unit_test_XArrayList.hpp"

bool UNIT_TEST_XArrayList::XArrayList02()
{
    string name = "XArrayList02";
    //! data
  XArrayList<int> list;
  list.add(0);
  list = list;
  XArrayList<int> list1(list);
  //! expect
  string expect = "[0]\nsize=1\nempty=0";

  //! output
  string output = list1.toString() + "\nsize=" + to_string(list1.size()) +
                  "\nempty=" + to_string(list1.empty());

  //! remove data

  //! print result
  return printResult(output, expect, name);
}
