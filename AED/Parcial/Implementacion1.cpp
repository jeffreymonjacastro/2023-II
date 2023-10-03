#include <iostream>

using namespace std;

template<class T = int>
class List {
private:
    struct Node {
        T data;
        int cont;
        Node *next;

        Node(T val){
            data = val;
            cont = 0;
            next = nullptr;
        }
    };

    Node* head;

public:
    List(){head = nullptr;}

    void insert(T value) {
        if (head == nullptr) {
            head = new Node(value);
            return;
        }

        Node* temp = head;

        while(temp->next != nullptr)
            temp = temp->next;

        temp->next = new Node(value);
    }

    void display(){
        Node* temp = head;

        while(temp->next != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }

        cout << temp->data << endl;
    }


    bool search_transpose_middle_chavez(Node*& head, T value) {
        Node *slow = head;
        Node *fastpar = head;//pos 0
        Node *fastimpar = head->next;//pos 1

        while((fastpar != nullptr and fastpar->next != nullptr) or (fastimpar->next != nullptr))
        {
            if (fastpar->data == value) {
                T temp = slow->data;
                slow->data = fastpar->value;
                fastpar->data = temp;
                return true;
            }
            if (fastimpar->data == value) {
                T temp = slow->data;
                slow->data = fastimpar->value;
                fastimpar->data = temp;
                return true;
            }

            fastpar = fastpar->next->next;
            fastimpar = fastimpar->next->next;
            slow = slow->next;
        }
    }

    bool search_transpose_middle_ours(Node*& head, T value) {
        int x = head->cont;
        Node* aux = nullptr;
        Node* curr = head;

        if (head->data == value) {
            head->cont++;
            return true;
        }

        while(curr->next != nullptr){
            if (curr->next->data != value && curr->next->cont < x) {
                x = curr->next->cont;
                aux = curr;
            }

            if (curr->next->data == value) {
                Node* temp = curr->next;
                temp->cont++;
                curr->next = temp->next;

                if (aux == nullptr){
                    temp->next = head;
                    head = temp;
                } else {
                    temp->next = aux->next;
                    aux->next = temp;
                }

                return true;
            }

            curr = curr->next;
        }

        return false;
    }

    bool search_transpose_middle_ours(T value){
        return search_transpose_middle_ours(head, value);
    }

    bool search_transpose_middle_chavez(T value){
        return search_transpose_middle_ours(head, value);
    }

};

void prueba1(List<int> lista){
    lista.search_transpose_middle_ours(5);
    lista.display();
    lista.search_transpose_middle_ours(4);
    lista.display();
    lista.search_transpose_middle_ours(4);
    lista.display();
    lista.search_transpose_middle_ours(2);
    lista.display();
    lista.search_transpose_middle_ours(1);
    lista.search_transpose_middle_ours(1);
    lista.search_transpose_middle_ours(1);
    lista.display();
}

void prueba2(List<int> lista){
    lista.search_transpose_middle_chavez(5);
    lista.display();
    lista.search_transpose_middle_chavez(4);
    lista.display();
    lista.search_transpose_middle_chavez(4);
    lista.display();
    lista.search_transpose_middle_chavez(2);
    lista.display();
    lista.search_transpose_middle_chavez(1);
    lista.search_transpose_middle_chavez(1);
    lista.search_transpose_middle_chavez(1);
    lista.display();
}

int main(){
    int* arr = new int[5]{1,2,3,4,5};
    List lista;

    for (int i = 0; i < 5; ++i) {
        lista.insert(arr[i]);
    }

    lista.display();

    prueba2(lista);


}
