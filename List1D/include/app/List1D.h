#ifndef INVENTORY_MANAGER_H
#define INVENTORY_MANAGER_H

#include "list/XArrayList.h"
#include "list/DLinkedList.h"
#include <sstream>
#include <string>
#include <iostream>
#include <iomanip>
#include <stdexcept>

using namespace std;

// -------------------- List1D --------------------
template <typename T>
class List1D
{
private:
    IList<T> *pList;

public:
    List1D();
    List1D(int num_elements);
    List1D(const T *array, int num_elements);
    List1D(const List1D<T> &other);
    virtual ~List1D();

    int size() const;
    T get(int index) const;
    void set(int index, T value);
    void add(const T &value);
    string toString() const;
    template <typename U> //! thêm vào  để chạy test 
    friend ostream &operator<<(ostream &os, const List1D<T> &list);
};



// -------------------- List1D Method Definitions --------------------
template <typename T>
List1D<T>::List1D()
{
    // TODO
    
}

template <typename T>
List1D<T>::List1D(int num_elements)
{
    // TODO
  
}

template <typename T>
List1D<T>::List1D(const T *array, int num_elements)
{
    // TODO
  
}

template <typename T>
List1D<T>::List1D(const List1D<T> &other)
{
    // TODO
   

}

template <typename T>
List1D<T>::~List1D()
{
    // TODO
   
}

template <typename T>
int List1D<T>::size() const
{
    // TODO
   
}

template <typename T>
T List1D<T>::get(int index) const
{
    // TODO

    
}

template <typename T>
void List1D<T>::set(int index, T value)
{
    // TODO

    
}

template <typename T>
void List1D<T>::add(const T &value)
{
    // TODO
    
}

template <typename T>
string List1D<T>::toString() const
{
    // TODO
   
    
}

template <typename T>
ostream &operator<<(ostream &os, const List1D<T> &list)
{
   
}




#endif /* INVENTORY_MANAGER_H */
