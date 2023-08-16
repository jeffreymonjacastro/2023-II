#include <iostream>

using namespace std;

/*
ESTRUCTURA DE DATOS
 * Son colecciones que mantienen diferentes relaciones entre los datos que almacenan.
 * Permiten eficiente acceso y modificación
 * Cada estructura se usa para diferentes problemas
 * Guardan datos en memoria

    STACK
    * Tiene la estructura de una pila (como las cartas)
    * LIFO (Last In First Out) -> La última carta que entra es la primera que sale
        * front() -> Devuelve el elemento que está en el tope de la pila
        * push() -> Agrega un elemento al tope de la pila
        * pop() -> Elimina el elemento que está en el tope de la pila
 */

class Stack {
private:
    int* array;
    int capacity;
    int size;
public:
    Stack(){
        array = new int[2];
        capacity = 2;
        size = 0;
    }

    void push(int data){
        if (size == capacity){
            int newCapacity = capacity * 2;
            int* newArray = new int[newCapacity];
            for (int i = 0; i < capacity; i++){
                newArray[i] = array[i];
            }
            delete[] array;
            array = newArray;
            capacity = newCapacity;
        }

        array[size] = data;
        size++;
    }

    void pop(){
        if (size == 0){
            return;
        }

        size--;
    }

    int front(){
        if (size == 0){
            return -1; // Representación que el stack está vacío
        }
        return array[size-1];
    }
};

/*
QUEUE


 */


/*
Arreglo circular
*/


int main(){
    Stack s;

    cout<< s.front() << endl;
    s.push(1);
    cout<< s.front() << endl;
    s.push(2);
    cout<< s.front() << endl;
    s.push(3);
    cout<< s.front() << endl;
    s.pop();
    cout<< s.front() << endl;

    return 0;
}