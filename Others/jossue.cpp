#include <iostream>

using namespace std;

void perimetroPoligono(int n, float* l, float* perimetro){
    *perimetro = n * (*l);
};

void areaPoligono (float perimetro, float& apotema, float* area){
    *area = (perimetro * apotema) / 2;
};

int main() {
    int cantidad, lados;
    cout << "Cantidad de poligonos regulares: ";
    cin>>cantidad;

    cout << "Numero de lados: ";
    cin>>lados;

    float apotema, tamLado, perimetro, area;

    float array[cantidad];

    for (int i = 0; i < cantidad; i++){

        cout << "Poligono " << i + 1 << endl;

        cout << "LADO (l): ";
        cin >> tamLado;

        cout << "APOTEMA (ap): ";
        cin >> apotema;

        perimetroPoligono(lados, &tamLado, &perimetro);
        areaPoligono(perimetro, apotema, &area);

        array[i] = area;
    }

    for(int i = 0; i < cantidad; i++){
        cout << "Area [" << i+1 << "]: " << array[i];
    }


    // TEORÍAA
    // int x = 5;
    // cout << x << endl;
    // cout << &x << endl;

    // int* p = &x;

    // cout << p << endl;
    // cout << *p << endl;

    // cout << &p << endl;

    // int** pp = &p;

    // cout << pp << endl;
    // cout << *pp << endl;
    // cout << **pp << endl;

    return 0;
}
