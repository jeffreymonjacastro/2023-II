#ifndef INC_2023_II_MYVEC_H
#define INC_2023_II_MYVEC_H

#include <iostream>

using namespace std;

template<typename T>
class Myvec {
private:
    int size;      // Cantidad de elementos
    int capacity;  // Capacidad total
    T* array;      // Nuestro array de elementos
public:
    // Constructor por defecto
    Myvec(){
        size = 0;
        capacity = 0;
        array = nullptr; // array vacío
    }

    // Constructor con el capacity
    Myvec(int cap){
        size = 0;
        capacity = cap;
        array = new T[cap]; // array con size
    }

    // Constructor con capacity y elemento
    Myvec(int cap, T value){
        size = cap;
        capacity = cap;
        array = new T[cap];

        for (int i = 0; i < cap; ++i) {
            array[i] = value;
        }
    }

    // MÉTODOS
    // Ingresar un elemento al final de la lista
    void push_back(T val){
        array[size] = val;
        size++;
    }

    // Elimiar el elemento al final de la lista
    void pop_back(){
        if (array == nullptr)
            return;

        size--;
    }

    // Getter
    int Size(){
        return size;
    }

    // SOBRECARGAS
    // Sobrecargar el +
    Myvec operator+(Myvec otrovec){
        Myvec nuevovec(capacity);

        for (int i = 0; i < capacity; ++i) {
            nuevovec.push_back(array[i] + otrovec[i]);
        }

        return nuevovec;
    }

    // Sobrecargar el *

    // Sobrecargar el ++

    // Sobrecargar el [] (indexación)
    T& operator[](int index){
        if (index < 0 || index >= size)
//            return T();
             throw out_of_range("Index out of range");
        return array[index];
    }

    // Sobrecargar el <<
    friend ostream& operator<<(ostream& os, Myvec& vec){
        os << "[";

        for (int i = 0; i < vec.size - 1; ++i) {
            os << vec[i] << ",";
        }

        os << vec[vec.size-1] << "]";

        return os;
    };

    // Destructor (liberamos memoria)
    ~Myvec(){
//        delete [] array;  CHECKEAR
//        array = nullptr;
    }
};




#endif //INC_2023_II_MYVEC_H
