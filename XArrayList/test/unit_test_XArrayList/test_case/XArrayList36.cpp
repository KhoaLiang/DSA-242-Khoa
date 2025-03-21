#include "../unit_test_XArrayList.hpp"

bool UNIT_TEST_XArrayList::XArrayList36()
{
    string name = "XArrayList36";
    //! data
  XArrayList<int> iList;
  for (int i = 0; i < 10; i++)
      iList.add(i, i * i);

  //! expect
  string expect = "0, found at: 0\n"
                  "1, found at: 1\n"
                  "4, found at: 2\n"
                  "9, found at: 3\n"
                  "16, found at: 4\n"
                  "25, found at: 5\n"
                  "36, found at: 6\n"
                  "49, found at: 7\n"
                  "64, found at: 8\n"
                  "81, found at: 9\n"
                  "\n"
                  "lookup for 120 found at: -1";

  //! output
  stringstream output;
  for (XArrayList<int>::Iterator it = iList.begin(); it != iList.end(); it++)
      output << *it << ", found at: " << iList.indexOf(*it) << endl;
  int item = 120;
  int foundIdx = iList.indexOf(item);
  output << "\nlookup for " << item << " found at: " << foundIdx;

  //! print result
  return printResult(output.str(), expect, name);
}
