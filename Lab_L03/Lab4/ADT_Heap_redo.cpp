#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
#define SEPARATOR "#<ab@17943918#@>#"
template<class T>
class Heap {
protected:
    T* elements;
    int capacity;
    int count;
public:
    Heap()
    {
        this->capacity = 10;
        this->count = 0;
        this->elements = new T[capacity];
    }
    ~Heap()
    {
        delete[]elements;
    }
    void push(T item);
    
    bool isEmpty();
    bool contains(T item);
    T peek();
    bool pop();
    int size();
    int getItem(T item);
    void remove(T item);
    void clear();
    void printHeap()
    {
        cout << "Max Heap [ ";
        for (int i = 0; i < count; i++)
            cout << elements[i] << " ";
        cout << "]\n";
    }
private:
    void ensureCapacity(int minCapacity);
    void reheapUp(int position);
    void reheapDown(int position);
};
template<class T>
int Heap<T>::size(){
    return count;
}

template<class T>
bool Heap<T>::isEmpty(){
    if (count == 0)
    {
        return true;
    }
    return false;
}

template<class T>
T Heap<T>::peek(){
    if (isEmpty() != false)
    {
        return elements[0];
    }
    return -1;
}

template<class T>
bool Heap<T>::contains(T item){
    for (int i = 0; i < count; i++)
    {
        if (elements[i] == item)
        {
            return true;
        }
    }
    return false;
}

template<class T>
bool Heap<T>::pop() {
    if (isEmpty()) {
        return -1; // Return -1 if the heap is empty
    }
    elements[0] = elements[count - 1]; // Replace the root with the last element
    count--;                           // Decrease the count
    reheapDown(0);                     // Restore the heap property
    return true;                       // Return true to indicate success
}

template<class T>
void Heap<T>::push(T item) {
    ensureCapacity(count + 1); // Ensure there is enough space
    elements[count] = item;   // Add the new item at the end
    reheapUp(count);          // Restore the heap property
    count++;                  // Increment the count
}


template<class T>
void Heap<T>::ensureCapacity(int minCapacity) {
    if (minCapacity > capacity) {
        int newCapacity = max(capacity * 2, minCapacity); // Double the capacity
        T* newElements = new T[newCapacity];
        memcpy(newElements, elements, count * sizeof(T)); // Copy the existing elements
        delete[] elements; // Free the old array
        elements = newElements;
        capacity = newCapacity;
    }
}

template<class T>
void Heap<T>::reheapUp(int position) {
    int parent = (position - 1) / 2; // Calculate the parent index
    while (position > 0 && elements[position] > elements[parent]) {
        swap(elements[position], elements[parent]); // Swap the current node with its parent
        position = parent; // Move up to the parent
        parent = (position - 1) / 2; // Recalculate the parent index
    }
}
template<class T>
void Heap<T>::reheapDown(int position) {
    int leftChild = 2 * position + 1;  // Calculate the left child index
    int rightChild = 2 * position + 2; // Calculate the right child index
    int largest = position; // Assume the current node is the largest

    if (leftChild < count && elements[leftChild] > elements[largest]) {
        largest = leftChild; // Update the largest if the left child is larger
    }
    if (rightChild < count && elements[rightChild] > elements[largest]) {
        largest = rightChild; // Update the largest if the right child is larger
    }
    if (largest != position) {
        swap(elements[position], elements[largest]); // Swap the current node with the largest child
        reheapDown(largest); // Recursively restore the heap property
    }
}
int main() {
    Heap<int> heap;

    heap.push(10);
    heap.push(20);
    heap.push(5);
    heap.push(30);

    heap.printHeap(); // Output: Max Heap [ 30 20 5 10 ]

    cout << "Peek: " << heap.peek() << endl; // Output: Peek: 30

    cout << "Pop: " << heap.pop() << endl; // Output: Pop: 1 (true)
    heap.printHeap(); // Output: Max Heap [ 20 10 5 ]

    cout << "Contains 10: " << heap.contains(10) << endl; // Output: Contains 10: 1
    cout << "Contains 50: " << heap.contains(50) << endl; // Output: Contains 50: 0

    cout << "Size: " << heap.size() << endl; // Output: Size: 3
    cout << "Is Empty: " << heap.isEmpty() << endl; // Output: Is Empty: 0 (false)

    return 0;
}