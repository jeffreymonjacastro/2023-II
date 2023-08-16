#include "circulararray.h"

template <typename T>
class StackArray : private CircularArray<T> {


public:
    explicit StackArray(int capacity_): CircularArray<T>(capacity_) {}
    void push(T data){
       CircularArray<T>::push_back(data);
    }
    T pop()
    {
        return CircularArray<T>::pop_back();
    }
    bool empty()
    {
        return CircularArray<T>::is_empty();
    }
    int size()
    {
        return CircularArray<T>::size();
    }




};