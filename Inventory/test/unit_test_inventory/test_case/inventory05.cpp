#include "../unit_test_inventory.hpp"

bool UNIT_TEST_inventory::inventory05()
{
    string name = "inventory05";
    //! data ------------------------------------
    InventoryAttribute attrA1("weight", 10);
    InventoryAttribute attrA2("height", 156);
    InventoryAttribute arrA[] = { attrA1, attrA2 };
    int numAttrA = sizeof(arrA) / sizeof(arrA[0]);
    List1D<InventoryAttribute> listAttrA(arrA, numAttrA);

    InventoryAttribute attrB1("weight", 20);
    InventoryAttribute attrB2("depth", 24);
    InventoryAttribute attrB3("height", 100);
    InventoryAttribute arrB[] = { attrB1, attrB2, attrB3 };
    int numAttrB = sizeof(arrB) / sizeof(arrB[0]);
    List1D<InventoryAttribute> listAttrB(arrB, numAttrB);

    InventoryAttribute attrC1("color", 2);
    InventoryAttribute arrC[] = { attrC1 };
    int numAttrC = sizeof(arrC) / sizeof(arrC[0]);
    List1D<InventoryAttribute> listAttrC(arrC, numAttrC);

    List1D<InventoryAttribute> attributesArray[3] = { listAttrA, listAttrB, listAttrC };
    List2D<InventoryAttribute> attributesMatrix(attributesArray, 3);

    string namesArray[] = { "Product A", "Product B", "Product C" };
    List1D<string> productNames(namesArray, 3);
    
    int quantitiesArray[] = { 50, 30, 20 };
    List1D<int> quantities(quantitiesArray, 3);

    InventoryManager inventory(attributesMatrix, productNames, quantities);
    
    InventoryAttribute attrD1("weight", 15);
    InventoryAttribute attrD2("height", 140);
    InventoryAttribute arrD[] = { attrD1, attrD2 };
    int numAttrD = sizeof(arrD) / sizeof(arrD[0]);
    List1D<InventoryAttribute> listAttrD(arrD, numAttrD);
    inventory.addProduct(listAttrD, "Product D", 40);
   
    

    //! expect ----------------------------------
    string expect = "\nAfter adding Product D:\n\
InventoryManager[\n\
  AttributesMatrix: [[weight: 10.000000, height: 156.000000], [weight: 20.000000, depth: 24.000000, height: 100.000000], [color: 2.000000], [weight: 15.000000, height: 140.000000]],\n\
  ProductNames: [Product A, Product B, Product C, Product D],\n\
  Quantities: [50, 30, 20, 40]\n\
]\n";

    //! output ----------------------------------
    stringstream output;
  
    output << "\nAfter adding Product D:" << endl;
    output << inventory.toString() << endl;
    //! remove data -----------------------------

    //! result ----------------------------------
    return printResult(output.str(), expect, name);
}
