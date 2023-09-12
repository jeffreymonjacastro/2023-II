#include <iostream>

using namespace std;

void imprimir(int n, string lista[]){
    string* p = nullptr;
    for(int i = 0; i < n; i++){
        p = &lista[i];

        cout << *p << "\t" ;
    }

    cout << endl;
}

void moverDerecha(int n, string lista[]){
    for (int i = 0; i < n; i++){
        string* temp = &lista[6];

        for (int j = 6; j > 0; j--) {
            lista[j] = lista[j-1];
        }

        lista[0] = *temp;
        imprimir(7, lista);
    }
}

void moverIzquierda(int n, string lista[]){
    n = abs(n);
    for (int i = 0; i < n; i++){
        string* temp = &lista[0];

        for (int j = 1; j < 7; j++) {
            lista[j-1] = lista[j];
        }

        lista[6] = *temp;
        imprimir(7, lista);
    }
}

int main(){
    string BTS[7] = {"JKook", "V", "Jimin", "Jin", "Suga", "RM", "J-Hope"};

    cout << "Estado inicial:" << endl;
    imprimir(7, BTS);

    int n;
    while(true){
        cout << "Ingrese numero de rotaciones : ";
        cin>>n;

        if (n >= -7 && n <= 7)
            break;
    }

    if (n == 0)
        cout << "No hay rotaciones!" << endl;
    else if (n > 0){
        moverDerecha(n, BTS);
    } else {
        moverIzquierda(n, BTS);
    }

// EJEMPLO
//    string BTS[7] = {"JKook", "V", "Jimin", "Jin", "Suga", "RM", "J-Hope"};
//
//    string* p = nullptr;
//
//    for (int i = 0; i < 7; i++) {
//        p = &BTS[i];
//
//        cout << *p << " ";
//    }

    return 0;
}
