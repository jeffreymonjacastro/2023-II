#include "MergeSort.h"
#include "SelectionSort.h"
#include <iostream>
#include <random>
#include <chrono>

using namespace std;
using namespace std::chrono;

int* intArray(int size, int max){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(0, max);

    int* arr = new int[size];

    for(int i = 0; i < size; i++){
        arr[i] = dist(gen);
    }

    return arr;
}

template<typename T>
void printArray(T* arr, int size){
    cout << "Array: ";

    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}


int main() {
    time_point<system_clock> t_inicio, t_fin; // Para medir el tiempo de ejecucion

    int size = 1000000;
    int* array = intArray(size, 1000);

    // Inicio
    t_inicio = high_resolution_clock::now();

    SelectionSort(array, size);

    // Fin
    t_fin = high_resolution_clock::now();

    duration<double, milli> time = t_fin - t_inicio;

    cout << "Tiempo: " << time.count() << " ms" << endl;

    return 0;
}