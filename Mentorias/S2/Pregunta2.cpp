#include <iostream>

using namespace std;

void promedioPrecios(double precios[], int n, double* prom){
    for (int i = 0; i < n; ++i) {
        *prom += precios[i];
    }

    *prom /= n;

    cout << "Promedio de precios: " << *prom << endl;
}

void prodProm(double precios[], string nombres[], int n, double* prom){
    cout<<"Nombre de productos con precios mayor al promedio"<< endl;

    int count = 1;
    for (int i = 0; i < n; ++i) {
        if (precios[i] > *prom){
            cout << "Producto [" << count << "]: " << nombres[i] << endl;
        }
    }
}

void prodMayor(double precios[], string nombres[], int cantidades[], int n){
    double max = 0;
    int index = 0;

    for (int i = 0; i < n; ++i) {
        if (precios[i] > max){
            max = precios[i];
            index = i;
        }
    }

    cout << "Detalle del producto con mayor precio:" << endl;
    cout << "\tNombre: " << nombres[index] << endl;
    cout << "\tPrecio: " << precios[index] <<endl;
    cout << "\tCantidad: " << cantidades[index] << endl;
}

int main(){
    int n;
    do {
        cout << "Cantidad de productos: ";
        cin >> n;
    } while (n < 2 || n > 50);

    string nombres[n];
    double precios[n];
    int cantidades[n];

    for(int i = 0; i < n; i++){
        string nombre;
        double precio;
        int cantidad;

        cout << "PRODUCTO \t Nro [" << i+1 << "]:" << endl;
        cout << "\t Nombre: ";
        cin>>nombre;
        cout << "\t Precio: ";
        cin>>precio;
        cout << "\t Cantidad: ";
        cin>>cantidad;

        nombres[i] = nombre;
        precios[i] = precio;
        cantidades[i] = cantidad;
    }

    double promedio = 0;
    promedioPrecios(precios, n, &promedio);

    prodProm(precios, nombres, n, &promedio);

    prodMayor(precios, nombres, cantidades, n);


    return 0;
}