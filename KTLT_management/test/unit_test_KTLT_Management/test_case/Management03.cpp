#include "../unit_test_KTLT_Management.hpp"

bool UNIT_TEST_KTLT_Management::Management03() {
    string name = "Management03";
    // Chuẩn bị đầu ra
    stringstream output, expect;

    // Test với Area3: Linked List
    Area3 area3;
    Item item1("I001", "Milk", 10, "2025-01-01");
    Item item2("I002", "Vegetables", 20, "2025-01-02");
    Item item3("I003", "Cement", 50, "2025-01-03");

    area3.addItem(item1); 
    area3.addItem(item2);  
    area3.addItem(item3, 1);

    output << "Area3 (Before):" << endl;
    area3.printInfo(output);

    area3.removeItem(1); // Loại bỏ phần tử ở vị trí index 1

    output << "Area3 (After):" << endl;
    area3.printInfo(output);

    // Dự kiến đầu ra sau khi xóa item ở index 1
    expect << "Area3 (Before):" << endl;
    expect << "ID: I001, Name: Milk, Quantity: 10, Entry Date: 2025-01-01" << endl;
    expect << "ID: I003, Name: Cement, Quantity: 50, Entry Date: 2025-01-03" << endl;
    expect << "ID: I002, Name: Vegetables, Quantity: 20, Entry Date: 2025-01-02" << endl;
   
  
    expect << "Area3 (After):" << endl;
    expect << "ID: I001, Name: Milk, Quantity: 10, Entry Date: 2025-01-01" << endl;
    expect << "ID: I002, Name: Vegetables, Quantity: 20, Entry Date: 2025-01-02" << endl;

    return printResult(output.str(), expect.str(), name);
}
