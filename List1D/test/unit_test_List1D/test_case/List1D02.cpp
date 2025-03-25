#include "../unit_test_List1D.hpp"

bool UNIT_TEST_List1D::List1D02()
{
    string name = "List1D02"; // Tên testcase

    //! data ------------------------------------
    List1D<string> list(5);
    list.add("1");
    list.add("2");
    list.add("3");

    //! expect ----------------------------------
    string expect = "[, , , , , 1, 2, 3]"; // Giả sử operator<< in ra theo định dạng này

    //! output ----------------------------------
    stringstream output;
    output << list; // Kiểm tra operator<<

    //! result ----------------------------------
    return printResult(output.str(), expect, name);
}
