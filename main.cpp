#include <stdlib.h>
#include <time.h>

//for timestamping:
#include <chrono>

#include "sorting.h"

int main(){
    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::duration;
    using std::chrono::milliseconds;

    srand (time(NULL));
    int n = 100;
    int *arr = (int *)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++){
        arr[i] = rand() % 100;
    }
    int *arr2 = (int *)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++){
        arr2[i] = rand() % 100;
    }
    sorting s;
    std::cout << "Bubble sort:\nUnsorted array: ";
    s.printArray(arr, n);

    auto bubble_t1 = high_resolution_clock::now();
    s.bubbleSort(arr, n);
    auto bubble_t2 = high_resolution_clock::now();

    std::cout << "Sorted array: ";
    s.printArray(arr, n);

    std::cout << "Bubble t1: " << bubble_t1.time_since_epoch().count() << "\n";
    std::cout << "Bubble t2: " << bubble_t2.time_since_epoch().count() << "\n";
    std::cout << "Bubble diff: " << bubble_t2.time_since_epoch().count() - bubble_t1.time_since_epoch().count() << "ms \n\n";


    std::cout << "Quick sort:\nUnsorted array: ";
    s.printArray(arr2, n);

    auto quick_t1 = high_resolution_clock::now();
    s.quickSort(arr2, n, 0, n - 1);
    auto quick_t2 = high_resolution_clock::now();
    
    std::cout << "Sorted array: ";
    s.printArray(arr2, n);

    std::cout << "Quick t1: " << quick_t1.time_since_epoch().count() << "\n";
    std::cout << "Quick t2: " << quick_t2.time_since_epoch().count() << "\n";
    std::cout << "Quick diff: " << quick_t2.time_since_epoch().count() - quick_t1.time_since_epoch().count() << "ms \n";

    return 0;
}