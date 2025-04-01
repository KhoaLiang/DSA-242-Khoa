#include <iostream>
#include <type_traits>
using namespace std;

template <class T>
class Sorting {
private:
    // Partition function using Hoare's algorithm
    static T* Partition(T* start, T* end) 
    {
        T p = start[0];
        int i = 0;
        int j = end - start;
        do
        {
            do
            {
                i++;
            } while (start[i] <= p);
            do
            {
                j--;
            } while (start[j] > p);
            swap(start[i], start[j]);
        } while (i < j);
        swap(start[i], start[j]);
        swap(start[0], start[j]);
        cout <<  j <<' ';
        return start + j;
    }

public:
    static void QuickSort(T* start, T* end) 
    {
        if (start >= end) return;
        T* par = Partition(start, end);    
        QuickSort(start, par);
        QuickSort(par + 1, end);
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