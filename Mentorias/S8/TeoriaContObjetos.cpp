#include <iostream>
#include <vector>

using namespace std;

class Perro {
private:
    string nombre;
    int edad;
public:
    Perro(){}
    Perro(string name, int e){ // Constructor de asignación
        nombre = name;
        edad = e;
    }

    Perro(Perro& otroperro){ // Constructor de copia
        nombre = otroperro.nombre;
        edad = otroperro.edad;
    }

    // MÉTODOS
    void comer(){
        cout << nombre << " esta comiendo..." << endl;
    }
    void ladrar(){}
    void correr(){}

    void imprimir(){
        cout << "Me llamo " << nombre << " y tengo " << edad << " anios.";
    }

    ~Perro(){}
};


int main(){
    //OBJETOS DINÁMICOS

    // Objeto estático
    Perro perronormal("Laika", 3);

    // Objeto dinámico - Asignación
    Perro* perrito1 = new Perro("Bethooven", 10);
    auto perrito2 = new Perro("Firulais", 5);

    // Objeto dinámico - Por defecto
    auto perrito3 = new Perro;

    perrito1->comer();

    // Array de Objetos estáticos
    Perro* perros = new Perro[3];
    perros[0] = perronormal;

    // Vector de Objetos dinámicos
    vector<Perro*> perros2;

    perros2.push_back(perrito1);
    perros2.push_back(perrito2);
    perros2.push_back(perrito3);

    // ejemplo aplicativo
    int n = 2;
    vector<Perro*> perros3;

    for (int i = 0; i < n; ++i) {
        string name;
        int age;
        cout << "Nombre: ";
        cin>>name;
        cout << "Edad: ";
        cin>>age;

        auto perrito = new Perro(name, age);
        perros3.push_back(perrito);
    }

    for (int i = 0; i < perros3.size(); ++i) {
        perros3[i]->imprimir();
    }


    return 0;
}