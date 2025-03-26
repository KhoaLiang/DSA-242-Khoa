#include "../unit_test_List2D.hpp"

bool UNIT_TEST_List2D::List2D10()
{
    string name = "List2D10";
   
    List1D<int> row1;
   
    List1D<int> row2;
   
    List1D<int> *array = new List1D<int>[2];
    array[0].add(1); array[0].add(2);  array[0].add(3);
    array[1].add(4); array[1].add(5); array[1].add(6);
    stringstream output;
    List2D<int> original(array,2);
    
    try {
       output <<  original.getRow(2);
    } catch (const out_of_range &e) {
        output << e.what() << endl;
    }
    // Copy constructor
    List2D<int> *copy = new List2D(original);
    try {
       output <<  copy->getRow(2);
    } catch (const out_of_range &e) {
        output << e.what()<< " size : " <<copy->rows()<< endl;
    }
    //! expect ----------------------------------
    string expect = "Index is out of range!\n\
Index is out of range! size : 2\n\
[[1, 2, 3], [4, 5, 6]]";
    
    //! output ----------------------------------
    delete [] array;
    output << *copy;
    delete copy;
    //! remove data -----------------------------
   
    
    //! result ----------------------------------
    return printResult(output.str(), expect, name);
}
