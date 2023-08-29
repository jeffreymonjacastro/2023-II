#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(){
        data = 0;
        next = nullptr;
    }

    explicit Node(int val){
        data = val;
        next = nullptr;
    }
};

class List{
private:
    Node* head;
public:
    List(){
        head = nullptr;
    }

    bool isempty(){
        return head == nullptr;
    }

    void push_front(int val){
        Node* nodo = new Node(val);
        nodo->next = head;
        head = nodo;
    }

    void push_back(int val){
        Node* nodo = new Node(val);

        if (isempty()){
            head = nodo;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;

        temp->next = nodo;
    }

    void pop_front(){
        if (isempty())
            return;

        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void pop_back(){
        if (isempty())
            return;

        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }

        Node* temp = head;
        while (temp->next->next != nullptr)
            temp = temp->next;

        delete temp->next;
        temp->next = nullptr;
    }

    void clear(){
        while (!isempty())
            pop_front();
    }
    void reverse(){
        Node* i = nullptr;
        Node* j = head;
        Node* k = nullptr;

        while (j != nullptr) {
            k = j->next;
            j->next = i;

            i = j;
            j = k;
        }

        head = i;
    }

    void printeo(){
        Node* temp = head;
        while (temp != nullptr){
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "nullptr";
    }

    friend List interseccion(List& l1, List& l2){
        Node* i = l1.head;
        Node* j = l2.head;
        List l;

        while (i != nullptr && j != nullptr){
            if (i->data == j->data){
                l.push_back(i->data);
                i = i->next;
                j = j->next;
            }
            else if (i->data < j->data)
                i = i->next;
            else
                j = j->next;
        }

        return l;
    };

};

struct Node2{
    int data;
    Node2* next;
    Node2* prev;

    Node2(){
        data = 0;
        next = nullptr;
        prev = nullptr;
    }

    explicit Node2(int val){
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

class List2{
private:
    Node2* head;
    Node2* tail;
public:
    List2(){
        head = nullptr;
        tail = nullptr;
    }

    bool isempty(){
        return head == nullptr;
    }

    void push_front(int val){
        Node2* nodo = new Node2(val);

        if (isempty()){
            head = nodo;
            tail = nodo;
            return;
        }

        nodo->next = head;
        head->prev = nodo;
        head = nodo;
    }

    void push_back(int val){
        Node2* nodo = new Node2(val);

        if (isempty()){
            head = nodo;
            tail = nodo;
            return;
        }

        tail->next = nodo;
        nodo->prev = tail;
        tail = nodo;
    }

    void pop_front(){
        if (isempty())
            return;

        Node2* temp = head;
        head = head->next;

        if (head == nullptr)
            tail = nullptr;
        else
            head->prev = nullptr;

        delete temp;
    }

    void pop_back(){
        if (isempty())
            return;

        Node2* temp = tail;
        tail = tail->prev;

        if (tail == nullptr)
            head = nullptr;
        else
            tail->next = nullptr;

        delete temp;
    }

    void clear(){
        while (!isempty())
            pop_front();
    }

    void printeo(){
        Node2* temp = head;
        while (temp != nullptr){
            cout << temp->data << "<->";
            temp = temp->next;
        }
        cout << "nullptr";
    }

    bool isPalindromoBinario(){
        bool flag = true;

        Node2* i = head;
        Node2* j = tail;

        while(i != j){
            if(i->data % 2 != j->data % 2){
                flag = false;
                break;
            }

            i = i->next;
            j = j->prev;
        }

        return flag;
    }
};


void test1(){
    List l1,l2;
    l1.push_back(1); l1.push_back(2); l1.push_back(3); l1.push_back(4); l1.push_back(5);
    l2.push_back(1); l2.push_back(3); l2.push_back(4); l2.push_back(6); l2.push_back(8);
    List l = interseccion(l1,l2);
    cout << "lista 1     : "; l1.printeo(); cout<<"\n";
    cout << "lista 2     : "; l2.printeo(); cout<<"\n";
    cout << "interseccion: "; l.printeo(); cout<<"\n";
}

void test2(){
    List2 ld1,ld2;
    ld1.push_back(1);ld1.push_back(2);ld1.push_back(3);ld1.push_back(4);ld1.push_back(5);
    ld2.push_back(1);ld2.push_back(2);ld2.push_back(3);ld2.push_back(3);ld2.push_back(5);
    string s[2]={"no es palindromo binario\n","si es palindromo binario\n"};

    cout<<"lista doble 1     : ";ld1.printeo();cout<<"\n";
    cout<<s[ld1.isPalindromoBinario()];
    cout<<"lista doble 2     : ";ld2.printeo();cout<<"\n";
    cout<<s[ld2.isPalindromoBinario()];
}

int main(){
    test1();
    test2();
    return 0;
}
