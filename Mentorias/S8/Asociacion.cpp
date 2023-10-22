#include <iostream>

using namespace std;

class Taxi {
private:
    string marca;
public:
    Taxi(){}
    Taxi(string m){
        marca = m;
    }

    void imprimir(){
        cout << "Carro de marca " << marca;
    }

    ~Taxi(){}
};

class Chofer {
private:
    string nombre;
    Taxi carro; // FIJA
public:
    Chofer(){}
    Chofer(string name){
        nombre = name;
    }
    Chofer(string name, Taxi taxi){ // FIJA
        nombre = name;
        carro = taxi;
    }

    // Funciona como setter
    void asociar_taxi(Taxi taxi){
        carro = taxi;
    }

    void imprimir(){
        cout << "El chofer " << nombre << " usa un ";
        carro.imprimir();
    }

    ~Chofer(){}
};




int main(){
    // ASOCIACIÓN
    Taxi taxi1("Nissan");
    Chofer chofer1("Pablito", taxi1);

    chofer1.imprimir();

    Chofer chofer2("Pedrito");
    Taxi taxi2("Toyota");

    chofer2.asociar_taxi(taxi2);

    return 0;
}