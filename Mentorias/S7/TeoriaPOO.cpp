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

// HACK
//class Perro {
//private:
//    string nombre;
//    string raza;
//    int edad;
//    float talla;
//    float peso;
//public:
//    Perro(const string &nombre, const string &raza, int edad, float talla, float peso) : nombre(nombre), raza(raza), edad(edad), talla(talla),  peso(peso) {}
//
//    const string &getNombre() const {
//        return nombre;
//    }
//
//    void setNombre(const string &nombre) {
//        Perro::nombre = nombre;
//    }
//
//    const string &getRaza() const {
//        return raza;
//    }
//
//    void setRaza(const string &raza) {
//        Perro::raza = raza;
//    }
//
//    int getEdad() const {
//        return edad;
//    }
//
//    void setEdad(int edad) {
//        Perro::edad = edad;
//    }
//
//    float getTalla() const {
//        return talla;
//    }
//
//    void setTalla(float _talla) {
//        talla = _talla;
//
//    }
//
//    float getPeso() const {
//        return peso;
//    }
//
//    void setPeso(float peso) {
//        Perro::peso = peso;
//    }
//
//    virtual ~Perro() {
//
//    }
//};



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

