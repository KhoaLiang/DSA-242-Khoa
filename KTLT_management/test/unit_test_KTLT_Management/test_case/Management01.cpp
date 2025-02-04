#include "../unit_test_KTLT_Management.hpp"

bool UNIT_TEST_KTLT_Management::Management01() {
    string name = "Management01";
    // Chuẩn bị đầu ra
    stringstream output, expect;

    // Test với Area1: FIFO
    Area1 area1;
    Item item1("I001", "Milk", 10, "2025-01-01");
    Item item2("I002", "Vegetables", 20, "2025-01-02");

    area1.addItem(item1);
    area1.addItem(item2);

    output << "Area1 (Before):" << endl;
    area1.printInfo(output);

    area1.removeItem(); // Loại bỏ phần tử đầu tiên (FIFO)

    output << "Area1 (After):" << endl;
    area1.printInfo(output);

    // Dự kiến đầu ra sau khi xóa item đầu tiên (FIFO)
    expect << "Area1 (Before):" << endl;
    expect << "ID: I001, Name: Milk, Quantity: 10, Entry Date: 2025-01-01" << endl;
    expect << "ID: I002, Name: Vegetables, Quantity: 20, Entry Date: 2025-01-02" << endl;
    expect << "Area1 (After):" << endl;
    expect << "ID: I002, Name: Vegetables, Quantity: 20, Entry Date: 2025-01-02" << endl;

    return printResult(output.str(), expect.str(), name);
}
