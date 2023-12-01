#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

class CCliente {
public:
    string TipoCliente;

    CCliente(){}
    CCliente(string TP){
        TipoCliente = TP;
    }

    virtual ~CCliente(){}

    virtual string getnombre() = 0;
    virtual string getdocid() = 0;
};

class CClienteNatural: public CCliente {
public:
    string Nombre;
    string Apellido;
    string DNI;

    CClienteNatural(){}

    CClienteNatural(string n, string a, string dni): Nombre(n), Apellido(a), DNI(dni), CCliente("Cliente Natural"){}

    virtual ~CClienteNatural(){}

    string getnombre(){
        return Nombre;
    }

    string getdocid(){
        return DNI;
    }
};

class CClienteEmpresa: public CCliente {
public:
    string Nombre;
    string RUC;

    CClienteEmpresa(){}
    CClienteEmpresa(string n, string ruc): Nombre(n), RUC(ruc), CCliente("Cliente Empresa"){}

    virtual ~CClienteEmpresa(){}

    string getnombre(){
        return Nombre;
    }

    string getdocid(){
        return RUC;
    }
};

class CPasajero {
public:
    string Nombre;
    string Apellido;
    string DNI;

    CPasajero(){}
    CPasajero(string n, string a, string dni){
        Nombre = n;
        Apellido = a;
        DNI = dni;
    }

    void imprimir(){
        cout << "Nombre: " << Nombre << endl;
        cout << "Apellido: " << Apellido << endl;
        cout << "DNI: " << DNI << endl;
    }

    ~CPasajero(){}
};

class CPromocion {
public:
    string CiudadOrigen;
    string CiudadDestino;
    string TipoTransporte;
    string NombreEmpresaTransporte;
    string HoraSalida;
    double Precio;

    CPromocion(){}
    CPromocion(string CO, string CD, string TT, string NE, string HS, string P){
        CiudadOrigen = CO;
        CiudadDestino = CD;
        TipoTransporte = TT;
        NombreEmpresaTransporte = NE;
        HoraSalida = HS;
        Precio = stod(P);
    }

    void imprimir(){
        cout << CiudadOrigen << "-" << CiudadDestino << "-" << TipoTransporte << "-" << NombreEmpresaTransporte << "-" << HoraSalida << "-" << Precio;
    }

    void imprimirFinal(){
        cout << "Ciudad Origen: " << CiudadOrigen << endl;
        cout << "Ciudad Destino: " << CiudadDestino << endl;
        cout << "Tipo Transporte: " << TipoTransporte << endl;
        cout << "Empresa Transporte: " << NombreEmpresaTransporte << endl;
        cout << "Hora Salida: " << HoraSalida << endl;
    }


    double getPrecio(){
        return Precio;
    }

    ~CPromocion(){}
};

class CListaPromos {
public:
    vector<CPromocion> lista;

    CListaPromos(){}
    ~CListaPromos(){}

    void imprimirPromociones(){
        for (int i = 0; i < lista.size(); ++i) {
            cout << i+1 << ":";
            lista[i].imprimir();
            cout << endl;
        }
    }

    void operator<<(string nombre){
//        CListaPromos promociones;

        string ruta = "../Others/" + nombre + ".txt";

        // El obj fstream se llama data y lee el archivo en la ruta con el modo de lectura (ios::in)
        fstream data(ruta, ios::in);

        // Verificar que se haya abierto el archivo
        if(!data.is_open()){
            cerr << "No se puede abrir el archivo";
            exit(1);
        }

        // dp = Datos_Promo
        vector<string> dp(6);

        // Recorremos nuestra data
        string linea, palabra;
        while(getline(data, linea)) {
            stringstream separado(linea);

            int i = 0;
            while(getline(separado, palabra, ',')){
                dp[i] = palabra;
                i++;
            }

            CPromocion promo(dp[0], dp[1], dp[2], dp[3], dp[4], dp[5]);

            lista.push_back(promo);
        }

//        return promociones;
    }
};

class CReserva {
public:
    CPromocion promocion;
    CCliente* cliente;
    CPasajero pasajero;
    string Fecha_viaje;
    double Precio_total;

    CReserva(){}
    CReserva(CPromocion promo, CCliente* client, CPasajero pas, string fecha, double precio){
        promocion = promo;
        cliente = client;
        pasajero = pas;
        Fecha_viaje = fecha;
        Precio_total = precio;
    }

    void imprimir(){
        cout << "----------------" << endl;
        cout << "Resumen:" << endl;
        cout << "----------------" << endl;

        promocion.imprimirFinal();

        cout << "----------------" << endl;
        cout << "Pasajero:" << endl;
        cout << "----------------" << endl;

        pasajero.imprimir();

        cout << "Total a pagar:" << Precio_total << endl;

        cout << "Pagado por: " << cliente->getnombre() << endl;

        cout << "Id del Pagador: DNI: " << cliente->getdocid() << endl;
    }

    ~CReserva(){}
};


int main(){
    CListaPromos promociones;

    promociones << "promociones";

    cout << "Lista De Promociones" << endl;
    cout << "----------------------------" << endl;

    promociones.imprimirPromociones();

    cout << endl;

    int opcion;
    cout << "Elija la opcion a reservar" << endl;
    cin >> opcion;

    CPromocion promo_escogida = promociones.lista[opcion - 1];

    cout << endl;

    cout << "Ingrese fecha de viaje" << endl;
    string fecha_viaje;
    cin>>fecha_viaje;

    cout << "----- Datos Pasajero: -----" << endl;

    string nombre, apellido, dni;

    cout << "Ingrese nombre pasajero" << endl;
    cin>>nombre;

    cout << "Ingrese apellido pasajero" << endl;
    cin>>apellido;

    cout << "Ingrese dni pasajero" << endl;
    cin>>dni;

    cout << endl;

    CPasajero pasajero(nombre, apellido, dni);

    cout << "Ingresar tipo cliente pagador: (Persona: 1) o (Empresa: 2)" << endl;

    cin>>opcion;

    cout << endl;

    if (opcion == 1){
        auto cliente = new CClienteNatural(nombre, apellido, dni);

        CReserva reserva(promo_escogida, cliente, pasajero, fecha_viaje, promo_escogida.getPrecio());

        reserva.imprimir();

    } else if (opcion == 2){
        string nombre_empresa, ruc;
        cout << "Ingrese nombre empresa" << endl;
        cin>>nombre_empresa;

        cout << "Ingrese RUC empresa" << endl;
        cin>>ruc;

        auto cliente = new CClienteEmpresa(nombre_empresa, ruc);

        CReserva reserva(promo_escogida, cliente, pasajero, fecha_viaje, promo_escogida.getPrecio());

        reserva.imprimir();
    }

    return 0;
}