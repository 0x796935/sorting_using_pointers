#include <iostream>

#include <stdlib.h>
#include <time.h>

//for timestamping:
#include <chrono>

class cSorting {
    public:
        void bubbleSort(int *arr, int n);
        void quickSort(int *arr, int n, int left, int right);
        void printArray(int *arr, int n);
    private:
        void swap(int *a, int *b);
        int partition(int *arr, int n, int left, int right, int &pivot);
};

void cSorting::bubbleSort(int *arr, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(arr[j] > arr[j + 1]){
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void cSorting::quickSort(int *arr, int n, int left, int right){
    if(left < right){
        int pivot = partition(arr, n, left, right, pivot);
        quickSort(arr, n, left, pivot - 1);
        quickSort(arr, n, pivot + 1, right);
    }
}

int cSorting::partition(int *arr, int n, int left, int right, int &pivot){
    pivot = left;
    int i = left + 1;
    int j = right;
    while(i <= j){
        if(arr[i] <= arr[pivot]){
            i++;
        }
        else if(arr[j] > arr[pivot]){
            j--;
        }
        else{
            swap(&arr[i], &arr[j]);
            i++;
            j--;
        }
    }
    swap(&arr[pivot], &arr[j]);
    pivot = j;
    return pivot;
}


void cSorting::printArray(int *arr, int n){
    for(int i = 0; i < n; i++){
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

void cSorting::swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
