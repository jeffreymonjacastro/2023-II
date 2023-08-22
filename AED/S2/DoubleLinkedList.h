#include <iostream>

using namespace std;

template<class T>
struct Node {
    T data;
    Node<T>* next;
    Node<T>* prev;

    Node() {
        this->next = nullptr;
        this->prev = nullptr;
    }

    explicit Node(T data) {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

template <class T>
class DoubleLinkedList {
private:
    Node<T>* head;
    Node<T>* tail;
public:
    DoubleLinkedList(){
        head = nullptr;
        tail = nullptr;
    }

    void display() {
        Node<T>* temp = head;

        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

    T front() {
        if (empty())
            return T();

        return head->data;
    }

    T back() {
        if (empty())
            return T();

        return tail->data;
    }

    void push_front(T data) {
        Node<T>* nodo = new Node(data);

        if (empty()){
            head = nodo;
            tail = nodo;
            return;
        }

        nodo->next = head;
        head->prev = nodo;
        head = nodo;
    }

    void push_back(T data) {
        Node<T>* nodo = new Node(data);

        if (empty()){
            head = nodo;
            tail = nodo;
            return;
        }

        tail->next = nodo;
        nodo->prev = tail;
        tail = nodo;
    }

    void pop_front() {
        if (empty()) return;

        Node<T>* temp = head;
        head = head->next;

        if (head == nullptr)
            tail = nullptr;
        else
            head->prev = nullptr;

        delete temp;
    }

    void pop_back() {
        if (empty()) return;

        Node<T>* temp = tail;
        tail = tail->prev;

        if (tail == nullptr)
            head = nullptr;
        else
            tail->next = nullptr;

        delete temp;
    }

    bool empty() {
        return head == nullptr || tail == nullptr;
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

    void clear() {
        while (!empty())
            pop_front();
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
        while(i++ < pos - 1)
            temp = temp->next;

        nodo->next = temp->next;
        nodo->prev = temp;

        temp->next->prev = nodo;
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
        while(i++ < pos - 1)
            temp = temp->next;

        Node<T>* nodo = temp->next;
        temp->next = nodo->next;
        nodo->next->prev = temp;
        delete nodo;
    }

    T operator[](int pos) {
        Node<T>* temp = head;

        int i = 0;
        while(i++ < pos)
            temp = temp->next;

        return temp->data;
    }

    void reverse() {
        Node<T>* prev = nullptr;
        Node<T>* curr = head;
        Node<T>* next = nullptr;

        while (curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            curr->prev = next;
            prev = curr;
            curr = next;
        }

        tail = head;
        head = prev;
    }

    void sort() {}
};