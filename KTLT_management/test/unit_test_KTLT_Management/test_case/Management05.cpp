#include "../unit_test_KTLT_Management.hpp"

bool UNIT_TEST_KTLT_Management::Management05() {
    string name = "Management05";
    // Chuẩn bị đầu ra
    stringstream output, expect;

    // Test với Area5: Hash Map
    Area2 area5;
    Item item1("I001", "Milk", 10, "2025-01-01");
    Item item2("I002", "Vegetables", 20, "2025-01-02");
    Item item3("I003", "Cement", 50, "2025-01-03");

    area5.addItem(item1); // Thêm item1 vào Hash Map
    area5.addItem(item2); // Thêm item2 vào Hash Map
    area5.addItem(item3); // Thêm item3 vào Hash Map

    output << "Area5 (Before):" << endl;
    area5.printInfo(output);

    area5.removeItem(0); // Loại bỏ phần tử có ID là "I002"

    output << "Area5 (After):" << endl;
    area5.printInfo(output);

    // Dự kiến đầu ra sau khi xóa item với ID "I002"
    expect << "Area5 (Before):" << endl;
    expect << "ID: I003, Name: Cement, Quantity: 50, Entry Date: 2025-01-03" << endl;
    expect << "ID: I002, Name: Vegetables, Quantity: 20, Entry Date: 2025-01-02" << endl;
     expect << "ID: I001, Name: Milk, Quantity: 10, Entry Date: 2025-01-01" << endl;
    expect << "Area5 (After):" << endl;
    expect << "ID: I002, Name: Vegetables, Quantity: 20, Entry Date: 2025-01-02" << endl;
    expect << "ID: I001, Name: Milk, Quantity: 10, Entry Date: 2025-01-01" << endl;

    return printResult(output.str(), expect.str(), name);
}
