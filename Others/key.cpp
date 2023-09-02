#include <iostream>

using namespace std;

const int contrasenia_empresa_inicio = 130804;//Variable global
const int contrasenia_empresa_salida = 408031;

int main(){
    int n, n2;
    char departamento;

    do {
        cout<<"Hola, para acceder a la plataforma de la empresa ingrese la contrasena: ";
        cin >> n;

    } while (n != contrasenia_empresa_inicio);

    string nombre;

    cout<<"Ingrese sus nombres y apellidos: ";
    getline(getline(cin, nombre), nombre);

    cout<<"Ingrese la inicial del departamento en que trabaja: ";
    cin>>departamento;

    float hora_trabajo = 20, verificacion_hora_soles=100, costo_fijo = 4, sueldo_supervisor =1820;

    if (departamento == 'A'){
        double sueldo = hora_trabajo*verificacion_hora_soles;
        cout<<"Su sueldo senior(a) "<<nombre<< " es "<<sueldo<<" soles. ";

    }else if (departamento == 'B'){
        double sueldo = hora_trabajo*verificacion_hora_soles + costo_fijo;
        cout<<"Su sueldo senior(a) "<<nombre<< " es "<<sueldo<<" soles. ";

    }else if (departamento == 'C'){
        double sueldo = hora_trabajo*verificacion_hora_soles + costo_fijo + sueldo_supervisor;
        cout<<"Su sueldo senior(a) "<<nombre<< " es "<<sueldo<<" soles. ";
    }

    cout<<"Para retirar el monto acerquese al banco mas cercano.\n";
    cout<<"\nContinue cerrando sesion para mantener la privacidad de sus datos" << endl;

    do {
        cout<<"Contrasenia de salida: "; cin>>n2;
    }while (n2 != contrasenia_empresa_salida);

    cout<<"Gracias por su consulta.";

    return 0;
}