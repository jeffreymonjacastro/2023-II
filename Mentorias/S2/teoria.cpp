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
//    int c;
//    sumaValor(5,6);
//    cout << c << endl;
//
//
//    int d = 0;
//    sumaRef(5, 6, d);
//    cout << d << endl;



    int x = 5;
    cout << x << endl;

//    int& y = x;
//    y = y + 5;
//    cout << x << endl;

    int* y = &x;
    *y = *y + 5;
    cout << x << endl;


    return 0;
}