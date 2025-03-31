#include <iostream>
#include <unordered_map>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int _val = 0, ListNode* _next = nullptr) : val(_val), next(_next) { }
};

// Merge two sorted linked lists
ListNode* mergeLists(ListNode* a, ListNode* b) {
    if (!a) return b;
    if (!b) return a;

    ListNode* head = nullptr;
    if (a->val <= b->val) {
        head = a;
        head->next = mergeLists(a->next, b);
    } else {
        head = b;
        head->next = mergeLists(a, b->next);
    }
    return head;
}

// Split the linked list into two halves
void splitList(ListNode* head, ListNode** left, ListNode** right) {
    ListNode* slow = head;
    ListNode* fast = head->next;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    *left = head;
    *right = slow->next;
    slow->next = nullptr;
}

// Sort an unsorted linked list using merge sort
ListNode* mergeSortList(ListNode* head) {
    if (!head || !head->next) return head;

    ListNode* left = nullptr;
    ListNode* right = nullptr;

    // Split the list into two halves
    splitList(head, &left, &right);

    // Recursively sort both halves
    left = mergeSortList(left);
    right = mergeSortList(right);

    // Merge the sorted halves
    return mergeLists(left, right);
}

// Helper functions for testing
ListNode* init(int* arr, int size, unordered_map<ListNode*, int>& nodeAddr) {
    if (size == 0) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    nodeAddr[head] = arr[0];
    ListNode* current = head;
    for (int i = 1; i < size; i++) {
        current->next = new ListNode(arr[i]);
        current = current->next;
        nodeAddr[current] = arr[i];
    }
    return head;
}

void printList(ListNode* head, unordered_map<ListNode*, int>& nodeAddr) {
    while (head) {
        if (nodeAddr.find(head) == nodeAddr.end()) throw "Invalid node address!";
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

void freeMem(ListNode* head) {
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

// Main function for testing
int main() {
    // Test case 1: Merging two sorted lists
    int arr1[] = {1, 3, 5, 7, 9};
    int arr2[] = {2, 4, 6, 8};
    unordered_map<ListNode*, int> nodeAddr;
    ListNode* a = init(arr1, sizeof(arr1) / 4, nodeAddr);
    ListNode* b = init(arr2, sizeof(arr2) / 4, nodeAddr);
    ListNode* merged = mergeLists(a, b);
    try {
        printList(merged, nodeAddr);
    } catch (char const* err) {
        cout << err << '\n';
    }
    freeMem(merged);

    // Test case 2: Sorting an unsorted list
    int size;
    cin >> size;
    int* array = new int[size];
    for (int i = 0; i < size; i++) cin >> array[i];
    ListNode* head = init(array, size, nodeAddr);
    ListNode* sorted = mergeSortList(head);
    try {
        printList(sorted, nodeAddr);
    } catch (char const* err) {
        cout << err << '\n';
    }
    freeMem(sorted);
    delete[] array;

    return 0;
}