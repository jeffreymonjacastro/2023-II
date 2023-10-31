#include <iostream>
#include <vector>

using namespace std;


class CArticulo {
private:
    string numSerie;
    int precio;
public:
    CArticulo(){}
    CArticulo(string num, int p){
        numSerie = num;
        precio = p;
    }

    virtual ~CArticulo(){}
};

class CObra {
protected:
    string tipo;
    string nombre;
    int epoca;
    CArticulo articulo;
public:
    CObra(){}
    CObra(string t, string n, int e, string numserie, int precio){
        tipo= t;
        nombre = n;
        epoca = e;
        articulo = CArticulo(numserie, precio);
    }

    int getEpoca(){ return epoca; }

    void imprimir(){
        cout << "nombre: " << nombre << ", epoca: " << epoca << endl;
    }

    virtual ~CObra(){}
};

class CMusica : public CObra {
private:
public:
    CMusica(){}

    virtual ~CMusica(){}
};

class CVideojuego : public CObra {
private:
    int rating;
public:
    CVideojuego(){}
    CVideojuego(int r){
        rating = r;
    }
};

class CEmpresa {
private:
    string nombre;
    vector<CObra> obras;
public:
    CEmpresa(){}
    CEmpresa(string nombre){}

    // Sobrecarga del operador <<
    void operator<< (CVideojuego& juego){
        obras.push_back(juego);
    }

    void operator<< (CObra& obra){
        obras.push_back(obra);
    }

    // Sobrecarga del ()
    void operator()(int epoca){
        for (int i = 0; i < obras.size(); ++i) {
            if (obras[i].getEpoca() == epoca){
                obras[i].imprimir();
            }
        }
    }


    virtual ~CEmpresa(){}
};



int main(){
    CEmpresa objEmpresa;
    CVideojuego objVideojuego;

    objEmpresa << objVideojuego ;

    CObra obra1("M", "Atlantis_II", 1990, "A1212", 600);

    objEmpresa << obra1;

    objEmpresa(1990);


    return 0;
}