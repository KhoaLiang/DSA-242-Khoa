#include "../unit_test_inventory.hpp"

bool UNIT_TEST_inventory::inventory18()
{
    string name = "inventory18";
    //! data ------------------------------------
    InventoryAttribute attr1("weight", 10);
    InventoryAttribute attr2("height", 150);
    InventoryAttribute attr3("height", 160);
    InventoryAttribute attr4("height", 170);
    InventoryAttribute attr5("height", 180);
    
    InventoryAttribute arrA[] = {attr1, attr2};
    InventoryAttribute arrB[] = {attr1, attr3};
    InventoryAttribute arrC[] = {attr1, attr4};
    InventoryAttribute arrD[] = {attr1, attr5};
    
    List1D<InventoryAttribute> listA(arrA, 2);
    List1D<InventoryAttribute> listB(arrB, 2);
    List1D<InventoryAttribute> listC(arrC, 2);
    List1D<InventoryAttribute> listD(arrD, 2);
    
    List1D<InventoryAttribute> lists[] = {listA, listB, listC, listD,
                                          listA, listB, listC, listD,
                                          listA, listB, listC, listD,
                                          listA, listB, listC, listD,
                                          listA, listB, listC, listD};
    
    List2D<InventoryAttribute> attributesMatrix(lists, 20);
    
    string productNamesArr[] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", 
                                "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T"};
    List1D<string> productNames(productNamesArr, 20);
    
    int quantitiesArr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100,
                           110, 120, 130, 140, 150, 160, 170, 180, 190, 200};
    List1D<int> quantities(quantitiesArr, 20);
    
    InventoryManager inv(attributesMatrix, productNames, quantities);
    
    //! expect ----------------------------------
    string expect = "[]\n\
[A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T]\n\
[A, B]\n\
[C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T]\n\
[A, B, C, D]\n\
[E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T]\n\
[A, B, C, D, E, F]\n\
[G, H, I, J, K, L, M, N, O, P, Q, R, S, T]\n\
[A, B, C, D, E, F, G, H]\n\
[I, J, K, L, M, N, O, P, Q, R, S, T]\n\
[A, B, C, D, E, F, G, H, I, J]\n\
[K, L, M, N, O, P, Q, R, S, T]\n\
[A, B, C, D, E, F, G, H, I, J, K, L]\n\
[M, N, O, P, Q, R, S, T]\n\
[A, B, C, D, E, F, G, H, I, J, K, L, M, N]\n\
[O, P, Q, R, S, T]\n\
[A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P]\n\
[Q, R, S, T]\n\
[A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R]\n\
[S, T]\n\
[A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T]\n\
[]\n";
    
    //! output ----------------------------------
    
    std::stringstream output;
    InventoryManager s1;
    InventoryManager s2;
    for(double i = 0.0; i <= 1.0; i += 0.1) {
        
        inv.split(s1,s2,i);
        output<<s1.getProductNames()<<endl;
        output<<s2.getProductNames()<<endl;
    }
   
    return printResult(output.str(), expect, name);
}
