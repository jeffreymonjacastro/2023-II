#include <iostream>
#include <vector>

using namespace std;

// FUNCIONES POLIMÓRFICAS
// T toma el tipo de variable que recibe automáticamente
template <typename T>
T suma(T a, T b){
    return a + b;
}

template <typename T1, typename T2>
void imprimirGenerico(T1 a, T2 b) {
    cout << a << b << endl;
}

// CLASE POLIMÓRFICA

template<typename T = int>
class Figura{
private:
    T lado;
public:
    Figura(T lado){
        this->lado = lado;
    }

    void print(){
        cout << "Lado: " << lado << endl;
    }
};

// vector es una clase polimórfica
template<typename T>
class miVector {
private:
    vector<T> vec;
public:
    miVector(){}

    void push_back(T value){
        vec.push_back(value);
    }
};


int main(){
    double result;

    suma('1', '2');
    result = suma(2.5, 3.9);

    cout << result << endl;

    imprimirGenerico(9.5, 10);

    // CLases polimorficas
    Figura<double> f1(4.9);
    Figura<int> f2(5);
    Figura<string> f3("10");

    f1.print();
    f2.print();
    f3.print();

    vector<int> vec1(5);
    vector<string> vec2;

    vec1.push_back(10);

    miVector<char> nuevovec;
    nuevovec.push_back('c');

    return 0;
}
