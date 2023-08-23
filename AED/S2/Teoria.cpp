#include <iostream>
using namespace std;
struct Node{
    int val;
    Node* next;
    Node(){
        //val=-1; no usar valores para indicar presencia de dato, usar optional<>
        next = NULL;
    }
    Node(int data){
        val= data;
        next =NULL;
    }
    void display(){
        cout<<"Nodo con valor: "<<val<<"\n";
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
        while(temp->next->next!= NULL) temp = temp->next;
        delete temp->next;
        temp->next =NULL;

    }
};

int main()
{
    //Node* n=new Node; n->display();
    /*
    List l;
    l.pop_front();
    l.push_front(1);
    l.push_front(2);
    l.push_front(3);
    l.push_front(10);
    //l.printeo();
    l.push_back(4);
    l.push_back(5);
    l.push_back(6);
    l.push_back(20);
    l.printeo();
    l.pop_front();
    l.printeo();
    l.pop_back();
    l.printeo();*/
    List l;
    l.pop_back();
    l.printeo();
    l.push_back(1);
    l.pop_back();
    l.printeo();
    l.push_back(2);
    l.push_back(3);
    l.pop_back();
    l.printeo();
    return 0;
}
