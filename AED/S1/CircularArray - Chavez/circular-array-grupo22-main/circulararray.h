#include <iostream>
#include "cmath"
using namespace std;

template <class T>
class CircularArray
{
private:
    T *array;
    int capacity{};
    int back{}, front{};

public:
    explicit CircularArray(int _capacity = 10);
    virtual ~CircularArray(){
        delete array;
    }

    [[maybe_unused]] T Front(){
        return array[front];
    }
    [[maybe_unused]] T Back(){
        return array[back];
    }
    void push_front(T data) {
        if (is_full()) {
            resize();
        }

        if (is_empty()) {
            front = 0;
            back = 0;
            array[front] = data;
        }
        else {
            front= prev(front);
            array[front]=data;
        }
    }
    void push_back(T data){
        if (is_full()) {
            resize();
        }

        if(is_empty())
        {
            front=0;
            back=0;
            array[back]=data;
        } else {
            back= next(back);
            array[back]=data;
        }
    }

    void insert(T data, int pos){
        if (is_full()){
            resize();
        }
        if (pos> size()){
            push_back(data);

            return;
        }
        if (is_empty()) {
            front = 0;
            back = 0;
            array[front] = data;
            return;
        }
        if (pos == 1){
            push_front(data);
        }
        else if (pos == size()){
            push_back(data);
        }
        else{
            int index = pos;
            for (int i = size(); i >= index; --i) {
                array[(i+front)%capacity] = array[(i-1+front)%capacity];
            }
            array[(index-1+front)%capacity] = data;
            back = next(back);
        }
    }

    T pop_front(){
        if(is_empty())
        {
            cout<<"NO HAY ELEMENTOS POP IMPOSIBLE..."<<endl;
            return -1;
        }

        if(size()==1)
        {
            T temp=array[front];
            front=-1;
            back=-1;
            return temp;

        }else {
            T temp = array[front];
            front= next(front);
            return temp;
        }

    }
    T pop_back(){
            if(is_empty())
            {
                cout<<"NO HAY ELEMENTOS POP IMPOSIBLE..."<<endl;
                return -1;
            }

        if(size()==1)
        {   T temp= array[back];
            front=-1;
            back=-1;
            return temp;
        }else {
            T temp = array[back];
            back= prev(back);
            return temp;
        }

    }

    bool is_full(){
        return size()==capacity;
    }
    bool is_empty(){
        return back==-1 and front == -1 ;
    }
    [[nodiscard]] virtual int size() const{

        if(back>=front)
            return back-front+1;
        else return (back+1)+(capacity-front);
    }

    T& operator[](int index) const{
        int tam=size();
        if(index> tam or index <0)
            throw std::out_of_range("El indice esta esta fuera del rango del arreglo");

        return array[(front + index)%capacity];


    }
    void sort() // La siguente funcion implementa el algoritmo de counting sort
    {
        int array_2[size()];
        for (int i = 0; i < capacity; ++i) { //Se copia el array original en un array estatico a ordenar
            array_2[i] = array[(i+front)%capacity];
        }

        T max=array_2[0];

        for (int i = 1; i < size(); ++i) { // Se encuentra el maximo de los elementos
            if(max < array_2[i])
                max=array_2[i];
        }
        T prov_array[max+1]; //Se crea un array provicional que servira como un arry de frecuencias
        for (int i = 0; i < max+1; ++i) {
            prov_array[i]=0;//se inicializa en cero valores
        }
        for (int i = 0; i < size(); ++i) {
            prov_array[array_2[i]]++; //Se crea un arreglo de frecuencias
        }
        T ord_array[size()];//Se crea un arreglo donde se mandaran los valores ordenados
        for (int i = 1; i < max+1; ++i)
            prov_array[i]=prov_array[i]+prov_array[i-1];//Se crea una tabla de frecuencias acumuladas


        for (int i = 0; i < size(); ++i) {
            ord_array[prov_array[array_2[i]] - 1]=array_2[i];//Segun el incide, se van entrando valores en el array de frecuencias y disminuyendo
            prov_array[array_2[i]]--;                         //segun sus apariciones en el arry original
        }

        for (int i = 0; i < size(); ++i) {
            array[i]=ord_array[i]; //Se vuelven a copiar los valores al array original
        }

        back=size()-1; // se reubican el back y fort para que coincidan con las posiciones el array ahora ordenado
        front=0;


    }
    bool is_sorted(){
        for (int i = 0; i < size()-1; ++i) {
            if(array[(i+front)%capacity]>array[(i+front+1)%capacity])
                return false;
        }
        return true;

    }
    void reverse(){
        int tempFront = front;
        int tempBack = back;
        for (int i = 0; i < ceil(static_cast<double>(size())/2); ++i) {
            int temp = std::move(array[tempFront%capacity]);
            array[tempFront%capacity] = array[tempBack%capacity];
            array[tempBack%capacity] = temp;
            tempBack--;
            tempFront++;
        }
    }
    string to_string(string sep=" "){
        if (!is_empty()){
            string result;
            int current = front;
            while (current != back) {
                result += std::to_string(array[current]) + sep;
                current = next(current);
            }
            result += std::to_string(array[back]) + sep;
            return result;
        }
        else{
            return "";
        }

    };
    [[maybe_unused]] void clear(){
        delete array;
        back = front = -1;
        array = new T[capacity];
    }
private:
    int next(int index){
        return (++index)%capacity;
    }
    int prev(int index){

        if(index == 0)
        {
            return capacity-1;
        }
        else return index-1;

    }
    void resize(){
        T temp[this->capacity];
        for (int i = 0; i < capacity; ++i) {
            temp[i] = array[(i+front)%capacity];
        }
        delete array;
        array = new T[capacity*2];
        for (int i = 0; i < capacity; ++i) {
            array[i] = temp[i];
        }
        front = 0;
        back = capacity-1;
        capacity *= 2;
    }

};

template <class T>
CircularArray<T>::CircularArray(int _capacity)
{
    this->capacity = _capacity;
    this->array = new T[_capacity];
    this->front = this->back = -1;
}

