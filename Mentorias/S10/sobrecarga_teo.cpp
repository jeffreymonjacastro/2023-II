#include <iostream>

using namespace std;

/* SOBRECARGA DE OPERADORES

 + La sobrecarga de operadores permite que un operador tenga diferentes significados en diferentes contextos.
 + Se realiza mediante la definición de una función que se llama cuando se utiliza el operador.
 + Generalmente se utiliza en las clases

 + Existen 2 tipos operadores que se pueden sobrecargar:
    - Operadores unarios: operan sobre un solo operando.
        > incremento (++)
        > decremento (--)
        > dereferencia (*)

    - Operadores binarios: operan como máximo en dos operandos.
        Por ejemplo: operador de suma (+) y resta (-).

     + Existen 3 formas de declarar una sobrecarga de operadores:
        - Funciones miembro (método de una clase)
        - Funciones amigas (friend)
    - Funciones globales (con atributos públicos o getters)

 Sintaxis:
 Tipo_retorno operator op (parámetros){
    // Código
 }
*/


class Vector3D {
private:
    int x, y, z;
public:
    Vector3D(){};
    Vector3D(int _x, int _y, int _z) : x(_x), y(_y), z(_z) {}

    // Sobrecarga del operador ostream << con friend (Función binaria)
    friend ostream& operator<<(ostream& os, Vector3D& vec);

    // Sobrecarga del operador + como método (Función binaria)
    Vector3D operator+(Vector3D& otrovec){
        int newx = x + otrovec.x;
        int newy = y + otrovec.y;
        int newz = z + otrovec.z;

        return Vector3D(newx, newy, newz);
    }

    // Sobrecarga del operador ++ (Preincremento) como método (Función Unaria)
    void operator++(){
        ++x; // x = x + 1
        ++y;
        ++z;
    }

    // Posincremento
    void operator++(int) {
        x++;
        y++;
        z++;
    }

    // Sobrecarga del operador -- (Predecremento) como método (Función Unaria)
    void operator--(){
        --x;
        --y;
        --z;
    }

    // Posdecremento
    void operator--(int){
        x--;
        y--;
        z--;
    }


    ~Vector3D(){}
};


// Operador de salida (ostream) << como función amiga
ostream& operator<<(ostream& os, Vector3D& vec){
    os << '(' << vec.x << ", " << vec.y << ", " << vec.z << ')' << endl;
    return os;
}


// Sobrecarga del operador + (Función global)
//string operator+(string s, int x){
//    return s + to_string(x);
//}


int main(){
//    string s = "Hello World";
//    int x = 1123129312;
//
//    cout << s + x << endl;


    Vector3D vec1(1,2,3);
    Vector3D vec2(4,5,6);

    cout << vec1;
    cout << vec2;

    Vector3D vec3;
    vec3 = vec1 + vec2;

    cout << vec3;

    ++vec1;
    vec1--;

    cout << vec1;

    return 0;
}