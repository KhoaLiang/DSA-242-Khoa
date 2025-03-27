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
    // TODO
    pMatrix = new XArrayList<IList<T> *>();
}

template <typename T>
List2D<T>::List2D(List1D<T> *array, int num_rows)
{
    // Initialize pMatrix as a new XArrayList of IList<T>* pointers
    pMatrix = new XArrayList<IList<T> *>();
    
    // Iterate through the number of rows
    for (int i = 0; i < num_rows; i++)
    {
        // Create a new row as an XArrayList<T>
        XArrayList<T>* newRow = new XArrayList<T>();
        
        // Copy elements from the given List1D array into the new row
        for (int j = 0; j < array[i].size(); j++)
        {
            newRow->add(array[i].get(j)); // Add each element to the new row
        }
        
        // Add the new row to the pMatrix
        pMatrix->add(newRow);
    }
}


template <typename T>
List2D<T>::List2D(const List2D<T> &other)
{
    // TODO
    pMatrix = new XArrayList<IList<T> *>();
    for (int i = 0; i < other.rows(); i++)
    {
        List1D<T> row = other.getRow(i);
        pMatrix->add(new XArrayList<T>());
        for (int j = 0; j < row.size(); j++)
        {
            pMatrix->get(i)->add(row.get(j));
        }
    }
}

template <typename T>
List2D<T>::~List2D()
{
    // TODO
    for (int i = 0; i < pMatrix->size(); i++)
    {
        delete pMatrix->get(i);
    }
    delete pMatrix;
}

template <typename T>
int List2D<T>::rows() const
{
    return pMatrix->size();
}

template <typename T>
void List2D<T>::setRow(int rowIndex, const List1D<T> &row)
{
    // Check if the row index is out of range
    if (rowIndex < 0 || rowIndex > pMatrix->size())
    {
        throw out_of_range("Index is out of range!");
    }

    // If the row already exists, delete and replace it
    if (rowIndex < pMatrix->size())
    {
        delete pMatrix->get(rowIndex);
        pMatrix->removeAt(rowIndex);
    }

    // Create a new row and add data
    XArrayList<T>* newRow = new XArrayList<T>();
    for (int i = 0; i < row.size(); i++)
    {
        newRow->add(row.get(i));
    }

    // Add the new row to the matrix
    pMatrix->add(rowIndex, newRow);
}

template <typename T>
T List2D<T>::get(int rowIndex, int colIndex) const
{
    // TODO
    if (rowIndex < 0 || rowIndex >= rows() || 
        colIndex < 0 || colIndex >= pMatrix->get(rowIndex)->size())
    {
        throw out_of_range("Index is out of range!");
    }
    return pMatrix->get(rowIndex)->get(colIndex);
}

template <typename T>
List1D<T> List2D<T>::getRow(int rowIndex) const
{
    // TODO
    if (rowIndex < 0 || rowIndex >= rows()) {
        throw out_of_range("Index is out of range!");
    }

    List1D<T> row;
    for (int i = 0; i < pMatrix->get(rowIndex)->size(); i++)
    {
        row.add(pMatrix->get(rowIndex)->get(i));
    }
    return row;
}

template <typename T>
string List2D<T>::toString() const
{
    // Convert the 2D list to a string representation
    stringstream ss;
    ss << "[";  // Start the result string

    for (int i = 0; i < rows(); i++)
    {
        ss << getRow(i).toString();  // Call toString() for each row

        if (i < rows() - 1)
        {
            ss << ", ";  // Add a comma if it's not the last row
        }
    }

    ss << "]";  // End the result string
    return ss.str();
}


template <typename T>
ostream &operator<<(ostream &os, const List2D<T> &matrix)
{
    // TODO
    os << matrix.toString();
    return os;
}

#endif /* INVENTORY_MANAGER_H */
