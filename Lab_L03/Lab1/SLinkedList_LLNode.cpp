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

class LLNode {
public:
    int val;
    LLNode* next;

    LLNode() : val(0), next(nullptr) {}
    LLNode(int val, LLNode* next = nullptr) : val(val), next(next) {}

    static LLNode* createWithIterators(const int* begin, const int* end) {
        LLNode* head = nullptr;
        LLNode* tail = nullptr;
        for (const int* it = begin; it != end; ++it) {
            LLNode* newNode = new LLNode(*it);
            if (!head) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
        }
        return head;
    }

    static void printList(LLNode* head) {
        LLNode* current = head;
        cout << "[";
        while (current) {
            cout << current->val;
            if (current->next) {
                cout << ", ";
            }
            current = current->next;
        }
        cout << "]" << endl;
    }

    void clear() {
        LLNode* current = this;
        while (current) {
            LLNode* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
};

LLNode* addLinkedList(LLNode* l0, LLNode* l1){
    // // Initialize a dummy node to act as the head of the result list
    // dummy = new LLNode(0)
    // current = dummy
    LLNode* dummy = new LLNode();
    LLNode* current = dummy;

    // // Initialize carry to 0
    // carry = 0
    int carry = 0;

    // // Iterate through both linked lists until both are null and carry is 0
    // while l0 is not null or l1 is not null or carry is not 0:
    while (l0 != nullptr || l1 != nullptr || carry != 0)
    {
        //     // Get the values from the current nodes of l0 and l1, or 0 if the node is null
        //     val0 = if l0 is not null then l0.val else 0
        //     val1 = if l1 is not null then l1.val else 0
        int val0 = (l0 != nullptr) ? l0->val : 0;
        int val1 = (l1 != nullptr) ? l1->val : 0;

        //     // Calculate the sum of val0, val1, and carry
        //     sum = val0 + val1 + carry
        int sum = val0 + val1 + carry;


        //     // Update carry for the next iteration
        //     carry = sum // 10
        carry = sum / 10;

        //     // Create a new node with the digit value of sum % 10 and attach it to the result list
        //     current.next = new LLNode(sum % 10)
        //     current = current.next
        current->next = new LLNode(sum % 10);
        current = current->next;

        //     // Move to the next nodes in l0 and l1 if they are not null
        if (l0 != nullptr) {
            l0 = l0->next;
        }
        if (l1 != nullptr) {
            l1 = l1->next;
        }
    }
    
    

    // // Return the next node of dummy, which is the head of the result list
    // return dummy.next
    return dummy->next;
}

LLNode* reverseLinkedList(LLNode* head){
    // Initialize three pointers: prev, current, and next
    // prev = nullptr
    // current = head

    // Iterate through the linked list
    // while current is not nullptr:
    //     // Store the next node
    //     next = current->next
    //     // Reverse the current node's pointer
    //     current->next = prev
    //     // Move the pointers one position forward
    //     prev = current
    //     current = next

    // Return prev as the new head of the reversed linked list
    LLNode* prev = new LLNode();
    LLNode* current = new LLNode();
    LLNode* next = new LLNode();

    prev = nullptr;
    current = head;

    while (current != nullptr)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}
LLNode* rotateLinkedList(LLNode* head, int k) {
    // STUDENT ANSWER
    //Psudocode
    // // If the list is empty or k is 0, return the head
    // if head is nullptr or k is 0:
    //     return head
    if (head == nullptr || k == 0)
    {
        return head;
    }
    

    // // Initialize a pointer to traverse the list and a variable to count the length
    // current = head
    // length = 1
    LLNode* current = head;
    int length = 1;

    // // Traverse the list to find the length and the last node
    // while current.next is not nullptr:
    //     current = current.next
    //     length += 1

    while (current->next != nullptr)
    {
        current = current->next;
        length += 1;
    }
    
    // // Connect the last node to the head to make it a circular list
    // current.next = head
    current->next = head;

    // // Calculate the effective rotations needed
    // k = k % length
    k = k % length;

    // // Find the new tail (length - k - 1) and the new head (length - k)
    // new_tail = head
    LLNode* new_tail = head;
    for (int i = 0; i < length - k - 1; i++)
    {
        new_tail = new_tail->next;
    }
    LLNode* new_head = new_tail->next;
    new_tail->next = nullptr;
    return new_head;
    // for i from 0 to length - k - 1:
    //     new_tail = new_tail.next

    // new_head = new_tail.next

    // // Break the circular list
    // new_tail.next = nullptr

    // // Return the new head
    // return new_head
}
int main() {
    int arr1[] = {2, 9};
    int arr2[] = {0, 5};
    LLNode* head1 = LLNode::createWithIterators(arr1, arr1 + sizeof(arr1) / sizeof(int));
    LLNode* head2 = LLNode::createWithIterators(arr2, arr2 + sizeof(arr2) / sizeof(int));
    LLNode* newhead = addLinkedList(head1, head2);
    LLNode::printList(newhead);
    head1->clear();
    head2->clear();
    newhead->clear();

    int arr[] = {13, 88, 60, 7, 192};
    LLNode* head = LLNode::createWithIterators(arr, arr + sizeof(arr) / sizeof(int));
    LLNode::printList(head);
    cout << "\n";
    LLNode* reversedHead = reverseLinkedList(head);
    LLNode::printList(reversedHead);
    reversedHead->clear();

    int arr3[] = {1, 2, 3, 4, 5};
    LLNode* head3 = LLNode::createWithIterators(arr3, arr3 + sizeof(arr3) / sizeof(int));
    LLNode::printList(head3);
    cout << "\n";
    LLNode* rotatedHead = rotateLinkedList(head3, 2);
    LLNode::printList(rotatedHead);
    rotatedHead->clear();

    return 0;
}