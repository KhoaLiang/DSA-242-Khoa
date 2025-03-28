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
    void removeAt(int index)
    {
        // Use the removeAt method from the underlying XArrayList
        pList->removeAt(index);
    }

    string toString() const;
    template <typename U> 
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
 
    
    void removeAt(int rowIndex)
    {
        // Check if the row index is out of range
        if (rowIndex < 0 || rowIndex >= rows())
        {
            throw out_of_range("Index is out of range!");
        }

        // Delete the row at the specified index
        delete pMatrix->get(rowIndex);

        // Remove the row from the matrix
        pMatrix->removeAt(rowIndex);
    }
    void setRow(int rowIndex, const List1D<T> &row);
    T get(int rowIndex, int colIndex) const;
    List1D<T> getRow(int rowIndex) const;
    string toString() const;
    template <typename U>
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
    pList = new XArrayList<T>();
    if(this != &other)
    {
        for(int i = 0; i < other.size(); i++)
        {
            this->pList->add(other.get(i));
        }
    }
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

template <typename T>
List1D<T> &List1D<T>::operator=(const List1D<T> &other)
{
    if (this != &other) // Avoid self-assignment
    {
        delete pList; // Clean up existing data
        pList = new XArrayList<T>(); // Allocate new memory
        for (int i = 0; i < other.size(); i++)
        {
            pList->add(other.get(i)); // Copy elements from the other list
        }
    }
    return *this; // Return the current object
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


//overload operator= for List2D
template <typename T>
List2D<T> &List2D<T>::operator=(const List2D<T> &other)
{
    if (this != &other) // Avoid self-assignment
    {
        // Clean up existing data
        for (int i = 0; i < pMatrix->size(); i++)
        {
            delete pMatrix->get(i);
        }
        delete pMatrix;

        // Allocate new memory
        pMatrix = new XArrayList<IList<T> *>();
        for (int i = 0; i < other.rows(); i++)
        {
            List1D<T> row = other.getRow(i);
            XArrayList<T> *newRow = new XArrayList<T>();
            for (int j = 0; j < row.size(); j++)
            {
                newRow->add(row.get(j)); // Copy elements from the other matrix
            }
            pMatrix->add(newRow);
        }
    }
    return *this; // Return the current object
}
// // -------------------- InventoryManager Method Definitions --------------------
InventoryManager::InventoryManager():attributesMatrix(), productNames(), quantities()
{
    // TODO
    
}

InventoryManager::InventoryManager(const List2D<InventoryAttribute> &matrix,
                                   const List1D<string> &names,
                                   const List1D<int> &quantities)
                                   : attributesMatrix(matrix), productNames(names), quantities(quantities)
{
    // TODO
}

InventoryManager::InventoryManager(const InventoryManager &other): attributesMatrix(other.attributesMatrix), productNames(other.productNames), quantities(other.quantities)
{
    // TODO
}

int InventoryManager::size() const
{
    // Return the number of rows in the attributesMatrix
    return attributesMatrix.rows();
}

List1D<InventoryAttribute> InventoryManager::getProductAttributes(int index) const
{
    // Check if the index is out of range
    if (index < 0 || index >= attributesMatrix.rows())
    {
        throw std::out_of_range("Index is invalid!");
    }

    // Return the attributes of the product at the given index
    return attributesMatrix.getRow(index);
}

string InventoryManager::getProductName(int index) const
{
    // Check if the index is out of range
    if (index < 0 || index >= productNames.size())
    {
        throw std::out_of_range("Index is invalid!");
    }

    // Return the name of the product at the given index
    return productNames.get(index);
}

int InventoryManager::getProductQuantity(int index) const
{
    // Check if the index is out of range
    if (index < 0 || index >= quantities.size())
    {
        throw std::out_of_range("Index is invalid!");
    }

    // Return the quantity of the product at the given index
    return quantities.get(index);
}

List2D<InventoryAttribute> InventoryManager::getAttributesMatrix() const
{
    // Return the entire attributes matrix
    return attributesMatrix;
}

List1D<string> InventoryManager::getProductNames() const
{
    // Return the list of product names
    return productNames;
}

List1D<int> InventoryManager::getQuantities() const
{
    // Return the list of product quantities
    return quantities;
}

void InventoryManager::updateQuantity(int index, int newQuantity)
{
    // TODO
    // Check if the index is out of range
    if (index < 0 || index >= quantities.size())
    {
        throw std::out_of_range("Index is invalid!");
    }

    // Update the quantity of the product at the given index
    quantities.set(index, newQuantity);
}

void InventoryManager::addProduct(const List1D<InventoryAttribute> &attributes, const string &name, int quantity)
{
    // Add the new product's attributes to the attributesMatrix
    attributesMatrix.setRow(attributesMatrix.rows(), attributes);

    // Add the product name to the productNames list
    productNames.add(name);

    // Add the product quantity to the quantities list
    quantities.add(quantity);
}

void InventoryManager::removeProduct(int index)
{
    // Check if the index is out of range
    if (index < 0 || index >= productNames.size())
    {
        throw std::out_of_range("Index is invalid!");
    }

    // Remove the product's attributes from the attributesMatrix
    attributesMatrix.removeAt(index);

    // Remove the product name from the productNames list
    productNames.removeAt(index);

    // Remove the product quantity from the quantities list
    quantities.removeAt(index);
}


//! tăng dần của cái gì
List1D<string> InventoryManager::query(string attributeName, const double &minValue,
                                       const double &maxValue, int minQuantity, bool ascending) const
{
    List1D<string> result;

    // Iterate through all products
    for (int i = 0; i < attributesMatrix.rows(); i++)
    {
        // Get the attributes of the current product
        List1D<InventoryAttribute> attributes = attributesMatrix.getRow(i);

        // Find the attribute with the specified name
        bool attributeFound = false;
        double attributeValue = 0.0;
        for (int j = 0; j < attributes.size(); j++)
        {
            if (attributes.get(j).name == attributeName)
            {
                attributeValue = attributes.get(j).value;
                attributeFound = true;
                break;
            }
        }

        // Skip if the attribute is not found
        if (!attributeFound)
        {
            continue;
        }

        // Check if the attribute value is within the range and the quantity is sufficient
        if (attributeValue >= minValue && attributeValue <= maxValue && quantities.get(i) >= minQuantity)
        {
            result.add(productNames.get(i)); // Add the product name to the result
        }
    }

    // Sort the result if ascending is true
    if (ascending)
    {
        // Simple bubble sort for demonstration purposes
        for (int i = 0; i < result.size() - 1; i++)
        {
            for (int j = 0; j < result.size() - i - 1; j++)
            {
                if (result.get(j) > result.get(j + 1))
                {
                    // Swap the elements
                    string temp = result.get(j);
                    result.set(j, result.get(j + 1));
                    result.set(j + 1, temp);
                }
            }
        }
    }

    return result;
}


void InventoryManager::removeDuplicates()
{
    for (int i = 0; i < productNames.size(); i++)
    {
        for (int j = i + 1; j < productNames.size(); j++)
        {
            // Check if the product names and attributes are the same
            if (productNames.get(i) == productNames.get(j) &&
                attributesMatrix.getRow(i).toString() == attributesMatrix.getRow(j).toString())
            {
                // Merge the quantities
                quantities.set(i, quantities.get(i) + quantities.get(j));

                // Remove the duplicate product
                attributesMatrix.removeAt(j);
                productNames.removeAt(j);
                quantities.removeAt(j);

                // Adjust the index to account for the removed element
                j--;
            }
        }
    }
}

//! Hàm này có gọi removeDuplicates hay không
InventoryManager InventoryManager::merge(const InventoryManager &inv1,
                                         const InventoryManager &inv2)
{
    // Create new lists to hold the merged data
    List2D<InventoryAttribute> mergedAttributesMatrix;
    List1D<string> mergedProductNames;
    List1D<int> mergedQuantities;

    // Add all products from inv1 to the merged inventory
    for (int i = 0; i < inv1.size(); i++)
    {
        mergedAttributesMatrix.setRow(mergedAttributesMatrix.rows(), inv1.getProductAttributes(i));
        mergedProductNames.add(inv1.getProductName(i));
        mergedQuantities.add(inv1.getProductQuantity(i));
    }

    // Add all products from inv2 to the merged inventory
    for (int i = 0; i < inv2.size(); i++)
    {
        mergedAttributesMatrix.setRow(mergedAttributesMatrix.rows(), inv2.getProductAttributes(i));
        mergedProductNames.add(inv2.getProductName(i));
        mergedQuantities.add(inv2.getProductQuantity(i));
    }

    // Create the merged inventory
    InventoryManager mergedInventory(mergedAttributesMatrix, mergedProductNames, mergedQuantities);

    // Remove duplicates from the merged inventory
    mergedInventory.removeDuplicates();

    return mergedInventory;
}

void InventoryManager::split(InventoryManager &section1,
                             InventoryManager &section2,
                             double ratio) const
{
    int totalProducts = attributesMatrix.rows();
    int section1Size = (totalProducts * ratio) - static_cast<int>(totalProducts * ratio) > 0
                           ? static_cast<int>(totalProducts * ratio) + 1
                           : static_cast<int>(totalProducts * ratio);
    int section2Size = totalProducts - section1Size;

    // Add products to section1
    for (int i = 0; i < section1Size; i++)
    {
        section1.addProduct(attributesMatrix.getRow(i), productNames.get(i), quantities.get(i));
    }

    // Add products to section2
    for (int i = section1Size; i < totalProducts; i++)
    {
        section2.addProduct(attributesMatrix.getRow(i), productNames.get(i), quantities.get(i));
    }
}



string InventoryManager::toString() const
{
    stringstream ss;
    ss << "InventoryManager[\n";
    ss << "  AttributesMatrix: " << attributesMatrix.toString() << ",\n";
    ss << "  ProductNames: " << productNames.toString() << ",\n";
    ss << "  Quantities: " << quantities.toString() << "\n";
    ss << "]";
    return ss.str();
}
#endif /* INVENTORY_MANAGER_H */
