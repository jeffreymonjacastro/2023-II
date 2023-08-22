#include "DoubleLinkedList.h"

int main(){
    DoubleLinkedList<int> lista;

    lista.push_front(2);
    lista.push_back(1);
    lista.push_front(3);
    lista.push_back(4);

    cout << lista.size() << endl;

    cout << "Front: " << lista.front() << " Back: " << lista.back() << endl;

    cout << lista[2] << endl;

    return 0;
}