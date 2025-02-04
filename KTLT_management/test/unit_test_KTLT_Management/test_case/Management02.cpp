#include "../unit_test_KTLT_Management.hpp"

bool UNIT_TEST_KTLT_Management::Management02() {
    string name = "Management02";
    // Chuẩn bị đầu ra
    stringstream output, expect;

    // Test với Area2: LIFO
    Area2 area2;
    Item item2("I002", "Vegetables", 20, "2025-01-02");
    Item item3("I003", "Cement", 50, "2025-01-03");

    area2.addItem(item2);
    area2.addItem(item3);

    output << "Area2 (Before):" << endl;
    area2.printInfo(output);

    area2.removeItem(); // Loại bỏ phần tử đầu tiên (vì hàng mới nhất ở đầu)

    output << "Area2 (After):" << endl;
    area2.printInfo(output);

    // Dự kiến đầu ra sau khi xóa item đầu tiên (LIFO)
    expect << "Area2 (Before):" << endl;
    expect << "ID: I003, Name: Cement, Quantity: 50, Entry Date: 2025-01-03" << endl;
    expect << "ID: I002, Name: Vegetables, Quantity: 20, Entry Date: 2025-01-02" << endl;
    expect << "Area2 (After):" << endl;
    expect << "ID: I002, Name: Vegetables, Quantity: 20, Entry Date: 2025-01-02" << endl;

    return printResult(output.str(), expect.str(), name);
}
