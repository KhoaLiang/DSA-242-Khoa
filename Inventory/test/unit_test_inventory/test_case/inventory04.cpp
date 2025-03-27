#include "../unit_test_inventory.hpp"

bool UNIT_TEST_inventory::inventory04()
{
    string name = "inventory04";
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
    
   
    string result = "!";

    //! expect ----------------------------------
    string expect = "InventoryManager[\n\
  AttributesMatrix: [[weight: 10.000000, height: 156.000000], [weight: 20.000000, depth: 24.000000, height: 100.000000], [color: 2.000000]],\n\
  ProductNames: [Product A, Product B, Product C],\n\
  Quantities: [50, 30, 20]\n\
]\n";

    //! output ----------------------------------
    stringstream output;

    output << inventory.toString() << endl;
    //! remove data -----------------------------

    //! result ----------------------------------
    return printResult(output.str(), expect, name);
}
