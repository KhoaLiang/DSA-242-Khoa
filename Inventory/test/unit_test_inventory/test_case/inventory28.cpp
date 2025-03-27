#include "../unit_test_inventory.hpp"

bool UNIT_TEST_inventory::inventory28()
{
    string name = "inventory28";
     // Tạo một InventoryManager trống
     stringstream output;
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
     inventory1 = inventory2;
     inventory1.removeProduct(0);
     inventory1.removeProduct(1);
     inventory1.removeProduct(0);
     // Kiểm tra query()
     inventory2.removeDuplicates();
     output << inventory2.toString() << endl;
     output << inventory1.toString() << endl;
     string expect = "InventoryManager[\n\
  AttributesMatrix: [[RAM: 16.000000, Storage: 512.000000], [RAM: 8.000000, Storage: 256.000000], [RAM: 4.000000, Storage: 128.000000]],\n\
  ProductNames: [Laptop, Phone, Tablet],\n\
  Quantities: [10, 5, 8]\n\
]\n\
InventoryManager[\n\
  AttributesMatrix: [],\n\
  ProductNames: [],\n\
  Quantities: []\n\
]\n";
    //! result ----------------------------------
    return printResult(output.str(), expect, name);
}
