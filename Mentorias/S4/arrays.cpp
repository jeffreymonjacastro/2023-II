#include <iostream>

using namespace std;

int* arrayAleatorio(int size){
    int* arr = new int[size];

    for (int i = 0; i < size; ++i) {
        arr[i] = rand()%99 + 1;
    }

    return arr;
}

int main(){
//    int x = 5;
//    int* p = &x;
//    int* q = new int;
//
//    int* r = nullptr;
//
//    int* array = new int[10];
//
//    for (int i = 0; i < 10; ++i) {
//        array[i] = i*i;
//    }
//
//    for (int i = 0; i < 10; ++i) {
//        cout << array[i] << " ";
//    }

    int n;
    cout << "Size: ";
    cin>>n;

    int* miArray = arrayAleatorio(n);

    for (int i = 0; i < n; ++i) {
        cout << miArray[i] << " ";
    }

    delete [] miArray;

    return 0;
}
