#include "../unit_test_inventory.hpp"

bool UNIT_TEST_inventory::inventory32()
{
    string name = "inventory32";
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
    
    int quantitiesArr[] = {10, 10, 30, 10};
    List1D<int>* quantities = new List1D<int>(quantitiesArr, 4);
    
     


    //! expect ----------------------------------
    string expect = "ratio : 0.15\n\
s1 : [A, B, C]\n\
ratio : [D, A, B, C, D, A, B, C, D, A, B, C, D]\n\
ratio : 0.3\n\
s1 : [A, B, C, D, A]\n\
ratio : [B, C, D, A, B, C, D, A, B, C, D]\n\
ratio : 0.45\n\
s1 : [A, B, C, D, A, B, C, D]\n\
ratio : [A, B, C, D, A, B, C, D]\n\
ratio : 0.6\n\
s1 : [A, B, C, D, A, B, C, D, A, B]\n\
ratio : [C, D, A, B, C, D]\n\
ratio : 0.75\n\
s1 : [A, B, C, D, A, B, C, D, A, B, C, D]\n\
ratio : [A, B, C, D]\n\
ratio : 0.9\n\
s1 : [A, B, C, D, A, B, C, D, A, B, C, D, A, B, C]\n\
ratio : [D]\n\
True : [A, B, D, A, B, D, A, B, D, A, B, D, C, C, C, C]\n\
False : [C, C, C, C, D, B, A, D, B, A, D, B, A, D, B, A]\n\
InventoryManager[\n\
  AttributesMatrix: [[height: 150.000000], [height: 150.000000], [height: 180.000000], [height: 150.000000]],\n\
  ProductNames: [A, B, C, D],\n\
  Quantities: [40, 40, 120, 40]\n\
]\n"; // Thay thế bằng output mong đợi thực tế
    
    //! output ----------------------------------
    std::stringstream output;
    InventoryManager* inv = new InventoryManager(*attributesMatrix, *productNames, *quantities);
    InventoryManager inv1 =  InventoryManager::merge(*inv,*inv);
    InventoryManager inv2 =  InventoryManager::merge(inv1,inv1);
    InventoryManager s1 ;
    InventoryManager s2;
    for(double i = 0.15 ; i <= 1 ; i = i + 0.15){
        inv2.split(s1,s2,i);
        output<<"ratio : "<<i<<endl;
        output<<"s1 : "<<s1.getProductNames()<<endl;
        output<<"ratio : "<<s2.getProductNames()<<endl;
    }
    
       double mina = 5;
       double maxa = 200;
     output<< "True : " <<inv2.query("height",mina,maxa,10,true)<<endl;
     output<< "False : " <<inv2.query("height",mina,maxa,10,false)<<endl;
     inv2.removeDuplicates();
     output<<inv2.toString()<<endl;
    
    

   
    
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
