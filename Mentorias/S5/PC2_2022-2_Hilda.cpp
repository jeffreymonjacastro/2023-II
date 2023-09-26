#include <iostream>
#include <iomanip>

using namespace std;

int** crearMatrix(int tamanio){
    int** matrix = new int*[tamanio]; // Declarar

    for (int i = 0; i < tamanio; ++i) {
        matrix[i] = new int[tamanio];
    }

    // Definimos
    for(int i = 0; i < tamanio; i++){
        for(int j = 0; j < tamanio; j++){
            if (i == j)
                matrix[i][j] = 0;
            else
                matrix[i][j] = rand() % 9 + 1;
        }
    }

    return matrix;
}

// Imprimir
void imprimirMatrix(int** matrix, int tamanio){
    for (int i = 0; i < tamanio; ++i) {
        for (int j = 0; j < tamanio; ++j) {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }
}

// invertir triángulos
int** invTriMatriz(int** original, int tamanio){
    int** matrizInvert = new int*[tamanio];

    for (int i = 0; i < tamanio; ++i) {
        matrizInvert[i] = new int[tamanio];
    }

    // Definimos
    for (int i = 0; i < tamanio; ++i) {
        for (int j = 0; j < tamanio; ++j) {
            matrizInvert[j][i] = original[i][j];
        }
    }

    return matrizInvert;
}


// Liberar
void liberarMatrix(int** matrix, int tamanio){
    for (int i = 0; i < tamanio; ++i) {
        delete [] matrix[i];
    }

    delete [] matrix;
}

int main(){
    srand(time(nullptr));

    int n;
    while(true){
        cout << "N [ mayor a 4 ] = ";
        cin >> n;

        if (n > 4) break;
    }

    int** matriz1 = crearMatrix(n);

    cout << "Matriz 1" << endl;
    imprimirMatrix(matriz1, n);

    int** matriz2 = invTriMatriz(matriz1, n);

    cout << "Matriz 2" << endl;
    imprimirMatrix(matriz2, n);

    // Liberar memoria
    liberarMatrix(matriz1, n);
    liberarMatrix(matriz2, n);

    return 0;
}
