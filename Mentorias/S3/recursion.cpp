#include <iostream>

using namespace std;

long long int factorial(int n){
    if (n == 1)
        return 1;

    return n * factorial(n-1);
}

int combinatoria(int n, int k){
    return factorial(n) / (factorial(k) * factorial(n - k));
}

int main(){
    int cantAlum;
    while(true){
        cout << "Cantidad total de alumnos: ";
        cin>>cantAlum;

        if (cantAlum <= 100 && cantAlum >=2)
            break;
    }

    int grupos;
    while(true){
        cout << "Cantidad total de grupos: ";
        cin>>grupos;

        if (grupos <= cantAlum)
            break;
    }

    int mujeres;
    while(true){
        cout << "Cantidad de mujeres: ";
        cin>>mujeres;

        if (mujeres <= grupos)
            break;
    }

    int comb1 = combinatoria(cantAlum, grupos);
    int comb2 = combinatoria(cantAlum - mujeres, grupos);

    cout << "La cantidad de grupos de " << grupos << " estudiantes que incluyen al menos " << mujeres << " estudiante mujer es: " << comb1 - comb2;


    return 0;
}