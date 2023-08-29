#include <iostream>

using namespace std;

struct Node{
    int val;
    Node* next;

    Node(){
        val = -1;
        next = nullptr;
    }

    explicit Node(int data){
        val = data;
        next = nullptr;
    }
    void display(){
        cout<<"Nodo con valor: "<<val<<"\n";
    }
};

class Iterador{
private:
    Node* nActual;
public:
/**
    Iterador()
    Iterador(Node* nodo){}
    operator=(Node* nodo) ///asignacion
    operator++() /// prefijo ++
    operator++(int) ///postfijo ++
    operator*() ///dereferencia
    operator!=(Iterador it) ///comparacion
    operator==(Iterador it) ///comparacion
**/

    Iterador(){
        nActual = nullptr;
    }

    explicit Iterador(Node* nodo){
        nActual = nodo;
    }

    Iterador& operator=(Node* nodo){
        nActual = nodo;
        return *this;
    }

    // Prefijo (++it)
    Iterador& operator++(){
        if (nActual)
            nActual = nActual->next;

        return *this;
    }

    // Postfijo (it++)
    Iterador operator++(int){
        Iterador it = *this;
        ++(*this);

        return it;
    }

    int operator*(){
        return nActual->val;
    }

    bool operator==(Iterador it){
        return nActual == it.nActual;
    }

    bool operator!=(Iterador it){
        return nActual != it.nActual;
    }

};

class List{
private:
    Node* head;
public:
/**
    Constructores
    pusheos
    popeos
    printeo
    reverse
    Iterador
**/
    List(){
        head =NULL;
    }
    List(int data){
        head = new Node(data);
    }
    bool empty(){
        return (head==NULL);
    }

    void push_front(int data){
        Node* nodo = new Node(data);
        nodo->next =head;
        head = nodo;

    }
    void push_back(int data){
        /*
            -usamos while para llegar al ultimo nodo
            -creamos un nuevo nodo
            -redirigimos el ultimo nodo al nuevo creado
            -trabajar caso esquina
        */

        if(empty()){
            push_front(data);
            return;
        }
        Node* temp = head;
        ///mientras (no sea el ultimo nodo) avanzas
        ///while(!(eres el ultimo nodo)) avanzas
        ///while(!(temp->next == NULL)) temp = temp->next;
        while(temp->next != NULL)   temp=temp->next;
        temp->next = new Node(data);
    }
    void printeo(){
        cout<<"Lista: ";
        if(empty()){
            cout<<"NULL\n";
            return;
        }
        Node* temp = head;
        while(temp!=NULL){
            cout<<temp->val<<"->";
            temp = temp->next;
        }
        cout<<"NULL\n";
    }
    void pop_front(){
        if(empty()) return;
        Node* nodo = head;
        head=head->next;
        delete nodo;
    }
    void pop_back(){
        if(empty()){        //la lista tiene menos de 2 elementos
            return;
        }
        if(head->next ==NULL){
            pop_front();
            return;
        }
        /*
            -mientras temp no sea el penultimo, avanzas.
            -while(!(seas penultimo)) avanzas

        */
        Node* temp = head;
        while(temp->next->next != nullptr) temp = temp->next;
        delete temp->next;
        temp->next = nullptr;
    }

    Iterador begin(){
        return Iterador(head);
    }

    Iterador end(){
        return Iterador(nullptr);
    }

};

int main()
{
    List l;
    int n;
    cout<<"ingrese numero de elementos: ";
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        l.push_back(x);         ///O(n^2)
    }
    cout<<"Impresion de elementos de la lista usando metodo:\n";
    l.printeo();

    Iterador it;

    it = l.begin();
    cout << "inicio: "<< *it <<"\n";
    cout << "prefijo ++: " << *(++it) <<"\n";
    cout << "postfijo++: "<< *(it++) <<"\n";
    cout << "comprobacion postfijo: "<< *it <<"\n";
    Iterador it2= it;

    cout << "bool it == it2: " << (it == it2) << "\n";
    cout << "bool it == it2: " << (it == ++it2) << "\n";
    cout << "Impresion de elementos de lista usando iteradores:\n";

    cout << "bool it != it2: " << (it != it2) << "\n";
    cout << "bool it != it2: " << (++it != it2) << "\n";


    cout<<"Impresion de elementos de lista usando iteradores:\n";
    for(it = l.begin(); it != l.end(); it++){
        cout<<*it<<" ";
    }
    return 0;
}

