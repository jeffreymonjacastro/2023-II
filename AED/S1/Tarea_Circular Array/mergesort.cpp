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

    void resize(){
        T* temp = new T[capacity * 2];
        int i = front;
        int j = 0;

        while (i != back){
            temp[j] = array[i];
            i = next(i);
            j++;
        }

        temp[j] = array[i];
        capacity *= 2;
        front = 0;
        back = j;
        delete[] array;
        array = temp;
    }

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
        return (back >= front) ? back - front + 1 : (capacity - front) + (back + 1);
    };

    void clear(){
        delete[] array;
        front = back = -1;
        capacity = 2;
        array = new T[capacity];
    };

    T& operator[](int pos){
        if (pos < 0 || pos >= size()) {
            throw std::out_of_range("El indice esta fuera de rango");
        }

        return array[(front + pos) % capacity];
    };

    void insert(T data, int pos) {
        if (is_empty()) {
            if (pos != 0)
                return;
            array[0] = data;
            front = back = 0;
            return;
        }

        if (pos > size() || pos < 0)
            return;

        if (is_full())
            resize();

        if (pos == size()) {
            back = next(back);
            array[back] = data;
            return;
        }

        int r = back;
        while (r != pos){
            array[next(r)] = array[r];
            r = prev(r);
        }

        array[next(r)] = array[r];
        array[r] = data;
        back = next(back);
    };

    void merge(int start, int mid, int end ){
        int i = start;
        int j = mid + 1;
        int k = 0;

        T* temp = new T[end - start + 1];

        // mezclar
        while(i <= mid and j <= end) {
            if (array[i] <= array[j]) {
                temp[k] = array[i];
                i++;
            }

            else {
                temp[k] = array[j];
                j++;
            }

            k++;
        }

        while(i <= mid){
            temp[k] = array[i];
            i++;
            k++;
        }

        while(j <= end){
            temp[k] = array[j];
            j++;
            k++;
        }

        for(int m = start; m <= end; m++){
            array[m] = temp[m - start];
        }
    };

    void MergeSort(int start, int end){
        // Condición base
        if(start == end) return;

        // Hallar la mitad del array
        int mid = (start + end)/2;

        //parte izquierda
        MergeSort(start, mid);
        //parte derecha
        MergeSort(mid+1, end);

        //mezcla las partes ordenadas
        merge(start, mid, end);
    };

    void sort(){
        int i = front;
        int j = 0;
        T* temp = new T[capacity];

        while (i != back){
            temp[j] = array[i];
            i = next(i);
            j++;
        }

        temp[j] = array[i];

        delete [] array;
        array = temp;

        back = size() - 1;
        front = 0;

        MergeSort(front, back);
    };

    bool is_sorted(){
        if (is_empty() or size() == 1)
            return true;

        int r = front;
        while (r != back) {
            if (array[r] > array[next(r)])
                return false;

            r = next(r);
        }

        return array[r] > array[next(r)];
    };

    void reverse(){
        int r = front;
        int h = back;
        int p = 0;
        while (p != size()/2) {
            T data = array[r];
            array[r] = array[h];
            array[h] = data;
            r++;
            h--;
            if (r == capacity)
                r = 0;
            if (h == -1)
                h = capacity-1;
            p++;
        }
        T data = array[h];
        array[r] = array[h];
        array[h] = data;
    };

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


//void merge(int* arr, int start, int middle, int end){
//    int i = start; // inicio de la izq
//    int j = middle + 1; // inicio de la der
//    int k = 0; // contador
//
//    // Array temporal para guardar los valores ordenados
//    int* temp = new int[end - start + 1];
//
//    // Comparar los valores de la izq y der
//    while (i <= middle && j <= end){
//        // Si el valor del array izq es menor que el de la der, lo agrega al array temporal
//        if (arr[i] < arr[j]){
//            temp[k] = arr[i];
//            i++;
//
//        // Si el valor del array der es menor que el de la izq, lo agrega al array temporal
//        } else {
//            temp[k] = arr[j];
//            j++;
//        }
//        k++;
//    }
//
//    // Si quedan elementos en la mitad izq, los agrega al array temporal
//    while (i <= middle){
//        temp[k] = arr[i];
//        i++;
//        k++;
//    }
//
//    // Si quedan elementos en la mitad der, los agrega al array temporal
//    while (j <= end){
//        temp[k] = arr[j];
//        j++;
//        k++;
//    }
//
//    // Copia los valores del array temporal al array original
//    for (int m = start; m <= end; m++){
//        arr[m] = temp[m - start];
//    }
//}
//
//void mergeSort(int* arr, int start, int end){
//    // Caso base
//    if (start == end) return;
//
//    // Hallar la mitad del array
//    int middle = (start + end) / 2;
//
//    // Mitad izquierda
//    mergeSort(arr, start, middle);
//
//    // Mitad derecha
//    mergeSort(arr, middle + 1, end);
//
//    // Merge
//    merge(arr, start, middle, end);
//}


int main(){
//    srand(time(nullptr));
//
//    int n = 10;
//    int *array = new int[n];
//
//    for(int i = 0; i < n; i++){
//        array[i] = rand() % 100;
//    }
//
//    for(int i = 0; i < n; i++){
//        cout << array[i] << " ";
//    }
//    cout << endl;
//
//    mergeSort(array,0, n-1);
//
//    for(int i = 0; i < n; i++){
//        cout << array[i] << " ";
//    }

    auto *array = new CircularArray<int>(7);

    array->push_back(3);
    array->push_back(7);
    array->push_front(8);
    array->push_back(1);
    array->push_front(10);

    cout << array->to_string() << endl;

    cout << array->size() << endl;

    array->sort();

    cout << array->size() << endl;

    cout << array->to_string() << endl;

    return 0;
}