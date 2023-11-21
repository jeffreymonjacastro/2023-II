#include "pc3.h"

CCilindro::CCilindro(int r, int h): altura(h), FiguraCurvada(r) {}

double CCilindro::area(){
    return (2*PI*radio*altura) + (2*PI*radio*radio);
}

double CCilindro::volumen() {
    return PI * radio * radio * altura;
}

string CCilindro::imprimir() {
    string fig;

    fig += "Cilindro \n";
    fig += "Radio : " + to_string(radio) + ", altura : " + to_string(altura) + "\n";
    fig += "Volumen : " + to_string(volumen()) + "\n";
    fig += "Area : " + to_string(area()) + "\n";

    return fig;
}

ostream& operator<<(ostream &o, CVector& vector){
    for (int i = 0; i < vector.figuras.size(); i++) {
        o << "Figura # " << i + 1 << ":" << endl;
        o << vector.figuras[i]->imprimir();
        o << "------------------------------" << endl;
        o << endl;
    }

    return o;
}