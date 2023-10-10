//#include "CArreglo.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

class CArreglo {
private:
    int tam;
    int* arr;
public:
    CArreglo(){} // Constructor default
    CArreglo(int n){ // Constructor de asignación
        tam = n;

        arr = new int[n];

        for (int i = 0; i < n; ++i)
            arr[i] = rand()%49 + 1;
    }

    // Método imprimir
    void imprimir(){
        for (int i = 0; i < tam; ++i)
            cout << arr[i] << " ";
    }

    // Método suma
    int suma(){
        int total = 0;

        for (int i = 0; i < tam; ++i)
            total += arr[i];

        return total;
    }

    // Método mayor
    int mayor(){
        int mayor = arr[0];

        for (int i = 1; i < tam; ++i) {
            if (arr[i] > mayor)
                mayor = arr[i];
        }

        return mayor;
    }

    // Método menor
    int menor(){
        int menor = arr[0];

        for (int i = 1; i < tam; ++i) {
            if (arr[i] < menor)
                menor = arr[i];
        }

        return menor;
    }

    // Método cantidad de primos
    int contarPrimos(){
        int cant = 0;
        bool flag;

        for (int i = 0; i < tam; ++i) {
            int actual = arr[i];
            flag = true;

            for (int j = 2; j < actual; ++j) {
                if (actual % j == 0)
                    flag = false;
            }

            if (flag)
                cant++;
        }

        return cant;
    }

    // Destructor
    ~CArreglo(){
        delete [] arr; // Buen uso de la memoria
    }
};

int main(){
    int n;
    srand(time (nullptr));

    cout << " Numero de elementos : ";
    cin >> n;

    CArreglo a(n);

    a.imprimir();

    cout << "\n \n";
    cout << "Lasuma de todos los elementos es : " << a.suma() << "\n";
    cout << " El mayor elementos es : " << a.mayor() << "\n" ;
    cout << " El menor elemento es : " << a.menor () << "\n";
    cout << " En el arreglo hay " << a.contarPrimos() << " numeros primos \n";

    return 0;
}