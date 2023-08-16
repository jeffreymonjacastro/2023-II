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
    * La lógica del Stack con arrays se basa en que si se llena el stack, se duplica su tamaño.
 */

class Stack {
private:
    int* array; // Arreglo dinámico
    int capacity; // Capacidad del arreglo
    int size; // Cantidad de elementos que tiene el stack
public:
    // Constructor del Stack, inicializa el arreglo con capacidad 2 y size 0
    Stack(){
        array = new int[2];
        capacity = 2;
        size = 0;
    }

    // Agrega un elemento al top del stack
    void push(int data){
        // Si el stack está lleno, duplica su capacidad
        if (size == capacity){
            int* temp = new int[capacity * 2]; // Crea un arreglo temporal con el doble de capacidad
            // Copypastea los elementos del arreglo original al temporal
            for (int i = 0; i < capacity; i++){
                temp[i] = array[i];
            }
            delete[] array; // Elimina el arreglo original
            array = temp; // El arreglo original ahora es el temporal
            capacity = capacity * 2; // Actualiza la capacidad
        }

        // Luego de aumentar la capacidad, agrega el elemento al top y aumenta el size
        array[size] = data;
        size++;
    }

    // Elimina el elemento que está en el top del stack
    void pop(){
        // Si el stack está vacío, no hace nada
        if (size == 0){
            return;
        }

        // Reduce el size para que el elemento que estaba en el top quede "eliminado" (no se accede)
        size--;
    }

    // Devuelve el elemento que está en el top del stack
    int front(){
        if (size == 0){
            return -1; // Representación que el stack está vacío
        }
        return array[size-1];
    }
};

/*
QUEUE

CIRCULAR QUEUE
*/

class Queue {
private:
    int* arr;
    int capacity;
    int size;
    int front;
    int rear;
public:
    // Constructor del Queue, inicializa el arreglo con capacidad 2 y size 0
    Queue(){
        arr = new int[2];
        capacity = 2;
        size = 0;
        front = -1;
        rear = -1;
    }

    // Queue lleno
    bool isFull(){
        return (rear - front == capacity-1 || front - rear == 1);
    }

    // Queue vacío
    bool isEmpty(){
        return (front == -1 && rear == -1);
    }

    // Agrega un elemento al final del queue
    void enqueue(int data){
        // Si el queue está lleno, no hace nada
        if (isFull()){
            return;
        }

        // Si el queue está vacío, el front y el rear son 0
        if (isEmpty()){
            front = 0;
            rear = 0;
            arr[0] = data;
            size++;
            return;
        }

        // Si el rear está en la última posición del arreglo, lo mueve al inicio
        rear = (++rear) % capacity;
        arr[rear] = data;
        size++;
    }

    // Elimina el elemento que está en el front del queue
    void dequeue(){
        // Si el queue está vacío, no hace nada
        if (isEmpty()){
            return;
        }

        // Si se va a eliminar el último elemento del queue
        if (rear == front){
            rear = -1;
            front = -1;
            size--;
            return;
        }

        // Si el front está en la última posición del arreglo, lo mueve al inicio
        front = (++front) % capacity;
        size--;
    }

    int getFront(){
        if (isEmpty()){
            return -1;
        }

        return arr[front];
    }

    int getBack(){
        if (isEmpty()){
            return -1;
        }

        return arr[rear];
    }
};


int main(){
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    cout << q.getFront() << endl;
    cout << q.getBack() << endl;
    q.dequeue();
    q.enqueue(3);
    q.dequeue();
    q.enqueue(4);
    cout << q.getFront() << endl;



    return 0;
}