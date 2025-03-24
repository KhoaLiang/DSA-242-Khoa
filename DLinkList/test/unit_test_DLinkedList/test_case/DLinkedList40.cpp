#include "../unit_test_DLinkedList.hpp"
bool pointComparator(Point*& p1, Point*& p2){
  return (p1->getX() == p2->getX()) && (p1->getY() == p2->getY());
}
string LpointPtr2Str(Point*& ptr){
  stringstream os;
  os << "("   << ptr->getX() << ", " 
              << ptr->getY()
     << ")";
  return os.str();
}
bool UNIT_TEST_DLinkedList::DLinkedList40()
{
    string name = "DLinkedList40";
     //! data
  DLinkedList<Point*> dList(&DLinkedList<Point*>::free, &pointComparator);
  dList.add(new Point(1.5, 3.5));
  dList.add(new Point(2.5, 4.5));
  dList.add(new Point(1.6, 3.1));

  //! expect
  string expect = "[(1.5, 3.5), (2.5, 4.5), (1.6, 3.1)]\ntest for indexOf: \nP(1.6, 3.1, 0.0) at: 2\n";

  //! output
  stringstream output;
  output << dList.toString(&LpointPtr2Str) << endl;
  output << "test for indexOf: " << endl;
  Point* p = new Point(1.6, 3.1);
  output << *p << " at: " << dList.indexOf(p) << endl;

  delete p;

  //! print result
  return printResult(output.str(), expect, name);
}
