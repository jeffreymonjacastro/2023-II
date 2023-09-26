#include <iostream>
#include <iomanip>

using namespace std;

// crear una matrix
int** crearMatrix(int filas, int columnas){
    int** matrix = new int*[filas]; // Declarar

    for (int i = 0; i < filas; ++i) {
        matrix[i] = new int[columnas];
    }

    for(int i = 0; i < filas; i++){
        for(int j = 0; j < columnas; j++){
            matrix[i][j] = rand() % 9999 + 1;
        }
    }

    return matrix;
}

// Imprimir
void imprimirMatrix(int** matrix, int filas, int columnas){
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }
}

// Imprimir matrix de char
void imprimirMatrix(char** matrix, int filas, int columnas){
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

// Liberar
void liberarMatrix(int** matrix, int filas){
    for (int i = 0; i < filas; ++i) {
        delete [] matrix[i];
    }

    delete [] matrix;
}



int main(){
    srand(time(nullptr));

    /*// Array dinámico
    int* array = new int[3]; // Declarar

    for (int i = 0; i < 3; ++i) { // Definir
        array[i] = 5;
    }

    for (int i = 0; i < 3; ++i) { // Imprimir
        cout << array[i] << " ";
    }

    cout << endl;

    delete [] array; // Liberar
*/

    /*// Matrices dinámicas
    int** matrix = new int*[3]; // Declarar

    for (int i = 0; i < 3; ++i) {
        matrix[i] = new int[3];
    }

    // Definir
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            matrix[i][j] = 5;
        }
    }

    // Imprimir
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // Liberar
    for (int i = 0; i < 3; ++i) {
        delete [] matrix[i];
    }

    delete [] matrix;
*/
//    int fil = 3, col = 4;
//
//    int** miMatriz = crearMatrix(fil,col);
//
//    imprimirMatrix(miMatriz, fil, col);
//
//    liberarMatrix(miMatriz, fil);

    // Problema de figuritas
    int fil = 4, col = 4;
    
    char** figurita = new char*[fil];

    for (int i = 0; i < fil; ++i) {
        figurita[i] = new char[col];
    }
    
    // CUIDAOOO
    for (int i = 0; i < fil; ++i) {
        for (int j = 0; j < col; ++j) {
            if (i == j || i > j)
                figurita[i][j] = '*';
            else
                figurita[i][j] = ' ';
        }
    }

    imprimirMatrix(figurita, fil, col);
    

    return 0;
}
