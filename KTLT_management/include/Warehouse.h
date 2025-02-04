#ifndef WAREHOUSE_HPP
#define WAREHOUSE_HPP

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

// ========================================
// Class Item: Đại diện cho một sản phẩm trong kho
// ========================================
class Item {
public:
    string id, name;
    int quantity;
    string entryDate;
    
    Item(string _id, string _name, int _quantity, string _entryDate);
    void getInfo(stringstream &output) const;
};

// ========================================
// Struct Node: Dùng cho danh sách liên kết
// ========================================
struct Node {
    Item item;
    Node* next;
    Node(Item _item);
};

// ========================================
// Class Warehouse: Lớp cơ sở trừu tượng cho các khu vực kho
// ========================================
class Warehouse {
protected:
    Node* head;
public:
    Warehouse();
    // Phương thức ảo thuần túy để thêm và xóa sản phẩm
    virtual void addItem(Item item, int index = -1) = 0;
    virtual void removeItem(int index = -1) = 0;
    
    // In thông tin các sản phẩm trong kho
    virtual void printInfo(stringstream &output) const;
    
    // Destructor: giải phóng bộ nhớ danh sách liên kết
    virtual ~Warehouse();
};

// ========================================
// Class Area1 (FIFO): Quản lý theo phương pháp FIFO
// ========================================
class Area1 : public Warehouse {
public:
    void addItem(Item item, int index = -1) override;
    void removeItem(int index = -1) override;
};

// ========================================
// Class Area2 (LIFO): Quản lý theo phương pháp LIFO
// ========================================
class Area2 : public Warehouse {
public:
    void addItem(Item item, int index = -1) override;
    void removeItem(int index = -1) override;
};

// ========================================
// Class Area3 (Linked List): Quản lý hàng hóa linh hoạt theo chỉ số
// ========================================
class Area3 : public Warehouse {
public:
    void addItem(Item item, int index = -1) override;
    void removeItem(int index = -1) override;
};

#endif  // WAREHOUSE_HPP
