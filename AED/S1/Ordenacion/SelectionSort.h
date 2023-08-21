#include <iostream>

using namespace std;

void SelectionSort(int* arr, int size){
    for(int i = 0; i < size - 1; i++){
        int posMin = i;

        for(int j = i + 1; j < size; j++){
            if (arr[j] < arr[posMin]){
                posMin = j;
            }
        }

        if (posMin != i)
            swap(arr[i] , arr[posMin]);
    }
}