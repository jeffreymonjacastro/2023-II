#include <iostream>
#include <vector>

using namespace std;

class Perro {
private:
    // ATTRIBUTES
    string nombre;
    int edad;
public:
    Perro(){} // Constructor por defecto
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

    // SETTER
    void setNombre(string _nombre){
        nombre = _nombre;
    }

    void setEdad(int _edad){
        edad = _edad;
    }

    // GETTER
    string getNombre(){
        return nombre;
    }

    int getEdad(){
        return edad;
    }


    // DESTRUCTOR
    ~Perro(){
//        cout << "Guau chau" << endl;
    }
};




int main(){
    // Declarar un objeto -> Llamar al constructor
    Perro perrito1;
    Perro perrito2("Bethooven", 3);
    Perro perrito3(perrito2);

    // SETTERS
    perrito1.setNombre("Firulais");
    perrito1.setEdad(4);

    // GETTERS
    cout << perrito1.getNombre() << endl;

    perrito1.comer();
    perrito2.comer();
    perrito3.comer();

    return 0;
}

