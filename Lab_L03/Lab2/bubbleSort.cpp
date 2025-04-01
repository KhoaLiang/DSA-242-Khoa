#include <iostream>
#include <sstream>
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
    SLinkedList()
    {
      this->head = nullptr;
      this->tail = nullptr;
      this->count = 0;
    }
    ~SLinkedList(){};
    void add(T e)
    {
        Node *pNew = new Node(e);

        if (this->count == 0)
        {
            this->head = this->tail = pNew;
        }
        else
        {
            this->tail->next = pNew;
            this->tail = pNew;
        }

        this->count++;
    }
    int size()
    {
        return this->count;
    }
    void printList()
    {
        stringstream ss;
        ss << "[";
        Node *ptr = head;
        while (ptr != tail)
        {
            ss << ptr->data << ",";
            ptr = ptr->next;
        }

        if (count > 0)
            ss << ptr->data << "]";
        else
            ss << "]";
        cout << ss.str() << endl;
    }
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
        Node(T data) {
            this->data = data;
            this->next = nullptr;
        }
    };

    void bubbleSort();
};

template <class T>
void SLinkedList<T>::bubbleSort()
{
    // Bubble sort implementation will go here
    //Psudocode
    // if head is nullptr or head->next is nullptr:
    //     return
    if (head == nullptr || head->next == nullptr)
    {
        return;
    }
    

    // for i from 0 to count - 1:
    //     current = head
    //     swapped = false

    //     while current is not nullptr and current->next is not nullptr:
    //         if current->data > current->next->data:
    //             swap(current->data, current->next->data)
    //             swapped = true
    //         current = current->next

    //     printList()

    //     if not swapped:
    //         break
    for (int i = 0; i < count - 1; i++)
    {
        Node* current = head;
        bool swapped = false;

        while (current != nullptr && current->next != nullptr)
        {
            if (current->data > current->next->data)
            {
                /* code */
                swap(current->data, current->next->data);
                swapped = true;
            }
            current = current->next;
        }
        // printList();
        if (!swapped)
        {
            break;
        }
        printList();
    }
}

int main() {
    {
        int arr[] = {9, 2, 8, 4, 1};
        SLinkedList<int> list;
        for(int i = 0; i < int(sizeof(arr)/sizeof(arr[0])); i++)
            list.add(arr[i]);
        list.bubbleSort();
    }

    {
        int arr[] = {1, 2, 3, 4, 5};
        SLinkedList<int> list;
        for(int i = 0; i < int(sizeof(arr)/sizeof(arr[0])); i++)
            list.add(arr[i]);
        list.bubbleSort();
    }

    {
        int arr[] = {5, 4, 3, 2, 1};
        SLinkedList<int> list;
        for(int i = 0; i < int(sizeof(arr)/sizeof(arr[0])); i++)
            list.add(arr[i]);
        list.bubbleSort();
    }

    {
        int arr[] = {1};
        SLinkedList<int> list;
        list.add(arr[0]);
        list.bubbleSort();
        list.printList();
    }

    {
        SLinkedList<int> list;
        list.bubbleSort();
        list.printList();
    }

    return 0;
}