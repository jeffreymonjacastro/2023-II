#include <iostream>

using namespace std;

template<class T>
struct Node {
    T data;
    Node<T>* next;

    Node() {
        this->next = nullptr;
    }

    explicit Node(T data) {
        this->data = data;
        this->next = nullptr;
    }
};

template <class T>
class SimpleLinkedList {
private:
    Node<T>* head;

public:
    SimpleLinkedList(){
        head = nullptr;
    }

    void display() {
        Node<T>* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

    T front() {
        if (head == nullptr)
            return T();

        return head->data;
    }

    T back() {
        if (head == nullptr)
            return T();

        Node<T>* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;

        return temp->data;
    }

    void push_front(T data) {
        Node<T>* nodo = new Node(data);
        nodo->next = head;
        head = nodo;
    }

    void push_back(T data) {
        Node<T>* nodo = new Node(data);
        Node<T>* temp = head;

        if (head == nullptr) {
            head = nodo;
            return;
        }

        while (temp->next != nullptr)
            temp = temp->next;

        temp->next = nodo;
    }

    void pop_front() {
        if (head == nullptr) return;

        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }

    void pop_back() {
        if (head == nullptr) return;

        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }

        Node<T>* temp = head;
        while (temp->next->next != nullptr)
            temp = temp->next;

        delete temp->next;
        temp->next = nullptr;
    }

    bool empty() {
        return head == nullptr;
    }

    void clear() {
        while (!empty())
            pop_front();
    }

    int size() {
        int count = 0;
        Node<T>* temp = head;

        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }

        return count;
    }

    void insert(T data, int pos) {
        if (pos == 0) {
            push_front(data);
            return;
        }

        if (pos == size()) {
            push_back(data);
            return;
        }

        Node<T>* nodo = new Node(data);
        Node<T>* temp = head;

        int i = 0;

        while (i++ < pos - 1)
            temp = temp->next;

        nodo->next = temp->next;
        temp->next = nodo;
    }

    void remove(int pos) {
        if (pos == 0) {
            pop_front();
            return;
        }

        if (pos == size() - 1) {
            pop_back();
            return;
        }

        Node<T>* temp = head;

        int i = 0;

        while (i++ < pos - 1)
            temp = temp->next;

        Node<T>* nodo = temp->next;
        temp->next = temp->next->next;
        delete nodo;
    }

    T operator[](int pos) {
        Node<T>* temp = head;

        int i = 0;

        while (i++ < pos)
            temp = temp->next;

        return temp->data;
    }

    void reverse() {
        Node<T>* i = nullptr;
        Node<T>* j = head;
        Node<T>* k = nullptr;

        while (j != nullptr) {
            k = j->next;
            j->next = i;

            i = j;
            j = k;
        }

        head = i;
    }

    void sort() {

    }
};