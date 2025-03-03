#include <iostream>
#include <stdexcept>
using namespace std;

template <class T>
class ArrayList {
protected:
    T* data;        // dynamic array to store the list's items
    int capacity;   // size of the dynamic array
    int count;      // number of items stored in the array
public:
    ArrayList() { capacity = 5; count = 0; data = new T[5]; }
    ~ArrayList() { delete[] data; }
    void add(T e);
    void add(int index, T e);
    int size();
    bool empty();
    void clear();
    T get(int index);
    void set(int index, T e);
    int indexOf(T item);
    bool contains(T item);
    T removeAt(int index);
    bool removeItem(T item);
    void ensureCapacity(int index);
    string toString();
};

template<class T>
void ArrayList<T>::ensureCapacity(int cap){
    /* 
        if cap == capacity: 
            new_capacity = capacity * 1.5;
            create new array with new_capacity
        else: do nothing
    */
//    if cap == capacity:
//         new_capacity = capacity * 1.5
//         create new array with new_capacity
//         copy elements from old array to new array
//         delete old array
//         set data to new array
//         set capacity to new_capacity
//     else:
//         do nothing
    if (cap == capacity)
    {
        int new_capacity = capacity * 1.5;
        T* new_data = new T[new_capacity];
        for (int i = 0; i < capacity; i++)
        {
            new_data[i] = data[i];
        }
        delete[] data;
        data = new_data;
        capacity = new_capacity;
    }
    
}

template <class T>
void ArrayList<T>::add(T e) {
    /* Insert an element into the end of the array. */
    // if count == capacity:
    //     ensureCapacity(capacity)
    // add element e to the end of the array
    // increment count
    if (count == capacity)
    {
        ensureCapacity(capacity);
    }
    data[count] = e;
    count += 1;
}

template<class T>
void ArrayList<T>::add(int index, T e) {
    /* 
        Insert an element into the array at given index.
        if index is invalid:
            throw std::out_of_range("the input index is out of range!");
    */ 
//    if index is invalid:
//         throw out_of_range exception
//     if count == capacity:
//         ensureCapacity(capacity)
//     shift elements from index to the end of the array one position to the right
//     insert element e at index
//     increment count
    if (index < 0 || index > count) {
        throw std::out_of_range("the input index is out of range!");
    }
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

template<class T>
int ArrayList<T>::size() {
    /* Return the length (size) of the array */ 
    return count;
}

template<class T>
string ArrayList<T>::toString() {
    string result = "[";
    for (int i = 0; i < count; i++) {
        result += to_string(data[i]);
        if (i < count - 1) {
            result += ", ";
        }
    }
    result += "]";
    return result;
}
template<class T>
T ArrayList<T>::removeAt(int index) {
    /*
    Remove element at index and return removed value 
    if index is invalid:
        throw std::out_of_range("index is out of range");
    */
   //Psudocode
    // if index is invalid:
    //     throw out_of_range exception
    // store the element at index to be removed
    // shift elements from index + 1 to the end of the array one position to the left
    // decrement count
    // return the removed element
    if (index < 0 || index > count) {
        throw std::out_of_range("the input index is out of range!");
    }
    T storedAtIndex = data[index];
    for (int i = index; i < count - 1; i++)
    {
        data[i] = data[i + 1];
    }
    count -= 1;
    return storedAtIndex;
}

template<class T>
bool ArrayList<T>::removeItem(T item) {
    /* Remove the first appearance of item in array and return true, otherwise return false */
    //Psudocode
    // iterate through the array:
    //     if the current element is equal to item:
    //         call removeAt with the current index
    //         return true
    // return false
    for (int i = 0; i < count; i++) {
        if (data[i] == item) {
            removeAt(i);
            return true;
        }
    }
    return false;
}

template<class T>
void ArrayList<T>::clear() {
    /* 
        Delete array if array is not NULL
        Create new array with: size = 0, capacity = 5
    */
   //Psudocode
    // if data is not NULL:
    //     delete the array
    // create a new array with capacity = 5
    // set count to 0
    if (data != nullptr) {
        delete[] data;
    }
    data = new T[5];
    count = 0;
    capacity = 5;
}

int main() {
    ArrayList<int> arr;

    for (int i = 0; i < 10; ++i) {
        arr.add(i);
    }
    arr.removeAt(0);

    cout << arr.toString() << '\n';
    cout << arr.size() << '\n';

    ArrayList<int> arr2;

    for (int i = 0; i < 10; ++i) {
        arr2.add(i);
    }
    arr2.removeAt(9);

    cout << arr2.toString() << '\n';
    cout << arr2.size() << '\n';

    ArrayList<int> arr3;

    for (int i = 0; i < 10; ++i) {
        arr3.add(i);
    }
    arr3.removeAt(5);

    cout << arr3.toString() << '\n';
    cout << arr3.size() << '\n';

    return 0;
}