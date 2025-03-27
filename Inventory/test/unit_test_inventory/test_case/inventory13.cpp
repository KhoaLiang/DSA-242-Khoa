#include "../unit_test_inventory.hpp"

bool UNIT_TEST_inventory::inventory13()
{
    string name = "inventory13";
    //! data ------------------------------------
    InventoryAttribute attrA1("weight", 15);
    InventoryAttribute attrA2("height", 120);
    InventoryAttribute arrA[] = { attrA1, attrA2 };
    int numAttrA = sizeof(arrA) / sizeof(arrA[0]);
    List1D<InventoryAttribute> listAttrA(arrA, numAttrA);
 
    InventoryAttribute attrB1("weight", 25);
    InventoryAttribute attrB2("depth", 30);
    InventoryAttribute arrB[] = { attrB1, attrB2 };
    int numAttrB = sizeof(arrB) / sizeof(arrB[0]);
    List1D<InventoryAttribute> listAttrB(arrB, numAttrB);
 
    List1D<InventoryAttribute> attributesArray[2] = { listAttrA, listAttrB };
    List2D<InventoryAttribute> attributesMatrix(attributesArray, 2);
 
    string namesArray[] = { "Item A", "Item B" };
    List1D<string> productNames(namesArray, 2);
    
    int quantitiesArray[] = { 40, 25 };
    List1D<int> quantities(quantitiesArray, 2);
 
    InventoryManager inventory(attributesMatrix, productNames, quantities);
 
    string expect = "InventoryManager[\n\
  AttributesMatrix: [[weight: 15.000000, height: 120.000000], [weight: 25.000000, depth: 30.000000]],\n\
  ProductNames: [Item A, Item B],\n\
  Quantities: [40, 25]\n\
]\n\
Item A\n\
40\n\
[weight: 15.000000, height: 120.000000]\n\
Index is invalid!\n";
 
    stringstream output;
    output << inventory.toString() << endl;
    try
    {
        output << inventory.getProductName(0) << endl;
        output << inventory.getProductQuantity(0) << endl;
        output << inventory.getProductAttributes(0) << endl;
       
    }
    catch(const std::exception& e)
    {
        output << e.what() << '\n';
    }
    try
    {
        output << inventory.getProductName(3) << endl;
        output << inventory.getProductQuantity(3) << endl;
        output << inventory.getProductAttributes(3) << endl;
    }
    catch(const std::exception& e)
    {
        output << e.what() << '\n';
    }
 
    //! result ----------------------------------
    return printResult(output.str(), expect, name);
}
