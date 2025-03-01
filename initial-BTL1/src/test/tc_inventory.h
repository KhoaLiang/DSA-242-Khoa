#include <iostream>
#include "app/inventory.h" 

using namespace std;

void tc_inventory1001() {
    int arr[] = {1, 2, 3, 4, 5};
    List1D<int> list1D(arr, 5);
    
    cout << list1D.toString() << endl;
}

void tc_inventory1002() {
    int row0[] = {1, 2, 3};
    int row1[] = {4, 5, 6};
    int row2[] = {7, 8, 9};
    const int* arr2D[] = { row0, row1, row2 };
    
    List2D<int> matrix(arr2D, 3, 3);
    
    cout << matrix.toString() << endl;
}

void tc_inventory1003() {
    int attrRow0[] = {10, 20};
    int attrRow1[] = {30, 40};
    const int* attrArr[] = { attrRow0, attrRow1 };
    List2D<int> attributesMatrix(attrArr, 2, 2);
    
    string namesArr[] = {"ProductA", "ProductB"};
    List1D<string> productNames(namesArr, 2);
    
    int qtyArr[] = {5, 10};
    List1D<int> quantities(qtyArr, 2);
    
    InventoryManager<int> inv(attributesMatrix, productNames, quantities);
    
    cout << inv.toString() << endl;
}

void tc_inventory1004() {
    int attrRow0[] = {1, 2};
    int attrRow1[] = {3, 4};
    const int* attrArr[] = { attrRow0, attrRow1 };
    List2D<int> matrix(attrArr, 2, 2);
    
    string namesArr[] = {"ProdX", "ProdY"};
    List1D<string> names(namesArr, 2);
    
    int qtyArr[] = {8, 12};
    List1D<int> quantities(qtyArr, 2);
    
    InventoryManager<int> inv1(matrix, names, quantities);
    
    InventoryManager<int> invCopy(inv1);
    invCopy.updateQuantity(0, 20);
    
    cout << inv1.getProductQuantity(0) << endl;
    cout << invCopy.getProductQuantity(0) << endl;
}

void tc_inventory1005() {
    int attrRow0[] = {5, 100};  
    int attrRow1[] = {10, 150};
    int attrRow2[] = {15, 200}; 
    const int* attrArr[] = { attrRow0, attrRow1, attrRow2 };
    List2D<int> matrix(attrArr, 3, 2);
    
    string namesArr[] = {"A", "B", "C"};
    List1D<string> names(namesArr, 3);
    
    int qtyArr[] = {3, 6, 9};
    List1D<int> quantities(qtyArr, 3);
    
    InventoryManager<int> inv(matrix, names, quantities);
    
    List1D<string> result = inv.query(0, 7, 16, 5, true);
    
    cout << result.toString() << endl;
}

