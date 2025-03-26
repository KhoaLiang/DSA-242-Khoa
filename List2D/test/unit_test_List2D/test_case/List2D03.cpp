#include "../unit_test_List2D.hpp"

bool UNIT_TEST_List2D::List2D03()
{
    string name = "List2D03";
    List1D<int> row;
    row.add(10);
    row.add(20);
    row.add(30);

    List2D<int> matrix;
    matrix.setRow(0, row);
    int value = matrix.get(0, 1); // Lấy phần tử hàng 0, cột 1
    string result = to_string(value);

    //! expect ----------------------------------
    string expect = "20";

    //! output ----------------------------------
    stringstream output;
    output << result;

    //! result ----------------------------------
    return printResult(output.str(), expect, name);
}
