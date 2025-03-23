/*
 * File:   XArrayList.h
 */

#ifndef XARRAYLIST_H
#define XARRAYLIST_H
#include "list/IList.h"
#include <memory.h>
#include <sstream>
#include <iostream>
#include <type_traits>
using namespace std;

template <class T>
class XArrayList : public IList<T>
{
public:
    class Iterator; // forward declaration

protected:
    T *data;                                 // dynamic array to store the list's items
    int capacity;                            // size of the dynamic array
    int count;                               // number of items stored in the array
    bool (*itemEqual)(T &lhs, T &rhs);       // function pointer: test if two items (type: T&) are equal or not
    void (*deleteUserData)(XArrayList<T> *); // function pointer: be called to remove items (if they are pointer type)

public:
    // XArrayList();    
    XArrayList(
        void (*deleteUserData)(XArrayList<T> *) = 0,
        bool (*itemEqual)(T &, T &) = 0,
        int capacity = 10);
    XArrayList(const XArrayList<T> &list);
    XArrayList<T> &operator=(const XArrayList<T> &list);
    ~XArrayList();

    // Inherit from IList: BEGIN
    void add(T e);
    void add(int index, T e);
    T removeAt(int index);
    bool removeItem(T item, void (*removeItemData)(T) = 0);
    bool empty();
    int size();
    void clear();
    T &get(int index);
    int indexOf(T item);
    bool contains(T item);
    string toString(string (*item2str)(T &) = 0);
    // Inherit from IList: BEGIN

    void println(string (*item2str)(T &) = 0)
    {
        cout << toString(item2str) << endl;
    }
    void setDeleteUserDataPtr(void (*deleteUserData)(XArrayList<T> *) = 0)
    {
        this->deleteUserData = deleteUserData;
    }

    Iterator begin()
    {
        return Iterator(this, 0);
    }
    Iterator end()
    {
        return Iterator(this, count);
    }

    /** free:
     * if T is pointer type:
     *     pass THE address of method "free" to XArrayList<T>'s constructor:
     *     to:  remove the user's data (if needed)
     * Example:
     *  XArrayList<Point*> list(&XArrayList<Point*>::free);
     *  => Destructor will call free via function pointer "deleteUserData"
     */
    static void free(XArrayList<T> *list)
    {
        typename XArrayList<T>::Iterator it = list->begin();
        while (it != list->end())
        {
            delete *it;
            it++;
        }
    }

protected:
    void checkIndex(int index);     // check validity of index for accessing
    void ensureCapacity(int index); // auto-allocate if needed

    /** equals:
     * if T: primitive type:
     *      indexOf, contains: will use native operator ==
     *      to: compare two items of T type
     * if T: object type:
     *      indexOf, contains: will use native operator ==
     *      to: compare two items of T type
     *      Therefore, class of type T MUST override operator ==
     * if T: pointer type:
     *      indexOf, contains: will use function pointer "itemEqual"
     *      to: compare two items of T type
     *      Therefore:
     *      (1): must pass itemEqual to the constructor of XArrayList
     *      (2): must define a method for comparing
     *           the content pointed by two pointers of type T
     *          See: definition of "equals" of class Point for more detail
     */
    static bool equals(T &lhs, T &rhs, bool (*itemEqual)(T &, T &))
    {
        if (itemEqual == 0)
            return lhs == rhs;
        else
            return itemEqual(lhs, rhs);
    }

    void copyFrom(const XArrayList<T> &list);

    void removeInternalData();

    //////////////////////////////////////////////////////////////////////
    ////////////////////////  INNER CLASSES DEFNITION ////////////////////
    //////////////////////////////////////////////////////////////////////
public:
    // Iterator: BEGIN
    class Iterator
    {
    private:
        int cursor;
        XArrayList<T> *pList;

    public:
        Iterator(XArrayList<T> *pList = 0, int index = 0)
        {
            this->pList = pList;
            this->cursor = index;
        }
        Iterator &operator=(const Iterator &iterator)
        {
            cursor = iterator.cursor;
            pList = iterator.pList;
            return *this;
        }
        void remove(void (*removeItemData)(T) = 0)
        {
            T item = pList->removeAt(cursor);
            if (removeItemData != 0)
                removeItemData(item);
            cursor -= 1; // MUST keep index of previous, for ++ later
        }

        T &operator*()
        {
            return pList->data[cursor];
        }
        bool operator!=(const Iterator &iterator)
        {
            return cursor != iterator.cursor;
        }
        // Prefix ++ overload
        Iterator &operator++()
        {
            this->cursor++;
            return *this;
        }
        // Postfix ++ overload
        Iterator operator++(int)
        {
            Iterator iterator = *this;
            ++*this;
            return iterator;
        }
    };
    // Iterator: END
};

//////////////////////////////////////////////////////////////////////
////////////////////////     METHOD DEFNITION      ///////////////////
//////////////////////////////////////////////////////////////////////
// //user added default constructor
// template <class T>
// XArrayList<T>::XArrayList()
// {
//     this->capacity = 10; // Default capacity
//     this->count = 0;
//     this->deleteUserData = nullptr;
//     this->itemEqual = nullptr;

//     try
//     {
//         this->data = new T[this->capacity];
//     }
//     catch (const std::bad_alloc &e)
//     {
//         std::cerr << "Memory allocation failed: " << e.what() << '\n';
//         throw; // Re-throw the exception to indicate failure
//     }
// }

template <class T>
XArrayList<T>::XArrayList(
    void (*deleteUserData)(XArrayList<T> *),
    bool (*itemEqual)(T &, T &),
    int capacity)
{
    // TODO
    // // Step 1: Initialize Member Variables
    // this.capacity = capacity
    // this.count = 0
    // this.deleteUserData = deleteUserData
    // this.itemEqual = itemEqual

    // // Step 2: Allocate Memory for the Dynamic Array
    // try
    //     this.data = allocate memory for an array of size this.capacity
    // catch memory allocation failure
    //     handle the exception (e.g., throw an exception or handle the error)
    this->capacity = capacity;
    this->count = 0;
    this->deleteUserData = deleteUserData;
    this->itemEqual = itemEqual;

    try
    {
        this->data = new T[this->capacity];
    }
    catch (const std::bad_alloc &e)
    {
        std::cerr << "Memory allocation failed: " << e.what() << '\n';
        throw; // Re-throw the exception to indicate failure
    }
}

template <class T>
void XArrayList<T>::copyFrom(const XArrayList<T> &list)
{
    /*
     * Copies the contents of another XArrayList into this list.
     * Initializes the list with the same capacity as the source list and copies all elements.
     * Also duplicates user-defined comparison and deletion functions, if applicable.
     */
    // TODO
}

template <class T>
void XArrayList<T>::removeInternalData()
{
    /*
     * Clears the internal data of the list by deleting the dynamic array and any user-defined data.
     * If a custom deletion function is provided, it is used to free the stored elements.
     * Finally, the dynamic array itself is deallocated from memory.
     */
    // TODO
}

template <class T>
XArrayList<T>::XArrayList(const XArrayList<T> &list)
{
    // TODO
    // Step 1: Initialize Member Variables
    this->capacity = list.capacity;
    this->count = list.count;
    this->deleteUserData = list.deleteUserData;
    this->itemEqual = list.itemEqual;

    // Step 2: Allocate Memory for the Dynamic Array
    try
    {
        this->data = new T[this->capacity];
    }
    catch (const std::bad_alloc &e)
    {
        std::cerr << "Memory allocation failed: " << e.what() << '\n';
        throw; // Re-throw the exception to indicate failure
    }

    // Step 3: Copy Elements from the Source List
    for (int i = 0; i < count; i++)
    {
        this->data[i] = list.data[i];
    }
}

template <class T>
XArrayList<T> &XArrayList<T>::operator=(const XArrayList<T> &list)
{
    // TODO
    if (this != &list) // Check for self-assignment
    {
        this->capacity = list.capacity;
        this->count = list.count;
        this->deleteUserData = list.deleteUserData;
        this->itemEqual = list.itemEqual;
        T* new_data = nullptr;
        try
        {
            new_data = new T[this->capacity];
        }
        catch (const std::bad_alloc &e)
        {
            std::cerr << "Memory allocation failed: " << e.what() << '\n';
            throw; // Re-throw the exception to indicate failure
        }
        for (int i = 0; i < count; i++)
        {
            new_data[i] = list.data[i];
        }
        delete[] data;
        data = new_data;
    }
    return *this;
}

template <class T>
XArrayList<T>::~XArrayList()
{
    // TODO
}

template <class T>
void XArrayList<T>::add(T e)
{
    // TODO
    if (count == capacity)
    {
        /* code */
        ensureCapacity(capacity);
    }
    data[count] = e;
    count++;
}

template <class T>
void XArrayList<T>::add(int index, T e)
{
    // TODO
    checkIndex(index);
    if (count == capacity)
    {
        ensureCapacity(capacity);
    }
    for (int i = count; i > index; i--) {
        data[i] = data[i - 1];
    }
    data[index] = e;
    count++;
}

template <class T>
T XArrayList<T>::removeAt(int index)
{
    // TODO
    checkIndex(index);
    if (index == count)
    {
        throw std::out_of_range("Index is out of range!");
    }
    T storedAtIndex = data[index];
    for (int i = index; i < count - 1; i++)
    {
        data[i] = data[i + 1];
    }
    count -= 1;
    return storedAtIndex;
}

template <class T>
bool XArrayList<T>::removeItem(T item, void (*removeItemData)(T))
{
    // TODO
    int index = indexOf(item);
    if (index != -1)
    {
        T removedItem = removeAt(index);
        if (removeItemData != nullptr)
        {
            removeItemData(removedItem);
        }
        return true;
    }
    return false;
}

template <class T>
bool XArrayList<T>::empty()
{
    // TODO
    if (count != 0)
    {
        return false;
    }
    return true;
}

template <class T>
int XArrayList<T>::size()
{
    // TODO
    return count;
}

template <class T>
void XArrayList<T>::clear()
{
    // TODO
    if (data != nullptr) {
        delete[] data;
    }
    this->capacity = 10;
    this->count = 0;
    this->deleteUserData = nullptr;
    this->itemEqual = nullptr;
    try
    {
        this->data = new T[this->capacity];
    }
    catch (const std::bad_alloc &e)
    {
        std::cerr << "Memory allocation failed: " << e.what() << '\n';
        throw; // Re-throw the exception to indicate failure
    }
}

template <class T>
T &XArrayList<T>::get(int index)
{
    // TODO
    checkIndex(index);
    if (empty() == true && index == 0)
    {
        throw std::out_of_range("Index is out of range!");
    }
    return data[index];
}

template <class T>
int XArrayList<T>::indexOf(T item)
{
    // TODO
    for (int i = 0; i < count; i++)
    {
        if (data[i] == item)
        {
            return i;
        }
    }
    return -1;
}
template <class T>
bool XArrayList<T>::contains(T item)
{
    for (int i = 0; i < count; i++)
    {
        if (data[i] == item)
        {
            return true;
        }
    }
    return false;
}

template <class T>
string XArrayList<T>::toString(string (*item2str)(T &))
{
    /**
     * Converts the array list into a string representation, formatting each element using a user-defined function.
     * If no function is provided, it uses the default string representation for each element.
     * Example: Given an array list with elements {1, 2, 3} and a function that converts integers to strings, calling toString would return "[1, 2, 3]".
     *
     * @param item2str A function pointer for converting items of type T to strings. If null, default to the string conversion of T.
     * @return A string representation of the array list with elements separated by commas and enclosed in square brackets.
     */

    // TODO
    // // Step 1: Initialize an Empty String
    // result = "["
    string result = "[";

    // // Step 2: Iterate Over the Elements
    // for i from 0 to count - 1 do
    //     // Step 3: Convert Each Element to String
    //     if item2str is not null then
    //         elementStr = item2str(data[i])
    //     else
    //         elementStr = default string conversion of data[i]

    //     // Step 4: Append Element to Result
    //     result = result + elementStr
    //     if i is not the last element then
    //         result = result + ", "

    // // Step 5: Add Closing Bracket
    // result = result + "]"

    // // Step 6: Return the Result
    // return result
    for (int i = 0; i < count; i++)
    {
        /* code */
        string eleStr;
        if (item2str != nullptr)
        {
            eleStr = item2str(data[i]);
        }
        else
        {
            stringstream ss;
            ss << data[i];
            eleStr = ss.str();
        }
        result += eleStr;

        if (i < (count - 1))
        {
            result += ", ";
        }
    }
    result = result + "]";
    return result;
}

//////////////////////////////////////////////////////////////////////
//////////////////////// (private) METHOD DEFNITION //////////////////
//////////////////////////////////////////////////////////////////////
template <class T>
void XArrayList<T>::checkIndex(int index)
{
    /**
     * Validates whether the given index is within the valid range of the list.
     * Throws an std::out_of_range exception if the index is negative or exceeds the number of elements.
     * Ensures safe access to the list's elements by preventing invalid index operations.
     */
    // TODO
    if (index < 0 || index > count)
    {
        throw std::out_of_range("Index is out of range!");
    }
}
template <class T>
void XArrayList<T>::ensureCapacity(int index)
{
    /**
     * Ensures that the list has enough capacity to accommodate the given index.
     * If the index exceeds the current capacity, reallocates the internal array with increased capacity,
     * copying the existing elements to the new array. In case of memory allocation failure, catches std::bad_alloc.
     */
    if (index >= capacity)
    {
        int new_capacity = static_cast<int>(capacity * 1.5);
        T* new_data = nullptr;

        try
        {
            new_data = new T[new_capacity];
        }
        catch (const std::bad_alloc& e)
        {
            std::cerr << "Memory allocation failed: " << e.what() << '\n';
            throw; // Re-throw the exception to indicate failure
        }

        for (int i = 0; i < capacity; i++)
        {
            new_data[i] = data[i];
        }
        delete[] data;
        data = new_data;
        capacity = new_capacity;
    }
}

#endif /* XARRAYLIST_H */
