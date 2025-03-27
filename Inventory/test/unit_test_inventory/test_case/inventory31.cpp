#include "../unit_test_inventory.hpp"

bool UNIT_TEST_inventory::inventory31()
{
    string name = "inventory31";
     //! data ------------------------------------
     InventoryAttribute* attr2 = new InventoryAttribute("height", 150);
     InventoryAttribute* attr3 = new InventoryAttribute("height", 150);
     InventoryAttribute* attr4 = new InventoryAttribute("height", 150);
     InventoryAttribute* attr5 = new InventoryAttribute("height", 180);
     
     
 InventoryAttribute* arrA = new InventoryAttribute[1]{ *attr2};
 InventoryAttribute* arrB = new InventoryAttribute[1]{ *attr3};
 InventoryAttribute* arrC = new InventoryAttribute[1]{ *attr5};
 InventoryAttribute* arrD = new InventoryAttribute[1]{ *attr4};
 
 List1D<InventoryAttribute>* listA = new List1D<InventoryAttribute>(arrA, 1);
 List1D<InventoryAttribute>* listB = new List1D<InventoryAttribute>(arrB, 1);
 List1D<InventoryAttribute>* listC = new List1D<InventoryAttribute>(arrC, 1);
 List1D<InventoryAttribute>* listD = new List1D<InventoryAttribute>(arrD, 1);
     
 List1D<InventoryAttribute>* lists = new List1D<InventoryAttribute>[4]{
     *listA, *listB, *listC, *listD
 };
 
 // Gọi constructor với con trỏ đầu tiên của mảng
 List2D<InventoryAttribute>* attributesMatrix = new List2D<InventoryAttribute>(lists, 4);
 
     
     string productNamesArr[] = {"A", "B", "C", "D"};
     List1D<string>* productNames = new List1D<string>(productNamesArr, 4);
     
     int quantitiesArr[] = {10, 20, 30, 10};
     List1D<int>* quantities = new List1D<int>(quantitiesArr, 4);
     
       InventoryManager* inv = new InventoryManager(*attributesMatrix, *productNames, *quantities);
       
     //! expect ----------------------------------
     string expect = "True : [A, D, B, C]\n\
False : [C, B, D, A]\n"; // Thay thế bằng output mong đợi thực tế
     
     //! output ----------------------------------
     std::stringstream output;
        double mina = 5;
        double maxa = 200;
      output<< "True : " <<inv->query("height",mina,maxa,10,true)<<endl;
      output<< "False : " <<inv->query("height",mina,maxa,10,false)<<endl;
       
     
     
 
    
     
     //! cleanup ----------------------------------
     delete inv;
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
    
     delete attr2;
     delete attr3;
     delete attr4;
     delete attr5;
    //! result ----------------------------------
    return printResult(output.str(), expect, name);
}
