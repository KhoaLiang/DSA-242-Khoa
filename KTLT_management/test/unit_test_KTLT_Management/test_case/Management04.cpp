#include "../unit_test_KTLT_Management.hpp"

bool UNIT_TEST_KTLT_Management::Management04() {
    string name = "Management04";
    // Chuẩn bị đầu ra
    stringstream output, expect;

    // Test với Area4: Priority Queue
    Area3 area4;
    Item item1("I001", "Milk", 10, "2025-01-01");
    Item item2("I002", "Vegetables", 20, "2025-01-02");
    Item item3("I003", "Cement", 50, "2025-01-03");
    

    area4.addItem(item1, 2); // Thêm với độ ưu tiên 2
    area4.addItem(item2, 1); // Thêm với độ ưu tiên 1
    area4.addItem(item3, 3); // Thêm với độ ưu tiên 3

    output << "Area4 (Before):" << endl;
    area4.printInfo(output);

    area4.removeItem(2); 

    output << "Area4 (After):" << endl;
    area4.printInfo(output);

    // Dự kiến đầu ra sau khi xóa item có độ ưu tiên cao nhất
    expect << "Area4 (Before):" << endl;
    
    expect << "ID: I001, Name: Milk, Quantity: 10, Entry Date: 2025-01-01" << endl;
    expect << "ID: I002, Name: Vegetables, Quantity: 20, Entry Date: 2025-01-02" << endl;
    expect << "ID: I003, Name: Cement, Quantity: 50, Entry Date: 2025-01-03" << endl;
    expect << "Area4 (After):" << endl;
  
    expect << "ID: I001, Name: Milk, Quantity: 10, Entry Date: 2025-01-01" << endl;
    expect << "ID: I002, Name: Vegetables, Quantity: 20, Entry Date: 2025-01-02" << endl;

    return printResult(output.str(), expect.str(), name);
}
