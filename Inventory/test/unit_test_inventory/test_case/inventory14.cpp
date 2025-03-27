#include "../unit_test_inventory.hpp"

bool UNIT_TEST_inventory::inventory14()
{
    string name = "inventory14";
    //! data ------------------------------------
    List2D<InventoryAttribute> matrix;
    List1D<string> names;
    List1D<int> quantities;
    InventoryManager inventory(matrix, names, quantities);
    
    string expect = "0\n\
InventoryManager[\n\
  AttributesMatrix: [],\n\
  ProductNames: [],\n\
  Quantities: []\n\
]\n\
[]\n\
[]\n\
[]\n";
    stringstream output;
    output << inventory.size() << endl;
    output<< inventory.toString()<<endl;
    output<<inventory.getProductNames()<<endl;
    output<<inventory.getAttributesMatrix()<<endl;
    output<<inventory.getQuantities()<<endl;
    //! result ----------------------------------
    return printResult(output.str(), expect, name);
}
