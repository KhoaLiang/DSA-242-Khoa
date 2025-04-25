#include <iostream>
#include <queue>
using namespace std;
template <class T>
class Sorting {
public:
    /* Function to print an array */
    static void printArray(T *start, T *end)
    {
        long size = end - start;
        for (int i = 0; i < size - 1; i++)
            cout << start[i] << ", ";
        cout << start[size - 1];
        cout << endl;
    }

    // Helper function to heapify a subtree rooted at index `index`
    static void reheapDown(T* arr, int size, int index) {
        int largest = index; // Assume the current index is the largest
        int leftChild = 2 * index + 1; // Left child index
        int rightChild = 2 * index + 2; // Right child index

        // Check if the left child exists and is greater than the current largest
        if (leftChild < size && arr[leftChild] > arr[largest]) {
            largest = leftChild;
        }

        // Check if the right child exists and is greater than the current largest
        if (rightChild < size && arr[rightChild] > arr[largest]) {
            largest = rightChild;
        }

        // If the largest is not the current index, swap and continue heapifying
        if (largest != index) {
            swap(arr[index], arr[largest]);
            reheapDown(arr, size, largest); // Recursively heapify the affected subtree
        }
    }

    // Function to perform heap sort
    static void heapSort(T* start, T* end) {
        int size = end - start;

        // Step 1: Build a max heap
        for (int i = size / 2 - 1; i >= 0; i--) {
            reheapDown(start, size, i);
        }

        // Step 2: Extract elements from the heap one by one
        for (int i = size - 1; i > 0; i--) {
            swap(start[0], start[i]); // Move the current root to the end
            reheapDown(start, i, 0); // Restore the heap property for the reduced heap
        }

        // Print the sorted array
        Sorting<T>::printArray(start, end);
    }
};