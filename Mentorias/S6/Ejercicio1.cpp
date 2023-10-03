#include <iostream>
#include <vector>

using namespace std;

int** crearMatrix(int n){
    int** matrix = new int*[n];

    for (int i = 0; i < n; ++i) {
        matrix[i] = new int[n];
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            matrix[i][j] = rand() % 50 + 1;
        }
    }

    return matrix;
}

void liberarMatrix(int** matrix, int filas){
    for (int i = 0; i < filas; ++i) {
        delete [] matrix[i];
    }

    delete [] matrix;
}

void imprimirMatrix(int** matrix, int n){
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    srand(time(nullptr));

    int orden;

    while (true){
        cout << "Ingrese el orden de la matriz: " << endl;
        cin >> orden;

        if (orden >= 3)
            break;
    }

    int** matriz = crearMatrix(orden);

    vector<int> diagonal;

    for (int i = 0; i < orden; ++i) {
        for (int j = 0; j < orden; ++j) {
            if (i == j) {
                diagonal.push_back(matriz[i][j]);
            }
        }
    }

    for (int i = 0; i < orden; ++i) {
        for (int j = 0; j < orden; ++j) {
            if (i + j + 1 == orden) {
                if (orden % 2 == 0)
                    diagonal.push_back(matriz[i][j]);
                else if (i != orden/2 && j != orden/2)
                    diagonal.push_back(matriz[i][j]);
            }
        }
    }

    imprimirMatrix(matriz, orden);

    for (int i = 0; i < diagonal.size(); ++i) {
        cout << diagonal[i] << " ";
    }

    return 0;
}
