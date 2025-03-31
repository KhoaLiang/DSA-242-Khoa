#include <iostream>
#include <vector>

using namespace std;

int hashFunction(int key, int capacity) {
    return key % capacity;
}

template<class K, class V>
class XHashMap {
public:
    class Entry {
    public:    
        K key;
        V value;  
        Entry* next; 
        
        Entry(K key, V value, Entry* next = 0) {
            this->key = key;
            this->value = value;
            this->next = next;
        }
    };

private:
    Entry** table; // hash table
    int capacity; // size for the hash table
    int count;   

public:
    // Constructor
    XHashMap() {
        this->capacity = 10;
        this->count = 0;
        table = new Entry*[capacity];
        //reset table to 0
        for (int i = 0; i < capacity; i++) {
            table[i] = 0;  
        }
    }

    ~XHashMap(){ // Destructor
        //Remove all entries in the current map
        for(int idx=0; idx < this->capacity; idx++){
            Entry* entry = this->table[idx];
            while(entry != 0){
                Entry * next = entry->next;
                delete entry;
                entry = next;
            }
        }
        //Remove table
        delete []table;
    } 
        
    // YOUR ANSWER
    void put(int key, int value) {
        // Compute the index using the hash function
        int index = hashFunction(key, capacity);

        // Check if the key exists in the linked list at the index
        Entry* current = table[index];
        while (current != nullptr) {
            if (current->key == key) {
                // Key exists, update the value
                current->value = value;
                return;
            }
            current = current->next;
        }

        // If the key doesn't exist, create and insert a new entry at the head of the linked list
        Entry* newEntry = new Entry(key, value, table[index]);
        table[index] = newEntry;

        // Increment the count
        count++;

        // Ensure load factor by resizing if needed
        ensureLoadFactor(count);
    }

    void ensureLoadFactor(int current_size) {
        // Calculate the maximum allowed size based on the load factor (0.75 * capacity)
        int maxAllowedSize = capacity * 0.75;

        // If the current size exceeds or equals the max allowed size, trigger rehashing
        if (current_size >= maxAllowedSize) {
            int newCapacity = capacity * 1.5; // Calculate the new capacity (1.5 times the old capacity)
            rehash(newCapacity);
        }
    }

    void rehash(int newCapacity) {
        // Store the current table and capacity
        Entry** oldTable = table;
        int oldCapacity = capacity;

        // Create a new table with the new capacity and update the capacity
        table = new Entry*[newCapacity];
        capacity = newCapacity;

        // Initialize the new table with nullptr values
        for (int i = 0; i < newCapacity; i++) {
            table[i] = nullptr;
        }

        // For each index in the old table:
        for (int i = 0; i < oldCapacity; i++) {
            Entry* current = oldTable[i];
            while (current != nullptr) {
                // Recompute the new index for each entry using the new capacity
                int newIndex = hashFunction(current->key, newCapacity);

                // Insert the entry into the new table at the recomputed index
                Entry* next = current->next;
                current->next = table[newIndex];
                table[newIndex] = current;

                current = next;
            }
        }

        // Delete the old table array
        delete[] oldTable;
    }    

    V& get(K key) {
        // Calculate the index using the hash function
        int index = hashFunction(key, capacity);

        // Access and traverse the linked list at that index
        Entry* current = table[index];
        while (current != nullptr) {
            if (current->key == key) {
                // If the current entry's key matches, return its value
                return current->value;
            }
            current = current->next;
        }

        // If not found, throw an exception
        throw std::out_of_range("Key not found");
    }
    V remove(int key) {
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
    // print table method (for testing)
    void printTable() const {

        cout << "------------The hash table is shown below------------\n";
        for (int i = 0; i < capacity; i++) {
            Entry* entry = table[i];
            cout << "Index " << i << ": ";
            while (entry != 0) {
                cout << "(" << entry->key << ", " << entry->value << ") ";
                entry = entry->next;
            }
            cout << endl;
        }
        cout << "-----------------------------------------------------\n";
        
    }

};
//testcase for put, ensure, rehash
// int main() {
//     // Create an instance of XHashMap
//     XHashMap<int, int> map;

//     // Test case 1: Adding a single key-value pair
//     map.put(6, 100);
//     map.printTable();
//     // Expected output:
//     // ------------The hash table is shown below------------
//     // Index 0:
//     // Index 1:
//     // Index 2:
//     // Index 3:
//     // Index 4:
//     // Index 5:
//     // Index 6: (6, 100)
//     // Index 7:
//     // Index 8:
//     // Index 9:
//     // -----------------------------------------------------

//     // Test case 2: Adding multiple key-value pairs, including collision
//     map.put(0, 10);
//     map.put(10, 100); // Adding a key that collides with key 0
//     map.printTable();
//     // Expected output:
//     // ------------The hash table is shown below------------
//     // Index 0: (10, 100) (0, 10)
//     // Index 1:
//     // Index 2:
//     // Index 3:
//     // Index 4:
//     // Index 5:
//     // Index 6:
//     // Index 7:
//     // Index 8:
//     // Index 9:
//     // -----------------------------------------------------

//     // Test case 3: Updating an existing key
//     map.put(1, 15);
//     map.put(1, 200); // Updating the value for key 1
//     map.printTable();
//     // Expected output:
//     // ------------The hash table is shown below------------
//     // Index 0:
//     // Index 1: (1, 200)
//     // Index 2:
//     // Index 3:
//     // Index 4:
//     // Index 5:
//     // Index 6:
//     // Index 7:
//     // Index 8:
//     // Index 9:
//     // -----------------------------------------------------

//     return 0;
// }

//tc for get function
// int main() {
//     // Create an instance of XHashMap
//     XHashMap<int, int> map;

//     // Add some key-value pairs
//     map.put(6, 100);
//     map.put(0, 10);
//     map.put(10, 95); // Adding a key-value pair for key 20

//     // Test case for the get function
//     vector<int> keys = {6, 0, 10, 20}; // Includes a key that doesn't exist
//     for (int key : keys) {
//         try {
//             cout << "Value for key " << key << ": " << map.get(key) << endl;
//         } catch (std::out_of_range& e) {
//             cout << "Key " << key << ": " << e.what() << endl;
//         }
//     }

//     return 0;
// }

//tc for remove function
int main() {
    // Create an instance of XHashMap
    XHashMap<int, int> map;

    // Add some key-value pairs
    map.put(68, 57);
    map.put(92, 32);
    map.put(34, 86);
    map.put(83, 87);
    map.put(4, 74);
    map.put(56, 29);

    // Test case 1: Removing a single key
    vector<int> keys1 = {68};
    for (int key : keys1) {
        try {
            cout << "Remove for key = " << key << ", value = " << map.remove(key) << endl;
        } catch (std::out_of_range& e) {
            cout << e.what() << endl;
        }
    }

    // Test case 2: Removing multiple keys, including a key that doesn't exist
    vector<int> keys2 = {92, 51, 34};
    for (int key : keys2) {
        try {
            cout << "Remove for key = " << key << ", value = " << map.remove(key) << endl;
        } catch (std::out_of_range& e) {
            cout << e.what() << endl;
        }
    }

    // Test case 3: Removing multiple keys with some keys not present
    vector<int> keys3 = {83, 4, 77, 28, 56};
    for (int key : keys3) {
        try {
            cout << "Remove for key = " << key << ", value = " << map.remove(key) << endl;
        } catch (std::out_of_range& e) {
            cout << e.what() << endl;
        }
    }

    return 0;
}