void tc_inventory1004(){
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
    cout << "Here" << endl;
    cout << "\nAfter adding Product D:" << endl;
    cout << inventory.toString() << endl;
}
Here
After adding Product D:
------------------------
Product Names: [Product A, Product B, Product C, Product D]
InventoryManager[
  AttributesMatrix: [[weight: 10.000000, height: 156.000000], [weight: 20.000000, depth: 24.000000, height: 100.000000], [color: 2.000000], [weight: 15.000000, height: 140.000000]],
  ProductNames: [Product A, Product B, Product C, Product D],
  Quantities: [50, 30, 20, 40]
]
Here
After adding Product D:
InventoryManager[
  AttributesMatrix: [[weight: 10.000000, height: 156.000000], [weight: 20.000000, depth: 24.000000, height: 100.000000], [color: 2.000000], [weight: 15.000000, height: 140.000000]],
  ProductNames: [Product A, Product B, Product C, Product D],
  Quantities: [50, 30, 20, 40]
]
void tc_inventory1005(){
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

    List1D<string> queryResult = inventory.query(1, 10, 20, 30, true);
    cout << "\nQuery result (weight between 10 and 20, quantity >= 30):" << endl;
    cout << queryResult << endl;
}
Query result (weight between 10 and 20, quantity >= 30):
[Product A, Product B]
Query result (weight between 10 and 20, quantity >= 30):
[Product A, Product B]
void tc_inventory1006(){
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

    inventory.addProduct(listAttrA, "Product A", 20);
    cout << "\nAfter adding duplicate of Product A:" << endl;
    cout << inventory.toString() << endl;
    cout << "Removing duplicates..." << endl;
    inventory.removeDuplicates();
    cout << "\nAfter removing duplicates:" << endl;
    cout << inventory.size() << endl;
    cout << inventory.toString() << endl;
}
After adding duplicate of Product A:
------------------------
Product Names: [Product A, Product B, Product C, Product A]
InventoryManager[
  AttributesMatrix: [[weight: 10.000000, height: 156.000000], [weight: 20.000000, depth: 24.000000, height: 100.000000], [color: 2.000000], [weight: 10.000000, height: 156.000000]],
  ProductNames: [Product A, Product B, Product C, Product A],
  Quantities: [50, 30, 20, 20]
]
Removing duplicates...
After removing duplicates:
3
------------------------
Product Names: [Product A, Product B, Product C]
InventoryManager[
  AttributesMatrix: [[weight: 10.000000, height: 156.000000], [weight: 20.000000, depth: 24.000000, height: 100.000000], [color: 2.000000]],
  ProductNames: [Product A, Product B, Product C],
  Quantities: [70, 30, 20]
]
After adding duplicate of Product A:
InventoryManager[
  AttributesMatrix: [[weight: 10.000000, height: 156.000000], [weight: 20.000000, depth: 24.000000, height: 100.000000], [color: 2.000000], [weight: 10.000000, height: 156.000000]],
  ProductNames: [Product A, Product B, Product C, Product A],
  Quantities: [50, 30, 20, 20]
]
Removing duplicates...
After removing duplicates:
3
InventoryManager[
  AttributesMatrix: [[weight: 10.000000, height: 156.000000], [weight: 20.000000, depth: 24.000000, height: 100.000000], [color: 2.000000]],
  ProductNames: [Product A, Product B, Product C],
  Quantities: [70, 30, 20]
]


void tc_inventory1003() {
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

    cout << inventory.toString() << endl;
    cout << "Done" << endl;
}
------------------------
Product Names: [Product A, Product B, Product C]
InventoryManager[
  AttributesMatrix: [[weight: 10.000000, height: 156.000000], [weight: 20.000000, depth: 24.000000, height: 100.000000], [color: 2.000000]],
  ProductNames: [Product A, Product B, Product C],
  Quantities: [50, 30, 20]
]
Done
InventoryManager[
  AttributesMatrix: [[weight: 10.000000, height: 156.000000], [weight: 20.000000, depth: 24.000000, height: 100.000000], [color: 2.000000]],