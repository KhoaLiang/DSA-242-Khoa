#include <iostream>
using namespace std;

template <class T>
class Sorting {
public:
    /* Function to print an array */
    static void printArray(T* start, T* end) {
        long size = end - start + 1;
        for (int i = 0; i < size - 1; i++)
            cout << start[i] << ", ";
        cout << start[size - 1];
        cout << endl;
    }

    static void merge(T* left, T* middle, T* right) {
        // Sizes of the two subarrays
        int n1 = middle - left + 1;
        int n2 = right - middle;

        // Create temporary arrays
        T* L = new T[n1];
        T* R = new T[n2];

        // Copy data to temporary arrays
        for (int i = 0; i < n1; i++)
            L[i] = left[i];
        for (int j = 0; j < n2; j++)
            R[j] = middle[1 + j];

        // Merge the temporary arrays back into the original array
        int i = 0, j = 0, k = 0;
        T* current = left;
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                current[k++] = L[i++];
            } else {
                current[k++] = R[j++];
            }
        }

        // Copy remaining elements of L[], if any
        while (i < n1) {
            current[k++] = L[i++];
        }

        // Copy remaining elements of R[], if any
        while (j < n2) {
            current[k++] = R[j++];
        }

        // Print the merged array
        Sorting::printArray(left, right);

        // Free temporary arrays
        delete[] L;
        delete[] R;
    }

    static void mergeSort(T* start, T* end) {
        if (start < end) {
            // Find the middle point
            T* middle = start + (end - start) / 2;

            // Recursively sort the first and second halves
            mergeSort(start, middle);
            mergeSort(middle + 1, end);

            // Merge the sorted halves
            merge(start, middle, end);
        }
    }
};
int main(){
    int arr[] = {0, 2, 4, 3, 1, 4};
    Sorting<int>::mergeSort(&arr[0], &arr[5]);
}