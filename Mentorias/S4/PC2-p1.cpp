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
#include <cstdlib>
#include <ctime>

using namespace std;


void imprim(int* arr, int n){
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

int suma(int x){
    return x + 4;
}

void sumaP(int* arr, int n) {
    int suma = 0;
    for (int j = 0; j < n; j++) {
        suma += arr[j];
        arr[j] = suma;
    }
}

void ordenamiento(int* arr, int k) {
    for (int i = 0; i < k - 1; i++) {
        for (int j = i + 1; j < k; j++) {
            if (arr[j] > arr[i]) {
                swap(arr[i], arr[j]);
            }
        }
    }
}

void scanLeft(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = suma(arr[i]);
    }

    sumaP(arr, n);
}

void scanRight(int* arr, int n) {
    for (int i = n - 1; i >= 0; i--) {
        arr[i] = suma(arr[i]);
    }

    for (int i = n - 2; i >= 0; i--) {
        arr[i] += arr[i + 1];
    }
}

int main() {
    srand(time(nullptr));
    int N;
    cout << "Ingrese N: ";
    cin >> N;

    int* arr = new int[N];

    for (int j = 0; j < N; j++) {
        arr[j] = rand() % 10 + 1;
    }

    cout<<"Array: \n";

    imprim(arr,N);

    sumaP(arr, N);
    cout << "Suma de prefijos: \n ";
    imprim(arr, N);

    ordenamiento(arr, N);
    cout << "Ordenamiento: \n";
    imprim(arr, N);

    scanLeft(arr, N);
    cout << "Scan-left: \n";
    imprim(arr, N);

    scanRight(arr, N);
    cout << "Scan-right: \n";
    imprim(arr, N);

    delete[] arr;

    return 0;
}