#include <iostream>
#include <type_traits>
using namespace std;

template <class T>
class Sorting {
private:
    // Partition function using Hoare's algorithm
    static T* Partition(T* start, T* end) {
        T pivot = *start; // Choose the first element as the pivot
        T* i = start - 1;
        T* j = end + 1;

        while (true) {
            do {
                i++;
            } while (*i < pivot);

            do {
                j--;
            } while (*j > pivot);

            if (i >= j) {
                return j; // Return the split position
            }

            swap(*i, *j);
        }
    }

public:
    // QuickSort function
    static void QuickSort(T* start, T* end) {
        if (start < end) {
            T* pivot = Partition(start, end);
            cout << (pivot - start) << " "; // Print the index of the pivot

            QuickSort(start, pivot);
            QuickSort(pivot + 1, end);
        }
    }
};

int main() {
    int array[] = { 3, 5, 7, 10, 12, 14, 15, 13, 1, 2, 9, 6, 4, 8, 11, 16, 17, 18, 20, 19 };
    cout << "Index of pivots: ";
    Sorting<int>::QuickSort(&array[0], &array[19]);
    cout << "\n";

    cout << "Array after sorting: ";
    for (int i : array) {
        cout << i << " ";
    }
    cout << "\n";

    return 0;
}