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
class CircularDoubleLinkedList {
private:
    Node<T>* head;
    Node<T>* tail;
public:
    CircularDoubleLinkedList(){
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

        if (empty()) {
            head = nodo;
            tail = nodo;
            head->next = head;
            head->prev = head;
            return;
        }

        nodo->next = head;
    }

    void push_back(T data) {}

    void pop_front() {}

    void pop_back() {}

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

    void clear() {}

    void insert(T data, int pos) {}

    void remove(int pos) {}

    T operator[](int pos) {}

    void reverse() {}

    void sort() {}
};