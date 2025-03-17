#ifndef QUEUE_H
#define QUEUE_H

#include "DLinkedList.h"

template<class T>
class Queue {
protected:
    DLinkedList<T> list;
public:
    Queue() {}

    void push(T item) {
        // Push new element into the end of the queue
        list.add(item);
    }

    T pop() {
        // Remove an element in the head of the queue
        return list.removeAt(0);
    }

    T top() {
        // Get value of the element in the head of the queue
        return list.get(0);
    }

    bool empty() {
        // Determine if the queue is empty
        return list.empty();
    }

    int size() {
        // Get the size of the queue
        return list.size();
    }

    void clear() {
        // Clear all elements of the queue
        list.clear();
    }
};

#endif /* QUEUE_H */