#include "SimpleLinkedList.h"

int main(){
    SimpleLinkedList<int> lista;

    lista.push_back(1);
    lista.push_back(2);
    lista.push_back(3);
    lista.push_front(4);
    lista.push_front(5);
    lista.push_front(6);

    cout << "Front: " << lista.front() << " Back: " << lista.back() << endl;

    for (int i = 0; i < lista.size(); ++i) {
        cout << lista[i] << " ";
    }

    return 0;
}