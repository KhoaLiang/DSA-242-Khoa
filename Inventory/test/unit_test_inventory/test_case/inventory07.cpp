#include "../unit_test_inventory.hpp"

bool UNIT_TEST_inventory::inventory07()
{
    string name = "inventory07";
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


    //! expect ----------------------------------
    string expect = "\nAfter adding duplicate of Product A:\n\
InventoryManager[\n\
  AttributesMatrix: [[weight: 10.000000, height: 156.000000], [weight: 20.000000, depth: 24.000000, height: 100.000000], [color: 2.000000], [weight: 10.000000, height: 156.000000]],\n\
  ProductNames: [Product A, Product B, Product C, Product A],\n\
  Quantities: [50, 30, 20, 20]\n\
]\n\
\nAfter removing duplicates:\n\
InventoryManager[\n\
  AttributesMatrix: [[weight: 10.000000, height: 156.000000], [weight: 20.000000, depth: 24.000000, height: 100.000000], [color: 2.000000]],\n\
  ProductNames: [Product A, Product B, Product C],\n\
  Quantities: [70, 30, 20]\n\
]\n";

    //! output ----------------------------------
    stringstream output;
    inventory.addProduct(listAttrA, "Product A", 20);
    output << "\nAfter adding duplicate of Product A:" << endl;
    output << inventory.toString() << endl;
    inventory.removeDuplicates();
    output << "\nAfter removing duplicates:" << endl;
    output << inventory.toString() << endl;

    //! remove data -----------------------------

    //! result ----------------------------------
    return printResult(output.str(), expect, name);
}
