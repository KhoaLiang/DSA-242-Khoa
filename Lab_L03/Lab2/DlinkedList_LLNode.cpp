// Given the head of a doubly linked list, two positive integer a and b where a <= b. Reverse the nodes of the list from position a to position b and return the reversed list

// Note: the position of the first node is 1. It is guaranteed that a and b are valid positions. You MUST NOT change the val attribute in each node.

// struct ListNode {
//     int val;
//     ListNode *left;
//     ListNode *right;
//     ListNode(int x = 0, ListNode *l = nullptr, ListNode* r = nullptr) : val(x), left(l), right(r) {}
// };

// Constraint:
// 1 <= list.length <= 10^5
// 0 <= node.val <= 5000
// 1 <= left <= right <= list.length

// Example 1:
// Input: list = {3, 4, 5, 6, 7} , a = 2, b = 4
// Output: 3 6 5 4 7

// Example 2:
// Input: list = {8, 9, 10}, a = 1, b = 3
// Output: 10 9 8

// For example:

// Test	Input	Result
// int size;
//     cin >> size;
//     int* list = new int[size];
//     for(int i = 0; i < size; i++) {
//         cin >> list[i];
//     }
//     int a, b;
//     cin >> a >> b;
//     unordered_map<ListNode*, int> nodeValue;
//     ListNode* head = init(list, size, nodeValue);
//     ListNode* reversed = reverse(head, a, b);
//     try {
//         printList(reversed, nodeValue);
//     }
//     catch(char const* err) {
//         cout << err << '\n';
//     }
//     freeMem(head);
//     delete[] list;
// 5
// 3 4 5 6 7
// 2 4 
// 3 6 5 4 7 
// int size;
//     cin >> size;
//     int* list = new int[size];
//     for(int i = 0; i < size; i++) {
//         cin >> list[i];
//     }
//     int a, b;
//     cin >> a >> b;
//     unordered_map<ListNode*, int> nodeValue;
//     ListNode* head = init(list, size, nodeValue);
//     ListNode* reversed = reverse(head, a, b);
//     try {
//         printList(reversed, nodeValue);
//     }
//     catch(char const* err) {
//         cout << err << '\n';
//     }
//     freeMem(head);
//     delete[] list;
// 3
// 8 9 10
// 1 3
// 10 9 8 


/*
struct ListNode {
    int val;
    ListNode *left;
    ListNode *right;
    ListNode(int x = 0, ListNode *l = nullptr, ListNode* r = nullptr) : val(x), left(l), right(r) {}
};
*/

ListNode* reverse(ListNode* head, int a, int b) {
    if (!head || a == b) return head;

    ListNode* current = head;
    ListNode* start = nullptr;
    ListNode* end = nullptr;
    ListNode* prev = nullptr;
    ListNode* next = nullptr;

    int pos = 1;
    while (current && pos <= b) {
        if (pos < a) {
            prev = current;
        }
        if (pos == a) {
            start = current;
        }
        if (pos == b) {
            end = current;
            next = current->right;
        }
        current = current->right;
        pos++;
    }

    // Reverse the sublist from position a to b
    ListNode* prevNode = next;
    current = start;
    while (current != next) {
        ListNode* temp = current->right;
        current->right = prevNode;
        if (prevNode) {
            prevNode->left = current;
        }
        prevNode = current;
        current = temp;
    }

    if (prev) {
        prev->right = end;
        end->left = prev;
    } else {
        head = end;
    }

    start->right = next;
    if (next) {
        next->left = start;
    }

    return head;
}