#ifndef INC_2023_II_VEC_H
#define INC_2023_II_VEC_H

#include <iostream>
#include <sstream>

using namespace std;


template<typename T>
class Vec {
private:
    int size;
    int capacity;
    T* array;
public:
    // Constructor por defecto
    Vec(){
        array = nullptr;
        capacity = 0;
        size = 0;
    }

    // Constructor con el tamaño del array
    Vec(int size){
        array = new T[size];
        capacity = size;
        this->size = 0;
    }

    // Constructor con el tamaño del array y el dato que tiene
    Vec(int size, T elem){
        array = new T[size];
        for (int i = 0; i < size; i++) {
            array[i] = elem;
        }

        this->size = size;
        capacity = size;
    }

    // Constructor con varios datos para ingresar
    template <typename... Ts>
    Vec(Ts... values){
        capacity = sizeof...(values);
        array = new T[capacity];
        size = 0;

        (..., (array[size++] = values));
    }

    // Método para ingresar un valor al final del array
    void push_back(T value){
        if (size != capacity) {
            array[size++] = value;
            return;
        }

        if (capacity == 0) {
            array = new T[capacity];
            capacity++;
            array[size++] = value;
            return;
        }

        T* temp = new T[capacity * 2];
        for (int i = 0; i < capacity; ++i) {
            temp[i] = array[i];
        }

        array = temp;
        capacity *= 2;

        array[size++] = value;
    }

    // Método para eliminar el último valor del array
    void pop_back(){
        if (size == 0)
            throw out_of_range("Array is empty");

        --size;
    }

    // Método para vaciar el vector
    void clear(){
        size = 0;
        capacity = 0;
        delete [] array;
        array = nullptr;
    }

    // SOBRECARGAS
    // Sobrecarga del operador []
    T& operator[](int index){
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of range");
        }
        return array[index];
    }

    // Sobrecarga del operador +

    // Sobrecarga del operador -

    // Sobrecarga del operador *

    // Sobrecarga del operador /

    // Sobrecarga del operador =

    // Sobrecarga del operador ==

    // Sobrecarga del operador !=

    // Sobrecarga del operador <

    // Sobrecarga del operador >

    // Sobrecarga del operador ++

    // Sobrecarga del operador --

    // Sobrecarga del operador <<
    friend ostream& operator<<(ostream& os, Vec& vec){
        if (vec.size == 0) return os;

        os << "[";
        for (int i = 0; i < vec.size - 1; i++) {
            os << vec.array[i] << ",";
        }
        os << vec.array[vec.size - 1] << "]" << endl;
        return os;
    }

    // Sobrecarga del operador >>
    friend istream& operator>>(istream& is, Vec& vec){
        vec.clear();

        T value;

        string input;
        getline(is, input);

        istringstream iss(input);
        while (iss >> value) {
            vec.push_back(value);
        }

        return is;
    }

    ~Vec(){
        delete [] array;
    }
};



#endif //INC_2023_II_VEC_H
