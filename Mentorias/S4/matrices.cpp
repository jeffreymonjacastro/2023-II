#include <iostream>

using namespace std;

// Declara y define la matrix
int** createMatrix(int n, int m){
    int** matrix = new int*[n];

    for (int i = 0; i < n; ++i) {
        matrix[i] = new int[m];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            matrix[i][j] = rand()%99 + 1;
        }
    }

    return matrix;
}

// Imprime la matrix
void printMatrix(int** matrix, int n, int m){
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << matrix[i][j] << " ";
        }

        cout << endl;
    }
}

// Liberar matrix
void deleteMatrix(int** matrix, int n){
    for (int i = 0; i < n; ++i) {
        delete [] matrix[i];
    }

    delete [] matrix;

    cout << "Liberado";
}

int main(){
    // Matrices estáticas

//    int matrix[2][3] = {};
//    int matrix2[2][2] = {{1,2}, {3,4}};
//
//    for (int i = 0; i < 2; ++i) {
//        for (int j = 0; j < 2; ++j) {
//            cout << matrix[i][j] << " ";
//        }
//    }

    // Dobles punteros
//    int x = 10;
//    int* p = &x;
//
//    cout << x << endl;
//    cout << &x << endl;
//    cout << p << endl;
//    cout << *p << endl;
//
//    int** pp = &p;
//
//    cout << &p << endl;
//    cout << pp << endl;
//
//    cout << *pp << endl;
//    cout << **pp << endl;
//
//    **pp = 20;
//
//    cout << x;

    // Matrices dinámicas
    // Declarar
//    int** matrix = new int*[2]; // Filas
//
//    for (int i = 0; i < 2; ++i) { // Columnas
//        matrix[i] = new int[2];
//    }
//
//    // Definir
//    for (int i = 0; i < 2; ++i) {
//        for (int j = 0; j < 2; ++j) {
//            matrix[i][j] = 5;
//        }
//    }
//
//    for (int i = 0; i < 2; ++i) {
//        for (int j = 0; j < 2; ++j) {
//            cout << matrix[i][j] << " ";
//        }
//
//        cout << endl;
//    }
//
//
//    // Liberar memoria
//    for (int i = 0; i < 2; ++i) {
//        delete [] matrix[i];
//    }
//
//    delete [] matrix;

    int n, m;
    cout << "N, M: ";
    cin>>n>>m;

    int** miMatrix = createMatrix(n, m);

    printMatrix(miMatrix, n, m);

    deleteMatrix(miMatrix, n);

    return 0;
}
