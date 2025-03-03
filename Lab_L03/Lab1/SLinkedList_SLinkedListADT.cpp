#include <iostream>
#include <string>
#include <cstring>
#include <climits>
#include <utility>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <functional>
#include <algorithm>
using namespace std;

template <class T>
class SLinkedList {
public:
    class Node; // Forward declaration
protected:
    Node* head;
    Node* tail;
    int count;
public:
    SLinkedList();
    ~SLinkedList();
    void add(const T& e);
    void add(int index, const T& e);
    int size();
    string toString();
    bool    empty();
    T       get(int index);
    void    set(int index, T e);
    int     indexOf(T item);
    bool    contains(T item);
public:
    class Node {
    private:
        T data;
        Node* next;
        friend class SLinkedList<T>;
    public:
        Node() {
            next = 0;
        }
        Node(Node* next) {
            this->next = next;
        }
        Node(T data, Node* next) {
            this->data = data;
            this->next = next;
        }
    };
};
template <class T>
SLinkedList<T>::SLinkedList() {
    head = nullptr;
    tail = nullptr;
    count = 0;
}

template <class T>
SLinkedList<T>::~SLinkedList() {
    Node* current = head;
    while (current != nullptr) {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }
}

template <class T>
string SLinkedList<T>::toString() {
    string result = "[";
    Node* current = head;
    while (current != nullptr) {
        result += to_string(current->data);
        if (current->next != nullptr) {
            result += ",";
        }
        current = current->next;
    }
    result += "]";
    return result;
}

template <class T>
void SLinkedList<T>::add(const T& e) {
    /* Insert an element into the end of the list. */
    Node* current = new Node(e, nullptr);
    if (head == nullptr)
    {
        head = current;
        tail = current;
    }
    else {
        tail->next = current;
        tail = current;
    }
    count++;
}

template<class T>
void SLinkedList<T>::add(int index, const T& e) {
    /* Insert an element into the list at given index. */
    //  // If index is out of bounds, throw an exception
    // if index < 0 or index > count:
    //     throw out_of_range exception
    if (index < 0 || index > count) {
        throw std::out_of_range("index is out of range");
    }
    
    
    // // Create a new node with data e
    // newNode = new Node(e, nullptr)
    Node* newNode = new Node(e, nullptr);
    
    if (index == 0)
    {
        newNode->next = head;
        head  = newNode;
        if (count == 0)
        {
            tail = newNode;
        }
    }
    else {
        Node* current = head;
        for (int i = 0; i < index - 1; i++)
        {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
        if (newNode->next == nullptr)
        {
            tail = newNode;
        }
    }
    count++;
    // // If adding at the head (index == 0):
    // if index == 0:
    //     newNode.next = head
    //     head = newNode
    //     if count == 0:
    //         tail = newNode
    // else:
    //     // Traverse the list to find the node before the insertion point
    //     current = head
    //     for i from 0 to index - 1:
    //         current = current.next
        
    //     // Insert the new node
    //     newNode.next = current.next
    //     current.next = newNode
    //     if newNode.next == nullptr:
    //         tail = newNode
    
    // // Increment the count of nodes
    // count += 1
}

template<class T>
int SLinkedList<T>::size() {
    /* Return the length (size) of list */ 
    return count;
}

int main() {
    SLinkedList<int> list;
    int size = 10;

    for (int index = 0; index < size; index++) {
        list.add(index);
    }

    cout << list.toString() << endl; // Expected output: [0,1,2,3,4,5,6,7,8,9]

    SLinkedList<int> list2;

    for (int index = 0; index < size; index++) {
        list2.add(0, index);
    }

    cout << list2.toString() << endl; // Expected output: [9,8,7,6,5,4,3,2,1,0]

    return 0;
}