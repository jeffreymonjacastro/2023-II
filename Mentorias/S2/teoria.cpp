#include <iostream>

using namespace std;

// Paso por valor
int sumaValor(int a, int b){
    return a + b;
}

// Paso por referencia
void sumaRef(int a, int b, int& c){
    c = a + b;
}

int main(){

// PASo POR VALOR Y REFERENCIA
//    int c;
//    sumaValor(5,6);
//    cout << c << endl;
//
//
//    int d = 0;
//    sumaRef(5, 6, d);
//    cout << d << endl;


// PUNTEROS
//    int x = 5;
//    cout << x << endl;
//
////    int& y = x;
////    y = y + 5;
////    cout << x << endl;
//
//    int* y = &x;
//    *y = *y + 5;
//    cout << x << endl;

// ARRAYS ESTÁTICOS
    int holitas[3];
    holitas[0] = 10;
    holitas[1] = 15;
    holitas[2] = 20;

    char array[4] = {'h', 'o', 'l', 'a'};

    for (int i = 0; i < 3; ++i) {
        cout << holitas[i] << ", ";
    }

    return 0;
}