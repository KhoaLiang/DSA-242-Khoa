testcase for put, ensure, rehash
int main() {
    // Create an instance of XHashMap
    XHashMap<int, int> map;

    // Test case 1: Adding a single key-value pair
    map.put(6, 100);
    map.printTable();
    // Expected output:
    // ------------The hash table is shown below------------
    // Index 0:
    // Index 1:
    // Index 2:
    // Index 3:
    // Index 4:
    // Index 5:
    // Index 6: (6, 100)
    // Index 7:
    // Index 8:
    // Index 9:
    // -----------------------------------------------------

    // Test case 2: Adding multiple key-value pairs, including collision
    map.put(0, 10);
    map.put(10, 100); // Adding a key that collides with key 0
    map.printTable();
    // Expected output:
    // ------------The hash table is shown below------------
    // Index 0: (10, 100) (0, 10)
    // Index 1:
    // Index 2:
    // Index 3:
    // Index 4:
    // Index 5:
    // Index 6:
    // Index 7:
    // Index 8:
    // Index 9:
    // -----------------------------------------------------

    // Test case 3: Updating an existing key
    map.put(1, 15);
    map.put(1, 200); // Updating the value for key 1
    map.printTable();
    // Expected output:
    // ------------The hash table is shown below------------
    // Index 0:
    // Index 1: (1, 200)
    // Index 2:
    // Index 3:
    // Index 4:
    // Index 5:
    // Index 6:
    // Index 7:
    // Index 8:
    // Index 9:
    // -----------------------------------------------------

    return 0;
}

tc for get function
int main() {
    // Create an instance of XHashMap
    XHashMap<int, int> map;

    // Add some key-value pairs
    map.put(6, 100);
    map.put(0, 10);
    map.put(10, 95); // Adding a key-value pair for key 20

    // Test case for the get function
    vector<int> keys = {6, 0, 10, 20}; // Includes a key that doesn't exist
    for (int key : keys) {
        try {
            cout << "Value for key " << key << ": " << map.get(key) << endl;
        } catch (std::out_of_range& e) {
            cout << "Key " << key << ": " << e.what() << endl;
        }
    }

    return 0;
}