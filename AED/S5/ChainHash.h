//
// Created by USER on 5/25/2023.
//

#ifndef PROYECTO_CHAINHASH_H
#define PROYECTO_CHAINHASH_H
#include <iostream>
#include <functional>
#include <string>
#include "ForwardList.h"
using namespace std;
const float maxFillFactor = 0.4;
const int maxColision = 3;

template<typename TK, typename TV>
class ChainHash
{
private:
    ForwardList<std::pair<TK, TV>> * array;
    int capacity;
    int size;
    hash<TK> hasher;

public:
    ChainHash(int cap = 13){
        this->capacity = cap;
        this->size = 0;
        this->array = new ForwardList<std::pair<TK, TV>>[this->capacity];
    }

    float fillFactor(){
        return size / (capacity * maxColision * 1.0);
    }
    pair<TK,TV> find(TK key)
    {
        size_t hashcode = hasher(key);
        int index =  hashcode % capacity;

    }
    bool contains  (TK key) const {

        size_t hashcode = hasher(key);
        int index =  hashcode % capacity;
        for(auto &[llave , value]:array[index])
        {
            if(llave==key)
                return true;
        }

        return false;

    }
    void remove(TK key)
    {

        size_t hashcode = hasher(key);
        int index =  hashcode % capacity;
        int i=0;

        for(auto &[llave , value]:array[index])
        { i++;
            if(llave==key)
                array[index].remove(i);

        }

    }

    TV& operator[](TK key) const
    {
        size_t hashcode = hasher(key);
        int index =  hashcode % capacity;

        if(contains(key))
        {
            for(auto &[llave , value]:array[index])
            {
                if(llave==key)
                    return value;
            }

        }else throw out_of_range("Elemento no encontrado ...");
    }

    void merge(ChainHash other){

        for(int i=0;i<(int)other.bucket_count();i++){
            for(auto it = other.begin(i); it != other.end(i); ++it)
            {
                insert(*it);

            }
        }

    }
    void insert(pair<TK, TV> dato){

        if(!contains(dato.first))
        {     size++;
            // cout<<"EL FILL FACTOR ES"<<size<<"  :->"<<fillFactor()<<endl;
            if(fillFactor() >= maxFillFactor) rehashing();

            size_t hashcode = hasher(dato.first);
            int index =  hashcode % capacity;
            //TODO: validar la existencia de la llave, lanzar excepcion
            array[index].push_front(dato);
            if(array[index].size()>maxColision) rehashing();


        }

    }

    int bucket_count(){
        return capacity;
    }

    int bucket_size(int i){
        return array[i].size();
    }
    int getsize(){
        return size;
    }

    typename ForwardList<std::pair<TK, TV>>::iterator begin(int i){
        return array[i].begin();
    }

    typename ForwardList<std::pair<TK, TV>>::iterator end(int i){
        return array[i].end();
    }

    ~ChainHash(){
        //TODO
    }
private:
    void rehashing(){
        ForwardList<std::pair<TK, TV>> temp[this->capacity];
        int stemp=capacity;
        for (int i = 0; i < capacity; ++i) {
            for(const auto& element:array[i])
            {
                temp[i].push_front(element);
            }
        }
        delete []array;
        int n_size=capacity*2;
        while (!is_prime(n_size))
            n_size++;
        capacity=n_size;
        array= new ForwardList<std::pair<TK, TV>>[this->capacity];
        for (int i = 0; i < stemp; ++i) {
            for(const auto& element:temp[i])
            {
                size_t hashcode = hasher(element.first);
                int index =  hashcode % capacity;
                array[index].push_front(element);
            }
        }
    }
    bool is_prime(int n)
    {
        for (int i = 2; i*i <= n ; ++i) {
            if(n%i==0)
                return false;
        }
        return true;
    }
};
#endif //PROYECTO_CHAINHASH_H
