#include "../unit_test_inventory.hpp"

bool UNIT_TEST_inventory::inventory17()
{
    string name = "inventory17";
   //! data ------------------------------------
   InventoryAttribute attrA1("weight", 10);
   InventoryAttribute attrA2("height", 156);
   InventoryAttribute arrA[] = { attrA1, attrA2 };
   int numAttrA = sizeof(arrA) / sizeof(arrA[0]);
   List1D<InventoryAttribute> listAttrA(arrA, numAttrA);

   InventoryAttribute attrA3("height", 100);
   InventoryAttribute arrA1[] = { attrA1, attrA3 };
   int numAttrA1 = sizeof(arrA1) / sizeof(arrA1[0]);
   List1D<InventoryAttribute> listAttrB(arrA1, numAttrA1);

   InventoryAttribute attrA4("height", 100);
   InventoryAttribute arrA4[] = { attrA1, attrA4 };
   int numAttrA4 = sizeof(arrA4) / sizeof(arrA4[0]);
   List1D<InventoryAttribute> listAttrc(arrA4, numAttrA4);



   List1D<InventoryAttribute> list[] = {listAttrA,listAttrB,listAttrc,listAttrA,listAttrA};
   List2D<InventoryAttribute> emptyMatrix(list,5); // Ma trận thuộc tính rỗng
   string name1[] = {"A", "B","C", "D", "E"};
   List1D<string> names1(name1,5);
   int quan[] = {150, 20, 30, 40, 50};
   List1D<int> quantities1(quan,5);
   InventoryManager inv1(emptyMatrix, names1, quantities1);
   string name2[] = {"F", "G", "I", "H", "J"};
   List1D<string> names2(name2,5);
   int quan1[] = {1100, 70, 80, 90, 100};
   List1D<int> quantities2(quan1,5);
   InventoryManager inv2(emptyMatrix, names2, quantities2);

   InventoryManager merged = InventoryManager::merge(inv1, inv2);
   
   //! expect ----------------------------------
   std::stringstream expect;
   expect << "[B, C, G, I, D, E, H, J, A, F]\n\
[F, A, J, H, E, D, I, G, C, B]\n";
          

   //! output ----------------------------------
   stringstream output;
   double maxvalue = 200;
   double minvalue =5;
   output<<merged.query("height",minvalue,maxvalue,10,true).toString()<<endl;
   output<<merged.query("height",minvalue,maxvalue,10,false).toString()<<endl;
    //! result ----------------------------------
    return printResult(output.str(), expect.str(), name);
}
