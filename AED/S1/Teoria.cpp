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
        * front() -> Devuelve el elemento que está en el capacity de la pila
        * push() -> Agrega un elemento al capacity de la pila
        * pop() -> Elimina el elemento que está en el capacity de la pila
    * La lógica del Stack con arrays se basa en que si se llena el stack, se duplica su tamaño.
 */

class Stack {
private:
    int* arr; // Arreglo dinámico
    int capacity; // Capacidad del arreglo
    int size; // Cantidad de elementos que tiene el stack
public:
    // Constructor del Stack, inicializa el arreglo con capacidad 2 y size 0
    Stack(){
        arr = new int[2];
        capacity = 2;
        size = 0;
    }

    void resize(){
        int* temp = new int[capacity * 2]; // Crea un arreglo temporal con el doble de capacidad
        for (int i = 0; i < capacity; ++i) {
            temp[i] = arr[i]; // Copypastea los elementos del arreglo original al temporal
        }

        delete[] arr; // Liberar
        arr = temp; // El arreglo original ahora es el temporal
        capacity = capacity * 2; // Actualiza la capacidad
    }

    // Agrega un elemento al top del stack
    void push(int data){
        // Si el stack está lleno, duplica su capacidad
//        if (size == capacity){
//            resize();
//        }

        // Luego de aumentar la capacidad, agrega el elemento al top y aumenta el size
        arr[size] = data;
        size++;
    }

    // Elimina el elemento que está en el top del stack
    void pop(){
        // Si el stack está vacío, no hace nada
        if (size == 0){
            cout << "Stack is empty" << endl;
            return;
        }

        // Reduce el size para que el elemento que estaba en el top quede "eliminado" (no se accede)
        size--;
    }

    // Devuelve el elemento que está en el top del stack
    int top(){
        if (size == 0){
            cout << "Stack is empty" << endl;
            return -1; // Representación que el stack está vacío
        }
        return arr[size - 1];
    }
};

/*
QUEUE
*/

class Queue{
private:
    int* arr;
    int size;
    int capacity;
public:
    Queue(){
        arr = new int [2];
        size=0;
        capacity=2;
    }

    void resize(){
        int* temp = new int[2 * capacity];
        for(int i = 0; i < capacity; i++) temp[i]=arr[i];

        delete[] arr;
        arr = temp;
        capacity= capacity * 2;
    }

    void push(int data){
        if(size == capacity) resize();
        arr[size] = data;
        size++;
    }

    void pop(){
        if(size == 0) return;
        // desplazar todos los elementos a su izquierda.
        // Si i>0, mover arr[i] a arr[i-1]
        for(int i = 1; i < size; i++) arr[i-1]=arr[i];
        size--;
    }

    int front(){
        if(size > 0) return arr[0];
        return -1;
    }

    int back(){
        if(size > 0) return arr[size-1];
        return -1;
    }
};

/*

CIRCULAR QUEUE
*/

class CircularQueue {
private:
    int* arr;
    int capacity;
    int size;
    int front;
    int rear;
public:
    // Constructor del Queue, inicializa el arreglo con capacidad 2 y size 0
    CircularQueue(){
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
    void push(int data){
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
    void pop(){
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
//    Stack s;
//    s.push(1);
//    cout << s.top() << endl;
//    s.push(2);
//    cout << s.top() << endl;
//    s.push(3);
//    cout << s.top() << endl;
//    s.push(4);
//    cout << s.top() << endl;
//


    Queue q;
    q.push(2);
    q.push(3);
    q.push(5);
    q.pop();
    cout << q.front() << endl;
    cout << q.back() << endl;



    return 0;
}