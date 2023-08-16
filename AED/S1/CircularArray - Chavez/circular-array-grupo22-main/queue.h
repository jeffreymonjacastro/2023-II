#include "circulararray.h"
template <typename T>
class QueueArray : private CircularArray<T> {
public:
    explicit QueueArray(int size_): CircularArray<T>(size_){};

    void push(T data_){
       CircularArray<T>::push_back(data_);
    }
    T pop(){
       return CircularArray<T>::pop_front();
    }
    string display(){
        return CircularArray<T>::to_string();
    }
};