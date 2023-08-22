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

    void display() {}

    T front() {}

    T back() {}

    void push_front() {}

    void push_back() {}

    void pop_front() {}

    void pop_back() {}

    bool empty() {}

    int size() {}

    void clear() {}

    void insert(T data, int pos) {}

    void remove(int pos) {}

    T operator[](int pos) {}

    void reverse() {}

    void sort() {}
};