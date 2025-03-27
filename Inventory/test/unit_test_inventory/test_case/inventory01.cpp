#include "../unit_test_inventory.hpp"

bool UNIT_TEST_inventory::inventory01()
{
    string name = "inventory01";
    //! data ------------------------------------
    stringstream output;
    List1D<Point> list;

    // Thêm một số điểm vào danh sách
    list.add(Point(1.5, 2.3));
    list.add(Point(-4.2, 3.1));
    list.add(Point(0.0, 0.0));
    List1D<Point> list1(list);
    list1 = list;
    // Hiển thị danh sách
    output << "List1D: " << list << endl;

    // Lấy và cập nhật phần tử
    output << "Phần tử tại index 1: " << list.get(1) << endl;
    list.set(1, Point(9.9, 8.8));
    output << "List1D sau khi cập nhật: " << list << endl;

    
    output<<list.toString()<<endl;

    List2D<Point> matrix;

    // Tạo các dòng của ma trận
    List1D<Point> row1;
    row1.add(Point(1.0, 2.0));
    row1.add(Point(3.0, 4.0));

    List1D<Point> row2;
    row2.add(Point(5.0, 6.0));
    row2.add(Point(7.0, 8.0));

    // Thêm các dòng vào ma trận
    matrix.setRow(0, row1);
    matrix.setRow(1, row2);

    // Hiển thị ma trận
    output << "List2D: " << matrix << endl;

    // Truy xuất và cập nhật giá trị
    output << "Phần tử tại (1,1): " << matrix.get(1, 1) << endl;
    List1D<Point> lista; 
    lista.add(Point(9.9, 9.9));
    lista.add(Point(8.8, 8.8));
   
    matrix.setRow(1, lista);
    output << "List2D sau khi cập nhật hàng thứ 2: " << matrix << endl;
    output << "List2D sau khi xóa hàng đầu tiên: " << matrix << endl;
    List2D<Point> matrix1(matrix);
    matrix1  = matrix;
    output<<matrix.toString()<<endl;
    string expect = "List1D: [P(1.5, 2.3, 0.0), P(-4.2, 3.1, 0.0), P(0.0, 0.0, 0.0)]\n\
Phần tử tại index 1: P(-4.2, 3.1, 0.0)\n\
List1D sau khi cập nhật: [P(1.5, 2.3, 0.0), P(9.9, 8.8, 0.0), P(0.0, 0.0, 0.0)]\n\
[P(1.5, 2.3, 0.0), P(9.9, 8.8, 0.0), P(0.0, 0.0, 0.0)]\n\
List2D: [[P(1.0, 2.0, 0.0), P(3.0, 4.0, 0.0)], [P(5.0, 6.0, 0.0), P(7.0, 8.0, 0.0)]]\n\
Phần tử tại (1,1): P(7.0, 8.0, 0.0)\n\
List2D sau khi cập nhật hàng thứ 2: [[P(1.0, 2.0, 0.0), P(3.0, 4.0, 0.0)], [P(9.9, 9.9, 0.0), P(8.8, 8.8, 0.0)]]\n\
List2D sau khi xóa hàng đầu tiên: [[P(1.0, 2.0, 0.0), P(3.0, 4.0, 0.0)], [P(9.9, 9.9, 0.0), P(8.8, 8.8, 0.0)]]\n\
[[P(1.0, 2.0, 0.0), P(3.0, 4.0, 0.0)], [P(9.9, 9.9, 0.0), P(8.8, 8.8, 0.0)]]\n";
    return printResult(output.str(), expect, name);
}