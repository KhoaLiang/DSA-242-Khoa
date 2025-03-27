#include "../unit_test_inventory.hpp"

bool UNIT_TEST_inventory::inventory25()
{
    string name = "inventory25";
     //! data ------------------------------------
     stringstream output;
     //! data ------------------------------------
     // Tạo một InventoryManager trống
     InventoryManager inventory1;
 
     // Tạo danh sách sản phẩm mẫu
     List1D<string> productNames;
     productNames.add("Laptop");
     productNames.add("Phone");
     productNames.add("Tablet");
 
     List1D<int> quantities;
     quantities.add(10);
     quantities.add(5);
     quantities.add(8);
 
     List2D<InventoryAttribute> attributesMatrix;
     // Giả sử InventoryAttribute có constructor (tên thuộc tính, giá trị)
     List1D<InventoryAttribute> laptopAttrs;
     laptopAttrs.add(InventoryAttribute("RAM", 16));
     laptopAttrs.add(InventoryAttribute("Storage", 512));
 
     List1D<InventoryAttribute> phoneAttrs;
     phoneAttrs.add(InventoryAttribute("RAM", 8));
     phoneAttrs.add(InventoryAttribute("Storage", 256));
 
     List1D<InventoryAttribute> tabletAttrs;
     tabletAttrs.add(InventoryAttribute("RAM", 4));
     tabletAttrs.add(InventoryAttribute("Storage", 128));
 
     attributesMatrix.setRow(0,laptopAttrs);
     attributesMatrix.setRow(1,phoneAttrs);
     attributesMatrix.setRow(2,tabletAttrs);
 
    
     // Tạo InventoryManager với dữ liệu mẫu
     InventoryManager inventory2(attributesMatrix, productNames, quantities);
     // Kiểm tra toString()
     output << "Inventory as string: " << inventory2.toString() << endl;
     // Kiểm tra size()
     output << "Size of inventory2: " << inventory2.size() << endl;
 
     // Lấy thông tin sản phẩm theo index
     output << "Product 0 Name: " << inventory2.getProductName(0) << endl;
     output << "Product 0 Quantity: " << inventory2.getProductQuantity(0) << endl;
 
     // Cập nhật số lượng sản phẩm
     inventory2.updateQuantity(0, 15);
     output << "Updated Product 0 Quantity: " << inventory2.getProductQuantity(0) << endl;
 
     // Thêm sản phẩm mới
     List1D<InventoryAttribute> newProductAttrs;
     newProductAttrs.add(InventoryAttribute("RAM", 32));
     newProductAttrs.add(InventoryAttribute("Storage", 1024));
     inventory2.addProduct(newProductAttrs, "Gaming PC", 3);
     output << "New size after adding Gaming PC: " << inventory2.size() << endl;
 
     // Xóa sản phẩm
     inventory2.removeProduct(1);
     output << "Size after removing second product: " << inventory2.size() << endl;
     output<<inventory2.toString()<<endl;
     // Kiểm tra query()
     List1D<string> queryResults = inventory2.query("RAM", 4, 32, 1, true);
     output << "Query results:" << endl;
     for (int i = 0; i < queryResults.size(); i++) {
         output << "- " << queryResults.get(i) << endl;
     }
 // Thêm sản phẩm mới
 List1D<InventoryAttribute> newProductAttrs1;
 newProductAttrs1.add(InventoryAttribute("RAM", 32));
 newProductAttrs1.add(InventoryAttribute("Storage", 1024));
 inventory2.addProduct(newProductAttrs1, "Gaming PC", 5);
     // Kiểm tra removeDuplicates()
     output<<inventory2.toString()<<endl;
     inventory2.removeDuplicates();
     output << "Size after removing duplicates: " << inventory2.size() << endl;
     output<<inventory2.toString()<<endl;
     // Kiểm tra merge()
     InventoryManager mergedInventory = InventoryManager::merge(inventory1, inventory2);
     output << "Size of merged inventory: " << mergedInventory.size() << endl;
 
     // Kiểm tra split()
     InventoryManager section1, section2;
     inventory2.split(section1, section2, 0.5);
     output << "Section 1 size: " << section1.toString() << endl;
     output << "Section 2 size: " << section2.toString() << endl;
 
     // Kiểm tra toString()
     output << "Inventory as string: " << inventory2.toString() << endl;
     string expect = "Inventory as string: InventoryManager[\n\
  AttributesMatrix: [[RAM: 16.000000, Storage: 512.000000], [RAM: 8.000000, Storage: 256.000000], [RAM: 4.000000, Storage: 128.000000]],\n\
  ProductNames: [Laptop, Phone, Tablet],\n\
  Quantities: [10, 5, 8]\n\
]\n\
Size of inventory2: 3\n\
Product 0 Name: Laptop\n\
Product 0 Quantity: 10\n\
Updated Product 0 Quantity: 15\n\
New size after adding Gaming PC: 4\n\
Size after removing second product: 3\n\
InventoryManager[\n\
  AttributesMatrix: [[RAM: 16.000000, Storage: 512.000000], [RAM: 4.000000, Storage: 128.000000], [RAM: 32.000000, Storage: 1024.000000]],\n\
  ProductNames: [Laptop, Tablet, Gaming PC],\n\
  Quantities: [15, 8, 3]\n\
]\n\
Query results:\n\
- Tablet\n\
- Laptop\n\
- Gaming PC\n\
InventoryManager[\n\
  AttributesMatrix: [[RAM: 16.000000, Storage: 512.000000], [RAM: 4.000000, Storage: 128.000000], [RAM: 32.000000, Storage: 1024.000000], [RAM: 32.000000, Storage: 1024.000000]],\n\
  ProductNames: [Laptop, Tablet, Gaming PC, Gaming PC],\n\
  Quantities: [15, 8, 3, 5]\n\
]\n\
Size after removing duplicates: 3\n\
InventoryManager[\n\
  AttributesMatrix: [[RAM: 16.000000, Storage: 512.000000], [RAM: 4.000000, Storage: 128.000000], [RAM: 32.000000, Storage: 1024.000000]],\n\
  ProductNames: [Laptop, Tablet, Gaming PC],\n\
  Quantities: [15, 8, 8]\n\
]\n\
Size of merged inventory: 3\n\
Section 1 size: InventoryManager[\n\
  AttributesMatrix: [[RAM: 16.000000, Storage: 512.000000], [RAM: 4.000000, Storage: 128.000000]],\n\
  ProductNames: [Laptop, Tablet],\n\
  Quantities: [15, 8]\n\
]\n\
Section 2 size: InventoryManager[\n\
  AttributesMatrix: [[RAM: 32.000000, Storage: 1024.000000]],\n\
  ProductNames: [Gaming PC],\n\
  Quantities: [8]\n\
]\n\
Inventory as string: InventoryManager[\n\
  AttributesMatrix: [[RAM: 16.000000, Storage: 512.000000], [RAM: 4.000000, Storage: 128.000000], [RAM: 32.000000, Storage: 1024.000000]],\n\
  ProductNames: [Laptop, Tablet, Gaming PC],\n\
  Quantities: [15, 8, 8]\n\
]\n";

    //! result ----------------------------------
    return printResult(output.str(), expect, name);
}
