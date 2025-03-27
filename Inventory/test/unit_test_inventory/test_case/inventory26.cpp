#include "../unit_test_inventory.hpp"

bool UNIT_TEST_inventory::inventory26()
{
    string name = "inventory26";
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
      List1D<string> queryResults = inventory2.query("RAM", 4, 32, 6, false);
      output << "Query results:" << endl;
      for (int i = 0; i < queryResults.size(); i++) {
          output << "- " << queryResults.get(i) << endl;
      }
       
      string expect = "New size after adding Gaming PC: 4\n\
Size after removing second product: 3\n\
InventoryManager[\n\
  AttributesMatrix: [[RAM: 16.000000, Storage: 512.000000], [RAM: 4.000000, Storage: 128.000000], [RAM: 32.000000, Storage: 1024.000000]],\n\
  ProductNames: [Laptop, Tablet, Gaming PC],\n\
  Quantities: [10, 8, 3]\n\
]\n\
Query results:\n\
- Laptop\n\
- Tablet\n";
 
    //! result ----------------------------------
    return printResult(output.str(), expect, name);
}
