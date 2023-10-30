#include <iostream>

using namespace std;

// SUPERCLASE
class Persona {
protected: // FIJA
    string nombre;
public:
    Persona(){}
    Persona(string name){
        nombre = name;
    }

    // Función virtual default
    virtual void imprimir(){
        cout << "Hola, soy " << nombre <<endl;
    }

    virtual ~Persona(){}
};

// CLASE ABSTRACTA
//class Persona {
//protected:
//    string nombre;
//public:
//    Persona(){}
//    Persona(string name){
//        nombre = name;
//    }
//
//    // TODOS sus métodos son virtuales
//    virtual void imprimir() = 0;
//    virtual void caminar() = 0;
//
//    virtual ~Persona(){}
//};

// SUBCLASE
class Estudiante : public Persona {
private:
    string carrera;
public:
    Estudiante(){}
    // En el constructor de la clase hija se llama al constructor de la clase padre
    Estudiante(string name, string carr): Persona(name), carrera(carr){}

    void imprimir(){
        cout << "Hola, soy " << nombre << " de la carrera " << carrera << endl;
    }

    void estudiar(){
        cout << "Estudianding c++" << endl;
    }

    virtual ~Estudiante(){}
};

// SUBCLASE
class Profesor : public Persona {
private:
    string maestria;
public:
    Profesor(){}
    Profesor(string nombre, string mba): Persona(nombre), maestria(mba){};

    void trabajar(){
        cout << "Trabajanding..." << nombre << endl;
    }

    void imprimir(){
        cout << "Holis, soy " << maestria << endl;
    }

    // Si estuviera dentro, podría acceder
    friend void imprimirProfesor(Profesor profe);

    friend ostream& print(ostream& os, Profesor profe);

    virtual ~Profesor(){}
};

// FUNCIÓN AMIGA EXTERNA A LA CLASE
void imprimirProfesor(Profesor profe){
    cout << "El profe " << profe.nombre << " tiene de maestria: " << profe.maestria << endl;
}

// OTRA FUNCIÓN EXTERNA
ostream& print(ostream& os, Profesor profe){
    os << profe.nombre;
    return os;
}



int main(){
    Estudiante estudiante1("Pedrito", "CS");
    Profesor profe1("Napa", "Matematico");

    estudiante1.imprimir();
    profe1.imprimir();

    estudiante1.estudiar();
    profe1.trabajar();

    imprimirProfesor(profe1);

    print(cout, profe1);


    return 0;
}