#include "../unit_test_inventory.hpp"

bool UNIT_TEST_inventory::inventory21()
{
    string name = "inventory21";
   //! data ------------------------------------
   InventoryAttribute* attr1 = new InventoryAttribute("weight", 10);
   InventoryAttribute* attr2 = new InventoryAttribute("height", 150);
   InventoryAttribute* attr3 = new InventoryAttribute("height", 160);
   InventoryAttribute* attr4 = new InventoryAttribute("height", 170);
   InventoryAttribute* attr5 = new InventoryAttribute("height", 180);
   
   
InventoryAttribute* arrA = new InventoryAttribute[2]{*attr1, *attr2};
InventoryAttribute* arrB = new InventoryAttribute[2]{*attr1, *attr3};
InventoryAttribute* arrC = new InventoryAttribute[2]{*attr1, *attr4};
InventoryAttribute* arrD = new InventoryAttribute[2]{*attr1, *attr5};

List1D<InventoryAttribute>* listA = new List1D<InventoryAttribute>(arrA, 2);
List1D<InventoryAttribute>* listB = new List1D<InventoryAttribute>(arrB, 2);
List1D<InventoryAttribute>* listC = new List1D<InventoryAttribute>(arrC, 2);
List1D<InventoryAttribute>* listD = new List1D<InventoryAttribute>(arrD, 2);
   
List1D<InventoryAttribute>* lists = new List1D<InventoryAttribute>[17]{
   *listA, *listB, *listC, *listD,
   *listA, *listB, *listC, *listD,
   *listA, *listB, *listC, *listD,
   *listA, *listB, *listC, *listD,
   *listA
};

// Gọi constructor với con trỏ đầu tiên của mảng
List2D<InventoryAttribute>* attributesMatrix = new List2D<InventoryAttribute>(lists, 17);

   
   string productNamesArr[] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", 
                               "K", "L", "M", "N", "O", "P", "Q"};
   List1D<string>* productNames = new List1D<string>(productNamesArr, 17);
   
   int quantitiesArr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100,
                          110, 120, 130, 140, 150, 160, 170};
   List1D<int>* quantities = new List1D<int>(quantitiesArr, 17);
   
     InventoryManager* inv = new InventoryManager(*attributesMatrix, *productNames, *quantities);
     InventoryManager* inv1 = new InventoryManager(*inv);
     InventoryManager* inv2 = new InventoryManager(*inv);
     
   //! expect ----------------------------------
   string expect = "Index is invalid!\n\
Index is invalid!\n\
Index is invalid!\n\
InventoryManager[\n\
  AttributesMatrix: [[weight: 10.000000, height: 150.000000], [weight: 10.000000, height: 160.000000], [weight: 10.000000, height: 170.000000], [weight: 10.000000, height: 180.000000], [weight: 10.000000, height: 150.000000], [weight: 10.000000, height: 160.000000], [weight: 10.000000, height: 170.000000], [weight: 10.000000, height: 180.000000], [weight: 10.000000, height: 150.000000], [weight: 10.000000, height: 160.000000], [weight: 10.000000, height: 170.000000], [weight: 10.000000, height: 180.000000], [weight: 10.000000, height: 150.000000], [weight: 10.000000, height: 160.000000], [weight: 10.000000, height: 170.000000], [weight: 10.000000, height: 180.000000], [weight: 10.000000, height: 150.000000]],\n\
  ProductNames: [A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q],\n\
  Quantities: [10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150, 160, 170]\n\
]\n\
InventoryManager[\n\
  AttributesMatrix: [[weight: 10.000000, height: 160.000000], [weight: 10.000000, height: 180.000000], [weight: 10.000000, height: 160.000000], [weight: 10.000000, height: 170.000000], [weight: 10.000000, height: 180.000000], [weight: 10.000000, height: 150.000000], [weight: 10.000000, height: 160.000000], [weight: 10.000000, height: 170.000000], [weight: 10.000000, height: 180.000000], [weight: 10.000000, height: 150.000000], [weight: 10.000000, height: 170.000000], [weight: 10.000000, height: 180.000000], [weight: 10.000000, height: 150.000000]],\n\
  ProductNames: [B, D, F, G, H, I, J, K, L, M, O, P, Q],\n\
  Quantities: [20, 40, 60, 70, 80, 90, 100, 110, 120, 130, 150, 160, 170]\n\
]\n"; // Thay thế bằng output mong đợi thực tế
   
   //! output ----------------------------------
    std::stringstream output;
          
           inv->removeProduct(0);
           inv->removeProduct(1);
           inv->removeProduct(2);
           
           try
           {   
            inv->removeProduct(14);
           }
           catch(const std::exception& e)
           {
               output << e.what() << '\n';
           }
           
        inv->removeProduct(10);
  
     try
     {   
           inv->removeProduct(-1);
     }
     catch(const std::exception& e)
     {
         output << e.what() << '\n';
     }
     try
     {   
           inv->removeProduct(inv->size());
     }
     catch(const std::exception& e)
     {
         output << e.what() << '\n';
     }

     output<<inv1->toString()<<endl;
     output<<inv->toString()<<endl;
   
   

  
   
   //! cleanup ----------------------------------
   delete inv;
   delete inv1;
  delete inv2;
   delete attributesMatrix;
   delete productNames;
   delete quantities;

   // Giải phóng danh sách mảng con trỏ
   delete[] lists;

   // Giải phóng từng danh sách 1D
   delete listA;
   delete listB;
   delete listC;
   delete listD;

   // Giải phóng từng mảng InventoryAttribute
   delete[] arrA;
   delete[] arrB;
   delete[] arrC;
   delete[] arrD;

   // Giải phóng từng InventoryAttribute
   delete attr1;
   delete attr2;
   delete attr3;
   delete attr4;
   delete attr5;


    //! result ----------------------------------
    return printResult(output.str(), expect, name);
}
