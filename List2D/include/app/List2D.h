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

template <typename T>
class List2D
{
private:
    IList<IList<T> *> *pMatrix;

public:
    List2D();
    List2D(List1D<T> *array, int num_rows);
    List2D(const List2D<T> &other);
    virtual ~List2D();

    int rows() const;
    void setRow(int rowIndex, const List1D<T> &row);
    T get(int rowIndex, int colIndex) const;
    List1D<T> getRow(int rowIndex) const;
    string toString() const;
    template <typename U> //! thêm vào  để chạy test 
    friend ostream &operator<<(ostream &os, const List2D<T> &matrix);
};

// -------------------- List1D Method Definitions --------------------
template <typename T>
List1D<T>::List1D()
{
    // TODO
    pList = new XArrayList<T>();
}

template <typename T>
List1D<T>::List1D(int num_elements)
{
    // TODO
    pList = new XArrayList<T>();
    for (int i = 0; i < num_elements; i++)
    {
        pList->add(T());
    }
}

template <typename T>
List1D<T>::List1D(const T *array, int num_elements)
{
    // TODO
    pList = new XArrayList<T>();
    for (int i = 0; i < num_elements; i++)
    {
        pList->add(array[i]);
    }
}

template <typename T>
List1D<T>::List1D(const List1D<T> &other)
{
    // Use the copy constructor of XArrayList to copy the list
    pList = new XArrayList<T>(*dynamic_cast<XArrayList<T>*>(other.pList));
}

template <typename T>
List1D<T>::~List1D()
{
    // TODO
    delete pList;
}

template <typename T>
int List1D<T>::size() const
{
    // TODO
    return pList->size();
}

template <typename T>
T List1D<T>::get(int index) const
{
    // TODO

    return pList->get(index);
}

template <typename T>
void List1D<T>::set(int index, T value)
{
    
    
    // Remove the element at the specified index
    if(index < pList->size()){
        pList->removeAt(index);
        pList->add(index, value);
    }
    // Add the new value at the same index
    if (index == pList->size())
    {
        pList->add(value);
    }
    if (index > pList->size())
    {
        throw std::out_of_range("Index out of range!");
    }
}

template <typename T>
void List1D<T>::add(const T &value)
{
    // TODO
    pList->add(value);
}

template <typename T>
string List1D<T>::toString() const
{
    // Convert the 1D list to a string representation
    stringstream ss;
    ss << "[";
    for (int i = 0; i < pList->size(); i++)
    {
        ss << pList->get(i);
        if (i < pList->size() - 1)
        {
            ss << ", ";
        }
    }
    ss << "]";
    return ss.str();
}

template <typename T>
ostream &operator<<(ostream &os, const List1D<T> &list)
{
    os << list.toString();
    return os;
}



// -------------------- List2D Method Definitions --------------------
template <typename T>
List2D<T>::List2D()
{
    // Initialize an empty matrix using XArrayList to store rows
    pMatrix = new XArrayList<IList<T> *>();
}

template <typename T>
List2D<T>::List2D(List1D<T> *array, int num_rows)
{
    // Initialize the matrix and populate it with rows
    pMatrix = new XArrayList<IList<T> *>();
    for (int i = 0; i < num_rows; i++)
    {
        // Add each List1D<T> object from the array to the matrix
        pMatrix->add(dynamic_cast<IList<T> *>(new List1D<T>(array[i])));
    }
}

template <typename T>
List2D<T>::List2D(const List2D<T> &other)
{
    // Deep copy the matrix from the other List2D object
    pMatrix = new XArrayList<IList<T> *>();
    for (int i = 0; i < other.pMatrix->size(); i++)
    {
        pMatrix->add(dynamic_cast<IList<T> *>(new List1D<T>(*dynamic_cast<List1D<T> *>(other.pMatrix->get(i)))));
    }
}

template <typename T>
List2D<T>::~List2D()
{
    // Clean up all rows and the matrix itself
    for (int i = 0; i < pMatrix->size(); i++)
    {
        delete pMatrix->get(i);
    }
    delete pMatrix;
}

template <typename T>
int List2D<T>::rows() const
{
    // Return the number of rows in the matrix
    return pMatrix->size();
}

template <typename T>
void List2D<T>::setRow(int rowIndex, const List1D<T> &row)
{
    // Replace the row at the specified index with a copy of the provided row
    if (rowIndex < 0 || rowIndex >= pMatrix->size())
    {
        throw std::out_of_range("Row index out of range!");
    }
    delete pMatrix->get(rowIndex); // Delete the existing row
    pMatrix->removeAt(rowIndex);   // Remove the row from the list
    pMatrix->add(rowIndex, dynamic_cast<IList<T> *>(new List1D<T>(row)));
}

template <typename T>
T List2D<T>::get(int rowIndex, int colIndex) const
{
    // Retrieve the value at the specified row and column
    if (rowIndex < 0 || rowIndex >= pMatrix->size())
    {
        throw std::out_of_range("Row index out of range!");
    }
    List1D<T> *row = dynamic_cast<List1D<T> *>(pMatrix->get(rowIndex));
    if (colIndex < 0 || colIndex >= row->size())
    {
        throw std::out_of_range("Column index out of range!");
    }
    return row->get(colIndex);
}

template <typename T>
List1D<T> List2D<T>::getRow(int rowIndex) const
{
    // Return a copy of the row at the specified index
    if (rowIndex < 0 || rowIndex >= pMatrix->size())
    {
        throw std::out_of_range("Row index out of range!");
    }
    return *dynamic_cast<List1D<T> *>(pMatrix->get(rowIndex));
}

template <typename T>
string List2D<T>::toString() const
{
    // Convert the 2D matrix to a string representation
    stringstream ss;
    ss << "[";
    for (int i = 0; i < pMatrix->size(); i++)
    {
        List1D<T> *row = dynamic_cast<List1D<T> *>(pMatrix->get(i));
        ss << row->toString();
        if (i < pMatrix->size() - 1)
        {
            ss << ", ";
        }
    }
    ss << "]";
    return ss.str();
}

template <typename T>
ostream &operator<<(ostream &os, const List2D<T> &matrix)
{
    // Output the string representation of the matrix
    os << matrix.toString();
    return os;
}

#endif /* INVENTORY_MANAGER_H */
