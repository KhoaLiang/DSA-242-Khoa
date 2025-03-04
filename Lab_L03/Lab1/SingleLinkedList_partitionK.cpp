void LinkedList::partition(int k) {
    if (head == nullptr) return;

    Node* lessHead = nullptr;
    Node* lessTail = nullptr;
    Node* equalHead = nullptr;
    Node* equalTail = nullptr;
    Node* greaterHead = nullptr;
    Node* greaterTail = nullptr;

    Node* current = head;

    // Partition the list into three groups
    while (current != nullptr) {
        if (current->value < k) {
            if (lessHead == nullptr) {
                lessHead = current;
                lessTail = current;
            } else {
                lessTail->next = current;
                lessTail = current;
            }
        } else if (current->value == k) {
            if (equalHead == nullptr) {
                equalHead = current;
                equalTail = current;
            } else {
                equalTail->next = current;
                equalTail = current;
            }
        } else {
            if (greaterHead == nullptr) {
                greaterHead = current;
                greaterTail = current;
            } else {
                greaterTail->next = current;
                greaterTail = current;
            }
        }
        current = current->next;
    }

    // Combine the three groups
    if (lessTail != nullptr) {
        lessTail->next = equalHead;
    } else {
        lessHead = equalHead;
    }

    if (equalTail != nullptr) {
        equalTail->next = greaterHead;
    } else if (lessTail != nullptr) {
        lessTail->next = greaterHead;
    } else {
        lessHead = greaterHead;
    }

    if (greaterTail != nullptr) {
        greaterTail->next = nullptr;
    }

    head = lessHead;
    tail = greaterTail != nullptr ? greaterTail : (equalTail != nullptr ? equalTail : lessTail);
}