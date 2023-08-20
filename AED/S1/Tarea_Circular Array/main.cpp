#include <iostream>
using namespace std;

template <class T>
class CircularArray {
private:
    T *array = nullptr;
    int capacity;
    int back, front;

    int next(int idx) {
        return (++idx) % capacity;
    };

    int prev(int idx){
        return (idx == 0) ? capacity - 1 : --idx;
    };

public:
    explicit CircularArray(int _capacity = 2);

    virtual ~CircularArray(){
        delete[] array;
    };

    T Front(){
        if (is_empty()) return -1;
        return array[front];
    }

    T Back(){
        if (is_empty()) return -1;
        return array[back];
    }

    void push_front(T data){
        if (is_empty()){
            front = back = 0;
            array[0] = data;
            return;
        }

        if (is_full()) {
            resize();
            push_front(data);
            return;
        }

        front = prev(front);
        array[front] = data;
    };

    void push_back(T data){
        if (is_empty()){
            front = back = 0;
            array[0] = data;
            return;
        }

        if (is_full()) {
            resize();
            push_back(data);
            return;
        }

        back = next(back);
        array[back] = data;
    };

    T pop_front(){
        if (is_empty()) return -1;

        if (front == back){
            T data = array[front];
            clear();
            return data;
        }

        T data = array[front];
        front = next(front);
        return data;
    };

    T pop_back(){
        if (is_empty()) return -1;

        if (front == back){
            T data = array[back];
            clear();
            return data;
        }

        T data = array[back];
        back = prev(back);
        return data;
    };

    bool is_full(){
        return (back - front == capacity - 1 || front - back == 1);
    };

    bool is_empty(){
        return (front == -1 && back == -1);
    };

    int size(){
        return (front >= back) ? back - front + 1 : (capacity - front) + (back + 1);
    };

    void clear(){
        delete[] array;
        front = back = -1;
        capacity = 2;
        array = new T[capacity];
    };

    T& operator[](int pos){
        if (pos < 0 || pos >= size())
            return T();

        return array[(front + pos) % size()];
    };

    void resize(){
        T* temp = new T[capacity * 2];
        int i = front;
        int j = 0;

        while (i != back){
            temp[j] = array[i];
            i = next(i);
            j++;
        }
        capacity *= 2;
        temp[j] = array[i];
        front = 0;
        back = j;
        delete[] array;
        array = temp;
    }

    void insert(T data, int pos){};

    void merge(int start, int mid, int end ){
        int tam1= mid-start+1, tam2=end-mid;
        int * mitad1 = new T[tam1];
        int * mitad2 = new T[tam2];

        //lenar las dos partes
        for(int idx = 0; idx<tam1; idx++) mitad1[idx]=array[(idx+start)%capacity];
        for(int idx = 0; idx<tam2; idx++) mitad2[idx]=array[(idx+(mid+1))%capacity];


        //mezclar
        int left= 0, right=0, idx=start;
        while(left<tam1 and right<tam2){
            if(mitad1[left]<= mitad2[right]){
                array[idx%capacity]= mitad1[left];
                left++;
            }
            else{
                array[idx%capacity]=mitad2[right];
                right++;
            }
            idx++;
        }
        while(left<tam1){
            array[idx%capacity]=mitad1[left];
            left++;
            idx++;
        }

        while(right<tam2){
            array[idx%capacity]= mitad2[right];
            right++;
            idx++;
        }

        //liberar memoria
        delete[] mitad1;
        delete[] mitad2;

    }

    void sort(int a, int b){
        //acomodar indices
        if(a<front) a= a+capacity;
        if(b<front) b = b+capacity;

        //se usa merge sort en base a indices
        if(a==b) return;

        int mid = a+(b-a)/2;

        //parte de izquierda
        sort(a, mid);
        //parte derecha
        sort(mid+1, b);

        //mezcla las partes ordenadas
        merge(a, mid,b);
        return;

    };


    bool is_sorted(){};

    void reverse(){};

    string to_string(string sep=" "){
        string result;
        int i = front;

        while (i != back){
            result += std::to_string(array[i]) + sep;
            i = next(i);
        }
        result += std::to_string(array[i]) + sep;

        return result;
    };

};

template <class T>
CircularArray<T>::CircularArray(int _capacity)
{
    this->capacity = _capacity;
    this->array = new T[_capacity];
    this->front = this->back = -1;
}
