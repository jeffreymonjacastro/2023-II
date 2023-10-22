#include <iostream>
#include <vector>

using namespace std;

class Estudiante {
private:
    string nombre;
    string carrera;
public:
    Estudiante(){}
    Estudiante(string name, string carr){
        nombre = name;
        carrera = carr;
    }

    void imprimir(){
        cout << "Estudiante: " << nombre << " de la carrera: " << carrera;
    }

    ~Estudiante(){}
};

class Univ {
private:
    string nombre;
    vector<Estudiante*> estudiantes; // FIJA
public:
    Univ(){}
    Univ(string nom){
        nombre = nom;
    }

    void agregar_estudiante(Estudiante* alumno){
        estudiantes.push_back(alumno);
    }

    void imprimir(){
        cout << nombre << endl;
        cout << "Lista de estudiantes:" << endl;

        for (int i = 0; i < estudiantes.size(); ++i) {
            estudiantes[i]->imprimir();
            cout << endl;
        }
    }

    ~Univ(){}
};

int main(){
    // AGREGACIÓN
    Univ univ1("UTEC");

    int n = 3;
    for (int i = 0; i < n; ++i) {
        string nombre, carrera;
        cin>>nombre>>carrera;

        Estudiante* estud1 = new Estudiante(nombre, carrera);

        univ1.agregar_estudiante(estud1);
    }

    univ1.imprimir();

    return 0;
}
