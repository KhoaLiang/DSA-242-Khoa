#include <string>
#include <memory.h>
#include <sstream>
#include <iostream>
#include <type_traits>
#include <cmath>
#include <iomanip>
using namespace std;

template<class T>
class IList{
public:
    virtual ~IList(){};
    /* add(T e): append item "e" to the list
     */
    virtual void    add(T e)=0;
    
    
    
    /* add(int index, T e): insert item "e" at location "index";
     *      location is an integer started from 0
     */
    virtual void    add(int index, T e)=0;
    
    
    
    /* removeAt(int index): remove the item at location "index"
     * 
     * return:
     *  >> the item stored at index
     *  >> throw an exception (std::out_of_range) if index is invalid
     */
    virtual T       removeAt(int index)=0;
    
    
    /* removeItem(T item, void (*removeItemData)(T)=0): remove item stored in the list
     *   >> removeItemData: a function pointer (maybe NULL, default),
     *          that will be called inside of removeItem to delete the item's data stored in the list
     *   >> removeItemData, why need? because we DO NOT type T is a pointer or not.
     * 
     * return:
     *   >> true if "item" stored in the list; 
     *   >> otherwise, return false
     */
    virtual bool    removeItem(T item, void (*removeItemData)(T)=0)=0;
    
    
    
    /* empty(): return true if the list is empty; otherwise, return false
     */
    virtual bool    empty()=0;
    
    
    
    /* size(): return number of items stored in the list
     */
    virtual int     size()=0;
    
    
    
    /* clear(): make the list empty by clearing all data and putting the list to the initial condition
     */
    virtual void    clear()=0;
    
    
    
    /* get(int index): return a reference to the item at location "index"
     *      if index is invalid, this function will throw an exception "std::out_of_range"
     * 
     * NOTE: programmers can change the item returned by this function
     */
    virtual T&      get(int index)=0;
    
    
    /* indexOf(T item): return the index of item
     *      if item is not found, then return -1
     */
    virtual int     indexOf(T item)=0;
    
    
    
    /* contains(T item): return true if the list contains "item", else: return false
     */
    virtual bool    contains(T item)=0;
    
    
    
    /* toString(string (*item2str)(T&)=0 ): return a string describing the list.
     *    >> We do not know the item type, so we do not know how to convert each item to string.
     *       Therefore, we need a pointer to a function
     *          that can convert the item (passed to that function) to a string
     */
    virtual string  toString(string (*item2str)(T&)=0 )=0;
};






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
void XArrayList<T>::removeInternalData()
{
    /*
     * Clears the internal data of the list by deleting the dynamic array and any user-defined data.
     * If a custom deletion function is provided, it is used to free the stored elements.
     * Finally, the dynamic array itself is deallocated from memory.
     */
    // TODO
    if (deleteUserData != nullptr)
    {
        deleteUserData(this);
    }
    delete[] data;
    data = nullptr;
    count = 0;
    capacity = 0;
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
    // If a custom deletion function is provided, call it
    if (deleteUserData != nullptr)
    {
        deleteUserData(this);
    }
    // Delete the dynamically allocated array
    delete[] data;
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
    for (int i = 0; i < count; i++)
    {
        if (itemEqual != nullptr)
        {
            if (itemEqual(data[i], item))
            {
                return i;
            }
        }
        else
        {
            if (data[i] == item)
            {
                return i;
            }
        }
    }
    return -1;
}

template <class T>
bool XArrayList<T>::contains(T item)
{
    return indexOf(item) != -1;
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


class Point
{
private:
    float x, y, z;
    friend ostream &operator<<(ostream &os, const Point &point);

public:
    Point(float x = 0.0f, float y = 0.0f, float z = 0.0f);
    Point(const Point &point);

    void setX(float x);
    float getX() const;
    void setY(float y);
    float getY() const;
    void setZ(float z);
    float getZ() const;

    float radius() const;

    operator float();

    bool operator==(Point rhs) const;

    // Compare by x, y, z and radius
    static bool pointEQ_X(Point &lhs, Point &rhs);
    static bool pointEQ_Y(Point &lhs, Point &rhs);
    static bool pointEQ_Z(Point &lhs, Point &rhs);
    static bool pointEQ_Radius(Point &lhs, Point &rhs);
    static bool pointEQ(Point &lhs, Point &rhs);

    // Comparison functions for pointers
    static bool pointEQ_X(Point *&lhs, Point *&rhs);
    static bool pointEQ_Y(Point *&lhs, Point *&rhs);
    static bool pointEQ_Z(Point *&lhs, Point *&rhs);
    static bool pointEQ_Radius(Point *&lhs, Point *&rhs);
    static bool pointEQ(Point *&lhs, Point *&rhs);

    // Conversion to string
    static string point2str_X(Point &point);
    static string point2str_Y(Point &point);
    static string point2str_Z(Point &point);
    static string point2str_Radius(Point &point);
    static string point2str(Point &point);

    // Conversion to string for pointers
    static string point2str_X(Point *&point);
    static string point2str_Y(Point *&point);
    static string point2str_Z(Point *&point);
    static string point2str_Radius(Point *&point);
    static string point2str(Point *&point);

    // Point operations
    static void pointRemove(Point *point);
    static Point *genPoints(int size, float minValue = 0, float maxValue = 1,
                            bool manualSeed = false, int seedValue = 0);
    static void println(Point *head, int size);
};

bool printResult(const string& output, const string& expect,
                   const string& name) {
    if (expect == output) {
      cout << "Test " + name + " --------------- PASS" 
           << "\n";
      return true;
    } else {
      cout << "Test " + name + " --------------- FAIL"  << "\n";
      cout << " Expected: " << expect << endl;
      cout << " Output  : " << output << endl;
      return false;
    }
}
bool XArrayList20()
{
    string name = "XArrayList20";
    //! data
  XArrayList<int> list;
  list.add(0);
  list.add(10);
  list.add(2);

  //! expect
  string expect = "get=10;[0, 10, 2];size=3;empty=0";

  //! output
  string output = "get=" + to_string(list.get(1)) + ";";
  output = output + list.toString() + ";size=" + to_string(list.size()) +
            ";empty=" + to_string(list.empty());

  //! remove data

  //! print result
  return printResult(output, expect, name);
}
int main(){
    cout << "The result: " << XArrayList20() << endl;
}
