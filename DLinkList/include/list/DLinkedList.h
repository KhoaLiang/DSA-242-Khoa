/*
 * File:   DLinkedList.h
 */

#ifndef DLINKEDLIST_H
#define DLINKEDLIST_H

#include "list/IList.h"

#include <sstream>
#include <iostream>
#include <type_traits>
using namespace std;

template <class T>
class DLinkedList : public IList<T>
{
public:
    class Node;        // Forward declaration
    class Iterator;    // Forward declaration
    class BWDIterator; // Forward declaration

protected:
    Node *head; // this node does not contain user's data
    Node *tail; // this node does not contain user's data
    int count;
    bool (*itemEqual)(T &lhs, T &rhs);        // function pointer: test if two items (type: T&) are equal or not
    void (*deleteUserData)(DLinkedList<T> *); // function pointer: be called to remove items (if they are pointer type)

public:
    DLinkedList(
        void (*deleteUserData)(DLinkedList<T> *) = 0,
        bool (*itemEqual)(T &, T &) = 0);
    DLinkedList(const DLinkedList<T> &list);
    DLinkedList<T> &operator=(const DLinkedList<T> &list);
    ~DLinkedList();

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
    // Inherit from IList: END

    void println(string (*item2str)(T &) = 0)
    {
        cout << toString(item2str) << endl;
    }
    void setDeleteUserDataPtr(void (*deleteUserData)(DLinkedList<T> *) = 0)
    {
        this->deleteUserData = deleteUserData;
    }

    bool contains(T array[], int size)
    {
        int idx = 0;
        for (DLinkedList<T>::Iterator it = begin(); it != end(); it++)
        {
            if (!equals(*it, array[idx++], this->itemEqual))
                return false;
        }
        return true;
    }

    /*
     * free(DLinkedList<T> *list):
     *  + to remove user's data (type T, must be a pointer type, e.g.: int*, Point*)
     *  + if users want a DLinkedList removing their data,
     *      he/she must pass "free" to constructor of DLinkedList
     *      Example:
     *      DLinkedList<T> list(&DLinkedList<T>::free);
     */
    static void free(DLinkedList<T> *list)
    {
        typename DLinkedList<T>::Iterator it = list->begin();
        while (it != list->end())
        {
            delete *it;
            it++;
        }
    }

    /* begin, end and Iterator helps user to traverse a list forwardly
     * Example: assume "list" is object of DLinkedList

     DLinkedList<char>::Iterator it;
     for(it = list.begin(); it != list.end(); it++){
            char item = *it;
            std::cout << item; //print the item
     }
     */
    Iterator begin()
    {
        return Iterator(this, true);
    }
    Iterator end()
    {
        return Iterator(this, false);
    }

    /* last, beforeFirst and BWDIterator helps user to traverse a list backwardly
     * Example: assume "list" is object of DLinkedList

     DLinkedList<char>::BWDIterator it;
     for(it = list.last(); it != list.beforeFirst(); it--){
            char item = *it;
            std::cout << item; //print the item
     }
     */
    BWDIterator bbegin()
    {
        return BWDIterator(this, true);
    }
    BWDIterator bend()
    {
        return BWDIterator(this, false);
    }

protected:
    static bool equals(T &lhs, T &rhs, bool (*itemEqual)(T &, T &))
    {
        if (itemEqual == 0)
            return lhs == rhs;
        else
            return itemEqual(lhs, rhs);
    }
    void copyFrom(const DLinkedList<T> &list);
    void removeInternalData();
    Node *getPreviousNodeOf(int index);
    void checkIndex(int index);

    //////////////////////////////////////////////////////////////////////
    ////////////////////////  INNER CLASSES DEFNITION ////////////////////
    //////////////////////////////////////////////////////////////////////
public:
    class Node
    {
    public:
        T data;
        Node *next;
        Node *prev;
        friend class DLinkedList<T>;

    public:
        Node(Node *next = 0, Node *prev = 0)
        {
            this->next = next;
            this->prev = prev;
        }
        Node(T data, Node *next = 0, Node *prev = 0)
        {
            this->data = data;
            this->next = next;
            this->prev = prev;
        }
    };

    //////////////////////////////////////////////////////////////////////
    class Iterator
    {
    private:
        DLinkedList<T> *pList;
        Node *pNode;

    public:
        Iterator(DLinkedList<T> *pList = 0, bool begin = true)
        {
            if (begin)
            {
                if (pList != 0)
                    this->pNode = pList->head->next;
                else
                    pNode = 0;
            }
            else
            {
                if (pList != 0)
                    this->pNode = pList->tail;
                else
                    pNode = 0;
            }
            this->pList = pList;
        }

        Iterator &operator=(const Iterator &iterator)
        {
            this->pNode = iterator.pNode;
            this->pList = iterator.pList;
            return *this;
        }
        void remove(void (*removeItemData)(T) = 0)
        {
            pNode->prev->next = pNode->next;
            pNode->next->prev = pNode->prev;
            Node *pNext = pNode->prev; // MUST prev, so iterator++ will go to end
            if (removeItemData != 0)
                removeItemData(pNode->data);
            delete pNode;
            pNode = pNext;
            pList->count -= 1;
        }

        T &operator*()
        {
            return pNode->data;
        }
        bool operator!=(const Iterator &iterator)
        {
            return pNode != iterator.pNode;
        }
        // Prefix ++ overload
        Iterator &operator++()
        {
            pNode = pNode->next;
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

    // Backward Iterator
    class BWDIterator
    {
    private:
        DLinkedList<T> *pList;
        Node *pNode;

    public:
        BWDIterator(DLinkedList<T> *pList = 0, bool last = true)
        {
            if (last)
            {
                if (pList != 0)
                    this->pNode = pList->tail->prev;
                else
                    pNode = 0;
            }
            else
            {
                if (pList != 0)
                    this->pNode = pList->head;
                else
                    pNode = 0;
            }
            this->pList = pList;
        }

        BWDIterator &operator=(const BWDIterator &iterator)
        {
            this->pNode = iterator.pNode;
            this->pList = iterator.pList;
            return *this;
        }
        void remove(void (*removeItemData)(T) = 0)
        {
            pNode->prev->next = pNode->next;
            pNode->next->prev = pNode->prev;
            Node *pNext = pNode->next; // MUST next, so iterator-- will go to head
            if (removeItemData != 0)
                removeItemData(pNode->data);
            delete pNode;
            pNode = pNext;
            pList->count -= 1;
        }

        T &operator*()
        {
            return pNode->data;
        }
        bool operator!=(const BWDIterator &iterator)
        {
            return pNode != iterator.pNode;
        }
        // Prefix -- overload
        BWDIterator &operator--()
        {
            pNode = pNode->prev;
            return *this;
        }
        // Postfix -- overload
        BWDIterator operator--(int)
        {
            BWDIterator iterator = *this;
            --*this;
            return iterator;
        }
    };
};

//////////////////////////////////////////////////////////////////////
// Define a shorter name for DLinkedList:

template <class T>
using List = DLinkedList<T>;

//////////////////////////////////////////////////////////////////////
////////////////////////     METHOD DEFNITION      ///////////////////
//////////////////////////////////////////////////////////////////////

template <class T>
DLinkedList<T>::DLinkedList(
    void (*deleteUserData)(DLinkedList<T> *),
    bool (*itemEqual)(T &, T &))
{
    // TODO
    this->deleteUserData = deleteUserData;
    this->itemEqual = itemEqual;

    head = new Node(); // Initialize head as a dummy node
    tail = new Node(); // Initialize tail as a dummy node
    head->next = tail;
    head->prev = nullptr;
    tail->prev = head;
    tail->next = nullptr;
    count = 0;
}

template <class T>
DLinkedList<T>::DLinkedList(const DLinkedList<T> &list)
{
    // TODO
    if (this != &list) // Check for self-assignment
    {
        this->deleteUserData = list.deleteUserData;
        this->itemEqual = list.itemEqual;

        head = new Node(); // Initialize head as a dummy node
        tail = new Node(); // Initialize tail as a dummy node
        head->next = tail;
        head->prev = nullptr;
        tail->prev = head;
        tail->next = nullptr;
        count = 0;

        Node *current = list.head->next; // Start from the first real node
        while (current != list.tail) // Iterate until the tail dummy node
        {
            add(current->data);
            current = current->next;
        }
    }
}

template <class T>
DLinkedList<T> &DLinkedList<T>::operator=(const DLinkedList<T> &list)
{
    // TODO
    if (this != &list) // Check for self-assignment
    {
        if(count != 0) clear(); // Clear the current list if list is not empty

        this->deleteUserData = list.deleteUserData;
        this->itemEqual = list.itemEqual;

        Node *current = list.head->next; // Start from the first real node
        while (current != list.tail) // Iterate until the tail dummy node
        {
            add(current->data);
            current = current->next;
        }
    }
    return *this;
}

template <class T>
DLinkedList<T>::~DLinkedList()
{
    // TODO
}

template <class T>
void DLinkedList<T>::add(T e)
{
    // TODO
    Node* nodePrev = tail->prev;
    Node* newNode = new Node(e, tail, nodePrev);
    nodePrev->next = newNode;
    tail->prev = newNode;
    count++;
}
template <class T>
void DLinkedList<T>::add(int index, T e)
{
    // TODO
    checkIndex(index);
    Node* preIndexNode = head;
    for (int position = 0; position < index; position++)
    {
        preIndexNode = preIndexNode->next;
    }
    Node* afterIndexNode = preIndexNode->next;
    Node* newNode = new Node(e, afterIndexNode, preIndexNode);
    preIndexNode->next = newNode;
    afterIndexNode->prev = newNode;
    count++;
}

template <class T>
typename DLinkedList<T>::Node *DLinkedList<T>::getPreviousNodeOf(int index)
{
    /**
     * Returns the node preceding the specified index in the doubly linked list.
     * If the index is in the first half of the list, it traverses from the head; otherwise, it traverses from the tail.
     * Efficiently navigates to the node by choosing the shorter path based on the index's position.
     */
    // TODO
}

template <class T>
T DLinkedList<T>::removeAt(int index)
{
    // TODO
    checkIndex(index);
    if (index == count)
    {
        throw std::out_of_range("Index is out of range!");
    }
    Node* current = head->next; // Start from the first real node
    for (int position = 0; position < index; position++)
    {
        current = current->next;
    }
    Node* afterCurrentNode = current->next;
    Node* beforeCurrentNode = current->prev;
    beforeCurrentNode->next = afterCurrentNode;
    afterCurrentNode->prev = beforeCurrentNode;
    T deletedData = current->data;
    delete current;
    count--;

    return deletedData;
}

template <class T>
bool DLinkedList<T>::empty()
{
    // TODO
    if (count == 0)
    {
        return true;
    }
    return false;
}

template <class T>
int DLinkedList<T>::size()
{
    // TODO
    return count;
}

template <class T>
void DLinkedList<T>::clear()
{
    // TODO
    Node* current = head->next;
    while (current != tail)
    {
        Node* nextNode = current->next;
        if (deleteUserData != nullptr)
        {
            deleteUserData(this);
        }
        else
        {
            delete current;
        }
        current = nextNode;
    }
    head->next = tail;
    tail->prev = head;
    count = 0;
}

template <class T>
T &DLinkedList<T>::get(int index)
{
    // TODO
    checkIndex(index);
    if (empty() == true && index == 0)
    {
        throw std::out_of_range("Index is out of range!");
    }
    Node* current = head->next; // Start from the first real node
    for (int position = 0; position < index; position++)
    {
        current = current->next;
    }
    return current->data;
}

template <class T>
int DLinkedList<T>::indexOf(T item)
{
    int index = 0;
    if (!empty())
    {
        Node* current = head->next; // Start from the first real node
        while (current != tail) // Iterate until the tail dummy node
        {
            if (itemEqual != nullptr)
            {
                if (itemEqual(current->data, item))
                {
                    return index;
                }
            }
            else
            {
                if (current->data == item)
                {
                    return index;
                }
            }
            current = current->next;
            index++;
        }
    }
    return -1;
}

template <class T>
bool DLinkedList<T>::removeItem(T item, void (*removeItemData)(T))
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
bool DLinkedList<T>::contains(T item)
{
    // TODO
    if (!empty())
    {
        Node* current = head->next; // Start from the first real node
        while (current != tail) // Iterate until the tail dummy node
        {
            if (itemEqual != nullptr)
            {
                if (itemEqual(current->data, item))
                {
                    return true;
                }
            }
            else
            {
                if (current->data == item)
                {
                    return true;
                }
            }
            current = current->next;
        }
    }
    return false;
}

template <class T>
string DLinkedList<T>::toString(string (*item2str)(T &))
{
    /**
     * Converts the list into a string representation, where each element is formatted using a user-provided function.
     * If no custom function is provided, it directly uses the element's default string representation.
     * Example: If the list contains {1, 2, 3} and the provided function formats integers, calling toString would return "[1, 2, 3]".
     *
     * @param item2str A function that converts an item of type T to a string. If null, default to string conversion of T.
     * @return A string representation of the list with elements separated by commas and enclosed in square brackets.
     */
    string result = "[";
    Node *current = head->next; // Start from the first real node

    while (current != tail) // Iterate until the tail dummy node
    {
        string eleStr;
        if (item2str != nullptr)
        {
            eleStr = item2str(current->data);
        }
        else
        {
            stringstream ss;
            ss << current->data;
            eleStr = ss.str();
        }
        result += eleStr;

        if (current->next != tail)
        {
            result += ", ";
        }
        current = current->next;
    }
    result += "]";
    return result;
}

template <class T>
void DLinkedList<T>::copyFrom(const DLinkedList<T> &list)
{
    /**
     * Copies the contents of another doubly linked list into this list.
     * Initializes the current list to an empty state and then duplicates all data and pointers from the source list.
     * Iterates through the source list and adds each element, preserving the order of the nodes.
     */

    // TODO
}
//////////////////////////////////////////////////////////////////////
/////////////////////// (protected) METHOD DEFNITION /////////////////
//////////////////////////////////////////////////////////////////////
template <class T>
void DLinkedList<T>::removeInternalData()
{
    /**
     * Clears the internal data of the list by deleting all nodes and user-defined data.
     * If a custom deletion function is provided, it is used to free the user's data stored in the nodes.
     * Traverses and deletes each node between the head and tail to release memory.
     */
    // TODO
}
template <class T>
void DLinkedList<T>::checkIndex(int index)
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

#endif /* DLINKEDLIST_H */
