#ifndef SORTING_H
#define SORTING_H

#include <sstream>
#include <iostream>
#include <type_traits>
using namespace std;

template <class T>
class Sorting {
private:
    static void printArray(T* start, T* end)
    {
        int size = end - start;
        for (int i = 0; i < size; i++)
            cout << start[i] << " ";
        cout << endl;
    }

public:
    static void sortSegment(T* start, T* end, int segment_idx, int cur_segment_total);
    static void ShellSort(T* start, T* end, int* num_segment_list, int num_phases);
};

template <class T>
void Sorting<T>::sortSegment(T* start, T* end, int segment_idx, int cur_segment_total) {
    // Pseudocode:
    // for i from segment_idx to end with step cur_segment_total:
    //     key = start[i]
    //     j = i - cur_segment_total
    //     while j >= segment_idx and start[j] > key:
    //         start[j + cur_segment_total] = start[j]
    //         j = j - cur_segment_total
    //     start[j + cur_segment_total] = key

    int n = end - start;
    for (int i = segment_idx + cur_segment_total; i < n; i += cur_segment_total) {
        T key = start[i];
        int j = i - cur_segment_total;
        while (j >= segment_idx && start[j] > key) {
            start[j + cur_segment_total] = start[j];
            j -= cur_segment_total;
        }
        start[j + cur_segment_total] = key;
    }
}

template <class T>
void Sorting<T>::ShellSort(T* start, T* end, int* num_segment_list, int num_phases) {
    // Pseudocode:
    // for k from 0 to num_phases - 1:
    //     num_segments = num_segment_list[k]
    //     for segment_idx from 0 to num_segments - 1:
    //         sortSegment(start, end, segment_idx, num_segments)
    //     printArray(start, end)

    for (int k = num_phases - 1; k >= 0; k--) {
        int num_segments = num_segment_list[k];
        for (int segment_idx = 0; segment_idx < num_segments; segment_idx++) {
            sortSegment(start, end, segment_idx, num_segments);
        }
        cout << num_segments << " segments: ";
        printArray(start, end);
    }
}

#endif /* SORTING_H */

int main() {
    int arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int num_segment_list[] = {1, 3, 5}; // Example segment list
    int num_phases = 3;
    Sorting<int>::ShellSort(&arr[0], &arr[10], num_segment_list, num_phases);
    return 0;
}