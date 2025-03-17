#include <iostream>
#include <stdexcept>
using namespace std;

template <class T>
class DLinkedList {
public:
    class Node; // Forward declaration
protected:
    Node* head;
    Node* tail;
    int count;
public:
    DLinkedList();
    ~DLinkedList();
    void add(const T &e);
    void add(int index, const T &e);
    int size();
    bool    empty();
    T       get(int index);
    void    set(int index, const T &e);
    int     indexOf(const T &item);
    bool    contains(const T &item);
    void toString();
    T       removeAt(int index);
    bool    removeItem(const T &item);
    void    clear();
public:
    class Node {
    private:
        T data;
        Node *next;
        Node *previous;
        friend class DLinkedList<T>;

    public:
        Node() {
            this->previous = NULL;
            this->next = NULL;
        }

        Node(const T &data) {
            this->data = data;
            this->previous = NULL;
            this->next = NULL;
        }
    };
};

template <class T>
DLinkedList<T>::DLinkedList() {
    head = nullptr;
    tail = nullptr;
    count = 0;
}

template <class T>
DLinkedList<T>::~DLinkedList() {
    Node* current = head;
    while (current != nullptr) {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }
}

template <class T>
void DLinkedList<T>::add(const T& e) {
    /* Insert an element into the end of the list. */
    Node* newNode = new Node(e);
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        newNode->previous = tail;
        tail = newNode;
    }
    count++;
}

template<class T>
void DLinkedList<T>::add(int index, const T& e) {
    /* Insert an element into the list at given index. */ 
    if (index < 0 || index > count) {
        throw std::out_of_range("index is out of range");
    }
    Node* newNode = new Node(e);

    if (index == 0) {
        newNode->next = head;
        if (head != nullptr) {
            head->previous = newNode;
        }
        head = newNode;
        if (count == 0) {
            tail = newNode;
        }
    } else if (index == count) {
        tail->next = newNode;
        newNode->previous = tail;
        tail = newNode;
    } else {
        Node* current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        newNode->next = current;
        newNode->previous = current->previous;
        current->previous->next = newNode;
        current->previous = newNode;
    }
    count++;
}

template<class T>
int DLinkedList<T>::size() {
    /* Return the length (size) of list */ 
    return count;
}

template <class T>
void DLinkedList<T>::toString() {
    Node* current = head;
    cout << "[";
    while (current != nullptr) {
        cout << current->data;
        if (current->next != nullptr) {
            cout << ", ";
        }
        current = current->next;
    }
    cout << "]" << endl;
}
template<class T>
T DLinkedList<T>::get(int index) {
    /* Give the data of the element at given index in the list. */
    if (index < 0 || index > count) {
        throw std::out_of_range("index is out of range");
    }
    Node* current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return current->data;
}

template <class T>
void DLinkedList<T>::set(int index, const T& e) {
    /* Assign new value for element at given index in the list */
    if (index < 0 || index > count) {
        throw std::out_of_range("index is out of range");
    }
    Node* current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    current->data = e;
}

template<class T>
bool DLinkedList<T>::empty() {
    /* Check if the list is empty or not. */
    if (count == 0)
    {
        return true;
    }
    return false;
}

template<class T>
int DLinkedList<T>::indexOf(const T& item) {
    /* Return the first index wheter item appears in list, otherwise return -1 */
    Node* current = head;
    int position = 0;
    while (current != nullptr)
    {
        if (current->data == item)
        {
            return position;
        }
        position++;
        current = current->next;
    }
    return -1;
}

template<class T>
bool DLinkedList<T>::contains(const T& item) {
    /* Check if item appears in the list */
    Node* current = head;
    while (current != nullptr)
    {
        if (current->data == item)
        {
            return true;
        }
        current = current->next;
    }
    return false;
}
template <class T>
T DLinkedList<T>::removeAt(int index) {
    /* Remove element at index and return removed value */
    if (index < 0 || index >= count) {
        throw std::out_of_range("index is out of range");
    }

    Node* current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }

    if (current->previous != nullptr) {
        current->previous->next = current->next;
    } else {
        head = current->next;
    }

    if (current->next != nullptr) {
        current->next->previous = current->previous;
    } else {
        tail = current->previous;
    }

    T data = current->data;
    delete current;
    count--;

    return data;
}

template <class T>
bool DLinkedList<T>::removeItem(const T& item) {
    /* Remove the first appearance of item in list and return true, otherwise return false */
    Node* current = head;
    while (current != nullptr && current->data != item) {
        current = current->next;
    }

    if (current == nullptr) {
        return false;
    }

    if (current->previous != nullptr) {
        current->previous->next = current->next;
    } else {
        head = current->next;
    }

    if (current->next != nullptr) {
        current->next->previous = current->previous;
    } else {
        tail = current->previous;
    }

    delete current;
    count--;

    return true;
}

template<class T>
void DLinkedList<T>::clear() {
    /* Remove all elements in list */
    Node* current = head;
    while (current != nullptr) {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }
    head = nullptr;
    tail = nullptr;
    count = 0;
}

int main() {
    DLinkedList<int> list;
    list.add(1);
    list.add(2);
    list.add(3);
    list.add(1, 4);
    list.add(0, 5);

    cout << "List size: " << list.size() << endl; // Expected output: 5
    list.toString(); // Expected output: [5, 4, 1, 2, 3]

    // Test get method
    cout << "Element at index 0: " << list.get(0) << endl; // Expected output: 5
    cout << "Element at index 1: " << list.get(1) << endl; // Expected output: 4
    cout << "Element at index 2: " << list.get(2) << endl; // Expected output: 1
    cout << "Element at index 3: " << list.get(3) << endl; // Expected output: 2
    cout << "Element at index 4: " << list.get(4) << endl; // Expected output: 3

    // Test set method
    list.set(0, 10);
    list.set(1, 20);
    list.set(2, 30);
    list.set(3, 40);
    list.set(4, 50);
    list.toString(); // Expected output: [10, 20, 30, 40, 50]

    // Test empty method
    cout << "Is list empty? " << (list.empty() ? "Yes" : "No") << endl; // Expected output: No

    // Test indexOf method
    cout << "Index of 10: " << list.indexOf(10) << endl; // Expected output: 0
    cout << "Index of 20: " << list.indexOf(20) << endl; // Expected output: 1
    cout << "Index of 30: " << list.indexOf(30) << endl; // Expected output: 2
    cout << "Index of 40: " << list.indexOf(40) << endl; // Expected output: 3
    cout << "Index of 50: " << list.indexOf(50) << endl; // Expected output: 4
    cout << "Index of 60: " << list.indexOf(60) << endl; // Expected output: -1

    // Test contains method
    cout << "Does list contain 10? " << (list.contains(10) ? "Yes" : "No") << endl; // Expected output: Yes
    cout << "Does list contain 20? " << (list.contains(20) ? "Yes" : "No") << endl; // Expected output: Yes
    cout << "Does list contain 30? " << (list.contains(30) ? "Yes" : "No") << endl; // Expected output: Yes
    cout << "Does list contain 40? " << (list.contains(40) ? "Yes" : "No") << endl; // Expected output: Yes
    cout << "Does list contain 50? " << (list.contains(50) ? "Yes" : "No") << endl; // Expected output: Yes
    cout << "Does list contain 60? " << (list.contains(60) ? "Yes" : "No") << endl; // Expected output: No

    return 0;
}