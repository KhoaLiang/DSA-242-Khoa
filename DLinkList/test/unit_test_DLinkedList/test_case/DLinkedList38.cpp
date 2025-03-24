#include "../unit_test_DLinkedList.hpp"

bool UNIT_TEST_DLinkedList::DLinkedList38()
{
    string name = "DLinkedList38";
   
  //! expect
  string expect = "P(23.2, 25.4, 0.0)\n\
P(24.6, 23.1, 0.0)\n\
P(12.5, 22.3, 0.0)\n\
P(24.6, 23.1, 0.0)=> found;  indexOf returns: 1\n\
P(124.6, 23.1, 0.0)=> not found;  indexOf returns: -1\n\n\n\
P(23.2, 25.4, 0.0)\n\
P(24.6, 23.1, 0.0)\n\
P(12.5, 22.3, 0.0)\n\
P(24.6, 23.1, 0.0)=> not found;  indexOf returns: -1\n\
P(124.6, 23.1, 0.0)=> not found;  indexOf returns: -1\n";
  
    //! output
    stringstream output;
    DLinkedList<Point*> list1(&DLinkedList<Point*>::free, &Point::pointEQ);
      list1.add(new Point(23.2f, 25.4f));
      list1.add(new Point(24.6f, 23.1f));  
      list1.add(new Point(12.5f, 22.3f)); 
      
      for(DLinkedList<Point*>::Iterator it = list1.begin(); it != list1.end(); it++)
      output << **it << endl;
      
      Point* p1 = new Point(24.6f, 23.1f); //found in list
      Point* p2 = new Point(124.6f, 23.1f); //not found
      output << *p1 << "=> " << (list1.contains(p1)? "found; " : "not found; ")
                  << " indexOf returns: " << list1.indexOf(p1) << endl;
                  output << *p2 << "=> " << (list1.contains(p2)? "found; " : "not found; ")
                  << " indexOf returns: " << list1.indexOf(p2) << endl;
      
      ///Different results if not pass &Point::equals
      output << endl << endl;
      DLinkedList<Point*> list2(&DLinkedList<Point*>::free);
      list2.add(new Point(23.2f, 25.4f));
      list2.add(new Point(24.6f, 23.1f));  
      list2.add(new Point(12.5f, 22.3f)); 
      
      for(DLinkedList<Point*>::Iterator it = list2.begin(); it != list2.end(); it++)
      output << **it << endl;
      
          output << *p1 << "=> " << (list2.contains(p1)? "found; " : "not found; ")
                  << " indexOf returns: " << list2.indexOf(p1) << endl;
                  output << *p2 << "=> " << (list2.contains(p2)? "found; " : "not found; ")
                  << " indexOf returns: " << list2.indexOf(p2) << endl;
      
      delete p1; delete p2;
  
    //! print result
    return printResult(output.str(), expect, name);
}
