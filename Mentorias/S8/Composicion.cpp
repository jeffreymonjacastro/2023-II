#include <iostream>

using namespace std;

class Lugar {
// Añadir más
};

class Fecha{
private:
    string dia;
    string mes;
    int anio;
public:
    Fecha(){}
    Fecha(string dia, string mes, int anio){
        this->dia = dia;
        this->mes = mes;
        this->anio = anio;
    }

    void imprimir(){
        cout << "Dia: " << dia << ", Mes: " << mes << ", Anio: " << anio;
    }

    ~Fecha(){}
};

class Evento{
private:
    string nombre_evento;
    Fecha fecha_evento; // FIJA
public:
    Evento(){}
    Evento(string nombre, string dia, string mes, int anio){
        nombre_evento = nombre;
        fecha_evento = Fecha(dia, mes, anio); // FIJA
    }

    void imprimir(){
        cout << "El evento " << nombre_evento << " tiene de fecha: " << endl;
        fecha_evento.imprimir();
    }

    ~Evento(){}
};



int main(){
    // COMPOSICIÓN
    Evento evento1("mentoria_Progra", "martes", "octubre", 2023);

    evento1.imprimir();

    return 0;
}