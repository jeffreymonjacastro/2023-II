#include <iostream>

using namespace std;

int factorial(int n){
    if (n == 1) {
        return 1;
    }
    else {
        return n * factorial(n-1);
    }
}

int combinatoria(int n, int k){
    return (factorial(n)) / (factorial(k) * factorial(n-k));
}



int main() {
    int cantidad;

    while (true) {
        cout << "Cantidad total de alumnos: ";
        cin>>cantidad;

        if (cantidad >= 2 && cantidad <= 100){
            break;
        }
    }

    int grupos;

    while (true) {
        cout << "Cantidad de grupos: ";
        cin>>grupos;

        if (grupos <= cantidad) {
            break;
        }
    }

    int mujeres;

    while (true){
        cout << "Cantidad de chicas minima por grupo: ";
        cin>>mujeres;

        if (mujeres <= grupos){
            break;
        }
    }

    int total;
    int combinatoria1 = combinatoria(cantidad, grupos);
    int combinatoria2 = combinatoria(cantidad - mujeres, grupos);

    cout << combinatoria1 << endl;
    cout << combinatoria2 << endl;

    total = combinatoria1 - combinatoria2;

    cout << "La cantidad de grupos de " << grupos << " estudiantes que incluyen al menos" << mujeres << "estudiante mujer es: " << total;

    return 0;
}