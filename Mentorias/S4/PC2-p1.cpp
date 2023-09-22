//#include <iostream>
//
//using namespace std;
//
//int** createMatrix(int filas, int columnas){
//    int** matrix = new int*[filas];
//
//    for (int i = 0; i < filas; ++i) {
//        matrix[i] = new int[columnas];
//    }
//
//    for (int i = 0; i < filas; ++i) {
//        for (int j = 0; j < columnas; ++j) {
//            matrix[i][j] = rand()%98 + 1;
//        }
//    }
//
//    return matrix;
//}
//
//
//void printMatrix(int** matrix, int fil, int col){
//    for (int i = 0; i < fil; ++i) {
//        for (int j = 0; j < col; ++j) {
//            cout << matrix[i][j] << " ";
//        }
//
//        cout << endl;
//    }
//}
//
//
//void deleteMatrix(int** matrix, int n){
//    for (int i = 0; i < n; ++i) {
//        delete [] matrix[i];
//    }
//
//    delete [] matrix;
//
//    cout << "Liberado";
//}
//
//int** multiploDeTres(int** matrix, int fil, int col){
//    int** newMatrix = new int*[fil];
//
//    for (int i = 0; i < fil; ++i) {
//        newMatrix[i] = new int[col];
//    }
//
//    for (int i = 0; i < fil; ++i) {
//        for (int j = 0; j < col; ++j) {
//            if(matrix[i][j] % 3 == 0) {
//                newMatrix[i][j] = matrix[i][j];
//            } else {
//                newMatrix[i][j] = 0;
//            }
//        }
//    }
//
//    return newMatrix;
//}
//
//int main(){
//    int opcion;
//
//    while(true){
//        cout << "----- MENU MATRICES -----" << endl;
//        cout << "1. Generar matriz" << endl;
//        cout << "2. Detectar multiplos de 3" << endl;
//        cout << "3. Salir" << endl;
//        cin>>opcion;
//
//        int fil, col;
//        int** matriz;
//
//        if (opcion == 1){
//
//            cout << "Filas y columnas: ";
//            cin >> fil >> col;
//
//            matriz = createMatrix(fil, col);
//
//            printMatrix(matriz, fil, col);
//
//        } else if (opcion == 2){
//            cout << "La matriz con valores multiplos de 3 es: " << endl;
//
//            int** newMatrix = multiploDeTres(matriz, fil, col);
//
//            printMatrix(newMatrix, fil, col);
//
//        }
//
//        if (opcion == 3) {
//            deleteMatrix(matriz, fil);
//            break;
//        }
//    }
//
//    return 0;
//}


#include <iostream>

using namespace std;

int main(){
    srand(time(nullptr));
//    int* arr = new int[5]{1,2,3,4,5};
//
//    cout << arr << endl;
//    cout << &arr[0] << endl;

    int filas = 10, columnas = 10;

    int** matrix = new int*[filas];

    for (int i = 0; i < filas; ++i) {
        matrix[i] = new int[columnas];
    }

    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            matrix[i][j] = rand() % 9 + 1;
        }
    }

    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            cout << matrix[i][j] << " ";
        }

        cout << endl;
    }

    cout << &matrix[0][0] << endl; // Dirección del primer elemento del primer array
    cout << matrix[0] << endl; // Valor del primer elemento de la matriz

    cout << &matrix[0] << endl;
    cout << matrix << endl;

//    **matrix = 100;
//
//    for (int i = 0; i < filas; ++i) {
//        for (int j = 0; j < columnas; ++j) {
//            cout << matrix[i][j] << " ";
//        }
//
//        cout << endl;
//    }

}