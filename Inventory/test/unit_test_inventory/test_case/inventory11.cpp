#include "../unit_test_inventory.hpp"

bool UNIT_TEST_inventory::inventory11()
{
    string name = "inventory11";
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
    string expect = "InventoryManager[\n\
  AttributesMatrix: [[weight: 10.000000, height: 156.000000], [weight: 20.000000, depth: 24.000000, height: 100.000000], [color: 2.000000], [color: 2.000000, weight: 10.000000]],\n\
  ProductNames: [Product A, Product B, Product C, Product D],\n\
  Quantities: [50, 30, 20, 10]\n\
]\n\
Product C\n\
Index is invalid!\n\
Index is invalid!\n";
 
    //! output ----------------------------------
    stringstream output;
    output << inventory.toString() << endl;
    try
    {
        output<< inventory.getProductName(2)<<endl;
    }
    catch(const std::exception& e)
    {
        output << e.what() << '\n';
    }
    try
    {
        output<< inventory.getProductName(4)<<endl;
    }
    catch(const std::exception& e)
    {
        output << e.what() << '\n';
    }
    
    try
    {
        output<< inventory.getProductName(-1)<<endl;
    }
    catch(const std::exception& e)
    {
        output << e.what() << '\n';
    }


    //! result ----------------------------------
    return printResult(output.str(), expect, name);
}
