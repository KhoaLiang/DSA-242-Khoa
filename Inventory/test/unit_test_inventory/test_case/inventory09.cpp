#include "../unit_test_inventory.hpp"

bool UNIT_TEST_inventory::inventory09()
{
    string name = "inventory09";
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
 
    InventoryAttribute attrD1("weight", 10);
    InventoryAttribute arrD[] = { attrC1,attrD1 };
    int numAttrD = sizeof(arrD) / sizeof(arrD[0]);
    List1D<InventoryAttribute> listAttrD(arrD, numAttrD);
 
    List1D<InventoryAttribute> attributesArray[4] = { listAttrA, listAttrB, listAttrC ,listAttrD};
    List2D<InventoryAttribute> attributesMatrix(attributesArray, 4);
 
    string namesArray[] = { "Product A", "Product B", "Product C" ,"Product D"};
    List1D<string> productNames(namesArray, 4);
    
    int quantitiesArray[] = { 50, 30, 20 ,10};
    List1D<int> quantities(quantitiesArray, 4);
 
    InventoryManager inventory(attributesMatrix, productNames, quantities);
 
 
    //! expect ----------------------------------
    string expect = "\nAfter removeProduct index 1:\n\
InventoryManager[\n\
  AttributesMatrix: [[weight: 10.000000, height: 156.000000], [color: 2.000000], [color: 2.000000, weight: 10.000000]],\n\
  ProductNames: [Product A, Product C, Product D],\n\
  Quantities: [50, 20, 10]\n\
]\n\
Index is invalid!\n\
Index is invalid!\n";
 
    //! output ----------------------------------
    stringstream output;
    inventory.removeProduct(1);
    output << "\nAfter removeProduct index 1:" << endl;
    output << inventory.toString() << endl;
    
    try
    {
        inventory.removeProduct(4);
    }
    catch(const std::exception& e)
    {
        output << e.what() << '\n';
    }
    
    try
    {
        inventory.removeProduct(-1);
    }
    catch(const std::exception& e)
    {
        output << e.what() << '\n';
    }
    
     //! remove data -----------------------------

    //! result ----------------------------------
    return printResult(output.str(), expect, name);
}
