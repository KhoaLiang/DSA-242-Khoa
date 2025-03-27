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
    List1D<T> &operator=(const List1D<T> &other); 
    int size() const;
    T get(int index) const;
    void set(int index, T value);
    void add(const T &value);

    //! thêm hàm này 
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
    List2D<T> &operator=(const List2D<T> &other);
    int rows() const;
    //! thêm hàm này 
    
    void setRow(int rowIndex, const List1D<T> &row);
    T get(int rowIndex, int colIndex) const;
    List1D<T> getRow(int rowIndex) const;
    string toString() const;
    template <typename U> //! thêm vào  để chạy test 
    friend ostream &operator<<(ostream &os, const List2D<T> &matrix);
};
struct InventoryAttribute
{
    string name;
    double value;
    //! thêm
    InventoryAttribute() : name(""), value(0.0) {}  // Constructor mặc định
    InventoryAttribute(const string &name, double value) : name(name), value(value) {}
    string toString() const { return name + ": " + to_string(value); }
     //! thêm
     // Định nghĩa toán tử so sánh ==
     bool operator==(const InventoryAttribute& other) const {
        return name == other.name && value == other.value;
    }
      // Toán tử in ra ostream
      friend std::ostream &operator<<(std::ostream &os, const InventoryAttribute &attr) {
        return os << attr.toString();
    }
};

// -------------------- InventoryManager --------------------
class InventoryManager
{
private:
    List2D<InventoryAttribute> attributesMatrix;
    List1D<string> productNames;
    List1D<int> quantities;

public:
    InventoryManager();
       
    
    InventoryManager(const List2D<InventoryAttribute> &matrix,
                     const List1D<string> &names,
                     const List1D<int> &quantities);
                     
                     
    InventoryManager(const InventoryManager &other);

    int size() const;
       
    
    List1D<InventoryAttribute> getProductAttributes(int index) const;
    string getProductName(int index) const;
    int getProductQuantity(int index) const;
    void updateQuantity(int index, int newQuantity);
    void addProduct(const List1D<InventoryAttribute> &attributes, const string &name, int quantity);
    void removeProduct(int index);

    List1D<string> query(string attributeName, const double &minValue,
                         const double &maxValue, int minQuantity, bool ascending) const;

    void removeDuplicates();

    static InventoryManager merge(const InventoryManager &inv1,
                                  const InventoryManager &inv2);

    void split(InventoryManager &section1,
               InventoryManager &section2,
               double ratio) const;

    List2D<InventoryAttribute> getAttributesMatrix() const;
    List1D<string> getProductNames() const;
    List1D<int> getQuantities() const;
    string toString() const;
};
// -------------------- List1D Method Definitions --------------------
template <typename T>
List1D<T>::List1D()
{
    // TODO
   
    // Sử dụng XArrayList làm danh sách nội bộ
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
List1D<T> &List1D<T>::operator=(const List1D<T> &other)
{
    
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

// -------------------- List2D Method Definitions --------------------
template <typename T>
List2D<T>::List2D()
{
    // TODO

}
template <typename T>
List2D<T> &List2D<T>::operator=(const List2D<T> &other)
{
}

template <typename T>
List2D<T>::List2D(List1D<T> *array, int num_rows)
{
    
}


template <typename T>
List2D<T>::List2D(const List2D<T> &other)
{
    // TODO

    
}

template <typename T>
List2D<T>::~List2D()
{
    // TODO
    
}

template <typename T>
int List2D<T>::rows() const
{
   
}

template <typename T>
void List2D<T>::setRow(int rowIndex, const List1D<T> &row)
{
    // TODO
    
   
}

template <typename T>
T List2D<T>::get(int rowIndex, int colIndex) const
{
    // TODO
   
}

template <typename T>
List1D<T> List2D<T>::getRow(int rowIndex) const
{
    // TODO
  
}

template <typename T>
string List2D<T>::toString() const
{
    // TODO
   
}

template <typename T>
ostream &operator<<(ostream &os, const List2D<T> &matrix)
{
    // TODO
   
}


#endif /* INVENTORY_MANAGER_H */
