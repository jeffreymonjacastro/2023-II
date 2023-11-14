#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    // Escribir (Entrada)
    fstream archivo("../Mentorias/S12/archivo.txt", ios::out);

    if (!archivo.is_open()){
        cerr << "No se puede abrir el archivo";
        exit(1);
    }

    string texto;
    for (int i = 0; i < 3; ++i) {
        getline(cin, texto); // escribir en el archivo
        archivo << texto + "\n";
    }

    archivo.close();

    // Leer (Salida)
    fstream data("../Mentorias/S12/archivo.txt", ios::in);

    if(!data.is_open()){
        cerr << "No se puede abrir el archivo";
        exit(1);
    }

    vector<string> words;

    string linea, palabra;
    while(getline(data, linea)){
        // Librería sstream para manejar strings .split(' ');
        stringstream separado(linea);

        while(getline(separado, palabra, ' ')){
            words.push_back(palabra);
        }
    }

    data.close();

    for (auto i : words){
        cout << i << endl;
    }

    return 0;
}