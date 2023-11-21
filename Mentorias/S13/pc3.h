#ifndef INC_2023_II_PC3_H
#define INC_2023_II_PC3_H

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const double PI = 3.14159;

class FiguraCurvada {
protected:
    int radio;
public:
    FiguraCurvada(){}
    FiguraCurvada(int r){
        radio = r;
    }

    virtual double area() = 0;

    virtual double volumen() = 0;

    virtual string imprimir() = 0;

    virtual ~FiguraCurvada(){}
};

class CCilindro: public FiguraCurvada {
private:
    int altura;
public:
    CCilindro(){}
    CCilindro(int r, int h);

    double area();

    double volumen();

    string imprimir();

    virtual ~CCilindro(){}
};

class CCono: public FiguraCurvada {
private:
    int altura;
public:
    CCono(){}

    CCono(int r, int h): altura(h), FiguraCurvada(r){}

    double area(){
        return PI*radio * sqrt((radio*radio) +(altura * altura)) + PI * radio * radio;
    }

    double volumen(){
        return (PI/3) * radio * radio * altura;
    }

    string imprimir(){
        string fig;

        fig += "Cono \n";
        fig += "Radio : " + to_string(radio) + ", altura : " + to_string(altura) + "\n";
        fig += "Volumen : " + to_string(volumen()) + "\n";
        fig += "Area : " + to_string(area()) + "\n";

        return fig;
    }

    virtual ~CCono(){}
};

class CEsfera: public FiguraCurvada {
private:

public:
    CEsfera(){}
    CEsfera(int r): FiguraCurvada(r){}

    double area(){
        return 4 * PI * radio * radio;
    }

    double volumen(){
        return (4*PI / 3) * pow(radio, 3);
    }

    string imprimir(){
        string fig;

        fig += "Esfera \n";
        fig += "Radio : " + to_string(radio) + "\n";
        fig += "Volumen : " + to_string(volumen()) + "\n";
        fig += "Area : " + to_string(area()) + "\n";

        return fig;
    }

    virtual ~CEsfera(){}
};

class CToro: public FiguraCurvada {
private:
    int radioR;
public:
    CToro(){}
    CToro(int r, int rR): radioR(rR), FiguraCurvada(r){}

    double area(){
        return 4 * (PI*PI) * radio * radioR;
    }

    double volumen(){
        return 2* (PI*PI) * (radio * radio) * radioR;
    }

    string imprimir(){
        string fig;

        fig += "Toro \n";
        fig += "Radio : " + to_string(radio) + ", Radio 2 : " + to_string(radioR) + "\n";
        fig += "Volumen : " + to_string(volumen()) + "\n";
        fig += "Area : " + to_string(area()) + "\n";

        return fig;
    }

    virtual ~CToro(){}
};

class CVector {
private:
    vector<FiguraCurvada*> figuras;
public:
    CVector(){}

    void agregar(FiguraCurvada* fig){
        figuras.push_back(fig);
    }

    friend ostream& operator<<(ostream &o, CVector& vector);

    ~CVector(){}
};



#endif //INC_2023_II_PC3_H
