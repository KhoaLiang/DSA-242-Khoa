#include "../unit_test_inventory.hpp"

bool UNIT_TEST_inventory::inventory24()
{
    string name = "inventory24";
     
       
     //! expect ----------------------------------
     string expect = "[]\n\
[]\n\
0\n\
[]\n\
InventoryManager[\n\
  AttributesMatrix: [],\n\
  ProductNames: [],\n\
  Quantities: []\n\
]\n\
[]\n\
InventoryManager[\n\
  AttributesMatrix: [],\n\
  ProductNames: [],\n\
  Quantities: []\n\
]\n\
InventoryManager[\n\
  AttributesMatrix: [],\n\
  ProductNames: [],\n\
  Quantities: []\n\
]\n"; // Thay thế bằng output mong đợi thực tế
     
     //! output ----------------------------------
      std::stringstream output;
      InventoryManager *inv = new InventoryManager();
      output<<inv->getQuantities()<<endl;
      output<<inv->getAttributesMatrix()<<endl;
      output<<inv->size()<<endl;
      output<<inv->getQuantities()<<endl;
      inv->removeDuplicates() ;
      output<< inv->toString()<<endl;
      double minvalue = 10;
      double maxvalue = 200;
      output<<inv->query("LIST",minvalue,maxvalue,10,true).toString()<<endl;
        InventoryManager s1 ;
        InventoryManager s2 ;
        inv->split(s1,s2,0.23);
        output<<s1.toString()<<endl;
        output<<s2.toString()<<endl;
     //! cleanup ----------------------------------
     delete inv;
    //! result ----------------------------------
    return printResult(output.str(), expect, name);
}
