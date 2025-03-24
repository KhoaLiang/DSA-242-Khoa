#include "../unit_test_DLinkedList.hpp"

bool UNIT_TEST_DLinkedList::DLinkedList03()
{
    string name = "DLinkedList03";
   //! data
   DLinkedList<int> list;
   list.add(0);
   list.add(1);
   list.add(2);
   list.add(3);
   list.add(4);
   list.add(5);
   list.add(6);
   list.add(7);
   list.add(8);
   list.add(9);
   list.add(10);
 
   //! expect
   string expect = "[0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10]\nsize=11\nempty=0";
 
   //! output
   string output = list.toString() + "\nsize=" + to_string(list.size()) +
                   "\nempty=" + to_string(list.empty());
 
   //! remove data
 
   //! print result
   return printResult(output, expect, name);
 }

