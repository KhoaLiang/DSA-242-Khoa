#include <iostream>
using namespace std;

template <class T>
class DLinkedList 
{
public:
    class Node 
    {
    public:
        T data;
        Node* next;
        Node* prev;
        Node(T data, Node* next = nullptr, Node* prev = nullptr) 
            : data(data), next(next), prev(prev) {}
    };

protected:
    Node* head;
    Node* tail;
    int count;

public:
    DLinkedList() : head(nullptr), tail(nullptr), count(0) {}
    ~DLinkedList() { clear(); }

    void add(const T& e) {
        Node* newNode = new Node(e);
        if (tail) {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        } else {
            head = tail = newNode;
        }
        count++;
    }

    void add(int index, const T& e) {
        if (index < 0 || index > count) throw out_of_range("Index out of range");
        if (index == count) {
            add(e);
            return;
        }
        Node* newNode = new Node(e);
        if (index == 0) {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        } else {
            Node* current = head;
            for (int i = 0; i < index; i++) {
                current = current->next;
            }
            newNode->next = current;
            newNode->prev = current->prev;
            current->prev->next = newNode;
            current->prev = newNode;
        }
        count++;
    }

    T removeAt(int index) {
        if (index < 0 || index >= count) throw out_of_range("Index out of range");
        Node* toDelete;
        if (index == 0) {
            toDelete = head;
            head = head->next;
            if (head) head->prev = nullptr;
            else tail = nullptr;
        } else if (index == count - 1) {
            toDelete = tail;
            tail = tail->prev;
            tail->next = nullptr;
        } else {
            toDelete = head;
            for (int i = 0; i < index; i++) {
                toDelete = toDelete->next;
            }
            toDelete->prev->next = toDelete->next;
            toDelete->next->prev = toDelete->prev;
        }
        T data = toDelete->data;
        delete toDelete;
        count--;
        return data;
    }

    bool removeItem(const T& removeItem) {
        Node* current = head;
        while (current) {
            if (current->data == removeItem) {
                if (current == head) {
                    head = head->next;
                    if (head) head->prev = nullptr;
                    else tail = nullptr;
                } else if (current == tail) {
                    tail = tail->prev;
                    tail->next = nullptr;
                } else {
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                }
                delete current;
                count--;
                return true;
            }
            current = current->next;
        }
        return false;
    }

    bool empty() { return count == 0; }
    int size() { return count; }
    void clear() {
        while (head) {
            Node* toDelete = head;
            head = head->next;
            delete toDelete;
        }
        tail = nullptr;
        count = 0;
    }

    T get(int index) {
        if (index < 0 || index >= count) throw out_of_range("Index out of range");
        Node* current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        return current->data;
    }

    void set(int index, const T& e) {
        if (index < 0 || index >= count) throw out_of_range("Index out of range");
        Node* current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        current->data = e;
    }

    int indexOf(const T& item) {
        Node* current = head;
        int index = 0;
        while (current) {
            if (current->data == item) return index;
            current = current->next;
            index++;
        }
        return -1;
    }

    bool contains(const T& item) {
        return indexOf(item) != -1;
    }
};

template<class T>
class Stack {
protected:
    DLinkedList<T> list;
public:
    Stack() {}
    void push(T item);
    T pop();
    T top();
    bool empty();
    int size();
    void clear();
};

template<class T>
void Stack<T>::push(T item) {
    list.add(item);
}

template<class T>
T Stack<T>::pop() {
    return list.removeAt(list.size() - 1);
}

template<class T>
T Stack<T>::top() {
    return list.get(list.size() - 1);
}

template<class T>
bool Stack<T>::empty() {
    return list.empty();
}

template<class T>
int Stack<T>::size() {
    return list.size();
}

template<class T>
void Stack<T>::clear() {
    list.clear();
}

int main() {
    DLinkedList<int> list;
    list.add(1);
    list.add(2);
    list.add(3);
    list.add(1, 4); // List: 1, 4, 2, 3
    cout << "List size: " << list.size() << endl; // Output: 4
    cout << "Element at index 1: " << list.get(1) << endl; // Output: 4
    list.removeAt(2); // List: 1, 4, 3
    cout << "List size after removal: " << list.size() << endl; // Output: 3
    cout << "Element at index 2: " << list.get(2) << endl; // Output: 3
    list.clear();
    cout << "List size after clearing: " << list.size() << endl; // Output: 0

    return 0;
}