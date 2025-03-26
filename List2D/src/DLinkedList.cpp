
#include "list/DLinkedList.h"

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
             Node *pNext = pNode->next; // MUST prev, so iterator++ will go to end
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
 
     class BWDIterator {
         private:
          DLinkedList<T> *pList;
          Node *pNode;
      
         public:
          // Constructor
          BWDIterator(DLinkedList<T> *pList = nullptr, bool begin = true) {
            this->pList = pList;
            if (begin) {
            
              if (pList != nullptr) {
                this->pNode = pList->tail->prev;
              } else {
                this->pNode = nullptr;
              }
            } else {
              
               this->pNode = pList->head; 
            }
          }
      
      
          BWDIterator &operator=(const BWDIterator &iterator) {
            this->pNode = iterator.pNode;
            this->pList = iterator.pList;
            return *this;
          }
      
         
          void remove(void (*removeItemData)(T) = nullptr) {
           
              pNode->next->prev = pNode->prev;
              pNode->prev->next = pNode->next;
              Node *pPrev = pNode->next; //! MUST next, so iterator++ will go to head  kiểm tra lại cái này nha
              if (removeItemData != nullptr) removeItemData(pNode->data);
              delete pNode;
              pNode = pPrev;
              pList->count--;
            
          }
      
          // Toán tử dereference
          T &operator*() {
            return pNode->data;
          }
      
        
          bool operator!=(const BWDIterator &iterator) {
            return pNode != iterator.pNode;
          }
      
          
          BWDIterator &operator--() {
              pNode = pNode->prev;
              return *this;
          }
      
         
          BWDIterator operator--(int) {
              BWDIterator iterator = *this;
              --(*this);
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
   

 }
 
 template <class T>
 DLinkedList<T>::DLinkedList(const DLinkedList<T> &list)
 {
     // TODO
     xét cái if nó khác vs chính nó this != &list
  // khởi tạo gán các giá trị, new head , tail, cho 2 nó trỏ tới nhau
 
// gọi coppy form
 }
 
 template <class T>
 DLinkedList<T> &DLinkedList<T>::operator=(const DLinkedList<T> &list)
 {
     // TODO
     // xét nó khác chính nó this != &list
    // tương tự như xarray gọi remove ròi coppy form
 }
 
 template <class T>
 DLinkedList<T>::~DLinkedList()
 {
     // TODO
     // gọi clear hoăc removeData
     // xóa đi con trỏ delete head, delete tail
     delete tail;
     delete head;
    
 }
 
 template <class T>
 void DLinkedList<T>::add(T e)
 {
     // TODO
     // thêm vào cuối 
    
     
 }
 template <class T>
 void DLinkedList<T>::add(int index, T e)
 {
     // TODO
     // tìm node ở vị trí trước đó rồi cập nhật lại con trỏ next và prve
    
 }
 // Hàm trả về node trước ví trí đó
 template <class T>
 typename DLinkedList<T>::Node *DLinkedList<T>::getPreviousNodeOf(int index)
 {
     /**
      * Returns the node preceding the specified index in the doubly linked list.
      * If the index is in the first half of the list, it traverses from the head; otherwise, it traverses from the tail.
      * Efficiently navigates to the node by choosing the shorter path based on the index's position.
      */
     // TODO
 
    //xét giới hạn
   
    // xét riêng trường hợp index là 0 trả ved head


    // xét trường hợp index  <= count /2
    // duyệt từ trái sang phải phải trả về node trước đó

    // và trường hợp else
    // duyệt từ phải sang trái , trả về node trước đó
   // 1<-2<-3 <-4 <-5   index 4 -> trả về node 4 là node trước vị trí index 4
     
     
 }
 
 template <class T>
 T DLinkedList<T>::removeAt(int index)
 {
     // TODO
    //T data = getPreviousNodeOf->next->data;
    return data 
   
 }
 
 template <class T>
 bool DLinkedList<T>::empty()
 {
     // TODO
   
 }
 
 template <class T>
 int DLinkedList<T>::size()
 {
     // TODO

 }
 
 template <class T>
 void DLinkedList<T>::clear()
 {
     // TODO

 }
 
 template <class T>
 T &DLinkedList<T>::get(int index)
 {
     // TODO
    
  //  getPreviousNodeOf(index)->next; dùng hàm này lấy các phần tử trước nó
    
 }
 
 template <class T>
 int DLinkedList<T>::indexOf(T item)
 {
     // TODO, equal
    
 }
 
 template <class T>
 bool DLinkedList<T>::removeItem(T item, void (*removeItemData)(T))
 {
     // TODO equal để só sánh tương tự aarray, nhớ khi xóa có delete node
     
 }
 
 template <class T>
 bool DLinkedList<T>::contains(T item)
 {
     // TODO equal


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
     // TODO
    // Tương tự bên Xarray
 }
 
 template <class T>
 void DLinkedList<T>::copyFrom(const DLinkedList<T> &list)
 {
     /**
      * Copies the contents of another doubly linked list into this list.
      * Initializes the current list to an empty state and then duplicates all data and pointers from the source list.
      * Iterates through the source list and adds each element, preserving the order of the nodes.
      */
    // gán các giá trị và head tail phải trỏ lẫn nhau
    head->next = tail 
    tail->prev = head
    count = 0
    // duyệt qua vòng lặp thêm data dùng hàm add thêm vào cuối 
    duyeejrt từ list->next   != list.tail 
     // TODO
    // duyệt qua vòng lặp thêm data
     // Gán 2 con trỏ
     deleteusserdata = list.deleteuserdataa
     itemeua = list.itemequal
   
 }
 
 template <class T>
 void DLinkedList<T>::removeInternalData()
 {
     /**
      * Clears the internal data of the list by deleting all nodes and user-defined data.
      * If a custom deletion function is provided, it is used to free the user's data stored in the nodes.
      * Traverses and deletes each node between the head and tail to release memory.
      */
     // TODO
     // xóa deleteuserdata truyền this vào
     // duyệt qua vòng lặp xóa các node
     xóa đi node delete node
     // nhớ cập nhật head tail trỏ lẫn nhau
     head ->next = tail 
     taii->prev = head
     count = 0
     // Đặt số lượng phần tử bằng 0
 
 }
 
 #endif /* DLINKEDLIST_H */
 