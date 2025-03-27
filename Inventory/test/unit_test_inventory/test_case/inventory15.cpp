#include "../unit_test_inventory.hpp"

bool UNIT_TEST_inventory::inventory15()
{
    string name = "inventory15";
   //! data ------------------------------------
   InventoryAttribute attrA1("weight", 10);
   InventoryAttribute attrA2("height", 156);
   InventoryAttribute arrA[] = { attrA1, attrA2 };
   int numAttrA = sizeof(arrA) / sizeof(arrA[0]);
   List1D<InventoryAttribute> listAttrA(arrA, numAttrA);

   List1D<InventoryAttribute> list[] = {listAttrA,listAttrA,listAttrA,listAttrA,listAttrA};
   List2D<InventoryAttribute> emptyMatrix(list,5); // Ma trận thuộc tính rỗng
   string name1[] = {"A", "B", "C", "D", "E"};
   List1D<string> names1(name1,5);
   int quan[] = {10, 20, 30, 40, 50};
   List1D<int> quantities1(quan,5);
   InventoryManager inv1(emptyMatrix, names1, quantities1);
   string name2[] = {"F", "G", "H", "I", "J"};
   List1D<string> names2(name2,5);
   int quan1[] = {60, 70, 80, 90, 100};
   List1D<int> quantities2(quan1,5);
   InventoryManager inv2(emptyMatrix, names2, quantities2);

   InventoryManager merged = InventoryManager::merge(inv1, inv2);
   
   //! expect ----------------------------------
   stringstream expect;
    expect << "InventoryManager[\n"
           << "  AttributesMatrix: [[weight: 10.000000, height: 156.000000], "
           << "[weight: 10.000000, height: 156.000000], "
           << "[weight: 10.000000, height: 156.000000], "
           << "[weight: 10.000000, height: 156.000000], "
           << "[weight: 10.000000, height: 156.000000]],\n"
           << "  ProductNames: [A, B, C, D, E],\n"
           << "  Quantities: [10, 20, 30, 40, 50]\n"
           << "]\n"
           << "InventoryManager[\n"
           << "  AttributesMatrix: [[weight: 10.000000, height: 156.000000], "
           << "[weight: 10.000000, height: 156.000000], "
           << "[weight: 10.000000, height: 156.000000], "
           << "[weight: 10.000000, height: 156.000000], "
           << "[weight: 10.000000, height: 156.000000]],\n"
           << "  ProductNames: [F, G, H, I, J],\n"
           << "  Quantities: [60, 70, 80, 90, 100]\n"
           << "]\n"
           << "InventoryManager[\n"
           << "  AttributesMatrix: [[weight: 10.000000, height: 156.000000], "
           << "[weight: 10.000000, height: 156.000000], "
           << "[weight: 10.000000, height: 156.000000], "
           << "[weight: 10.000000, height: 156.000000], "
           << "[weight: 10.000000, height: 156.000000], "
           << "[weight: 10.000000, height: 156.000000], "
           << "[weight: 10.000000, height: 156.000000], "
           << "[weight: 10.000000, height: 156.000000], "
           << "[weight: 10.000000, height: 156.000000], "
           << "[weight: 10.000000, height: 156.000000]],\n"
           << "  ProductNames: [A, B, C, D, E, F, G, H, I, J],\n"
           << "  Quantities: [10, 20, 30, 40, 50, 60, 70, 80, 90, 100]\n"
           << "]\n";

   //! output ----------------------------------
   stringstream output;
   output<<inv1.toString()<<endl;
   output<<inv2.toString()<<endl;
   output<<merged.toString()<<endl;
    //! result ----------------------------------
    return printResult(output.str(), expect.str(), name);
}
