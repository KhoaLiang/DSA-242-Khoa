    // Calculate the index using the hash function
        int index = hashFunction(key, capacity);

        // Access the linked list at the computed index
        Entry* current = table[index];
        Entry* prev = nullptr;

        // Traverse the linked list to find the key
        while (current != nullptr) {
            if (current->key == key) {
                // Key found, remove the entry
                V value = current->value;
                if (prev == nullptr) {
                    // If the entry is the first node in the list
                    table[index] = current->next;
                } else {
                    // If the entry is in the middle or end of the list
                    prev->next = current->next;
                }
                delete current;
                count--; // Decrement the count
                return value;
            }
            prev = current;
            current = current->next;
        }

        // If the key is not found, throw an exception
        throw std::out_of_range("Key not found");
    }