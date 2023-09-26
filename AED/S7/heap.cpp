#include <iostream>
#include <vector>

using namespace std;

class Heap{
private:
    vector<int> arr;
    int canti;  ///canti <= tope cantidad de elementos del vector que son parte del heap
    int tope;  ///tope = arr.size()
public:
    Heap(vector<int>& elements){
        for (auto i: elements) {
            arr.push_back(i);
        }

        canti = arr.size();
        tope = arr.size();
    }

    int L(int i){ return 2*i + 1; }
    int R(int i){ return 2*i + 2; }
    int P(int i){ return (i - 1)/2; }

    ///retorna la respuesta a la pregunta, ¿i es un indice válido en el heap?
    bool in(int i){
        return i < canti;
    }

    ///assumes L(i) and R(i) are heaps
    void heapify_down(int i){
        int l = L(i);
        int r = R(i);
        int p = i;

        if (in(l) && arr[l] > arr[p])
            p = l;
        if (in(r) && arr[r] > arr[p])
            p = r;

        if (p != i){
            swap(arr[i], arr[p]);
            heapify_down(p);
        }
    }

    void heapify_up(int i){
        int p = P(i);

        if (in(p) && arr[p] < arr[i]){
            swap(arr[i], arr[p]);
            heapify_up(p);
        }
    }

    void build_max_heap(){
        for (int i = canti/2 - 1; i >= 0; i--)
            heapify_down(i);
    }

    ///muestra los elementos de Heap. ojo que no todos los elementos del arr son parte del heap
    void display(){
        for(int i = 0; i < canti; i++){
            cout << arr[i] <<" ";
        }
        cout << endl;
    }

    ///inserta el elemento x al heap
    ///para este ejercicio puede usar la funcion .resize de la libreria vector.
    ///tambien etar permitido(en este ejemplo) hacer un resize de n a n+1, en vez de n a 2n, si desea
    void insert(int x){
        canti++;
        tope++;
        arr.resize(tope);
        arr[canti - 1] = x;
        heapify_up(canti - 1);
    }

    void pop(){
        if (canti == 0) return;

        swap(arr[0], arr[canti - 1]);
        canti--;
        heapify_down(0);
    }

    void ordenar(){
        for (int i = 0; i < tope; ++i) {
            pop();
        }
    }

    void vertodo(){
        for(int i = 0; i < tope; i++){
            cout << arr[i] <<" ";
        }
        cout << endl;
    }
};
int main(){
    vector<int> v = {36, 3, 25, 2, 19, 100,1, 17};
    Heap* heap = new Heap(v);
    cout<<"heap original:\n";
    heap->display();
    heap->build_max_heap();
    cout<<"max-heap:\n";
    heap->display();

    heap->insert(7);
    cout<<"max-heap al insertar 7:\n";
    heap->display();

    heap->pop();
    cout << "max-heap al popear 1 vez:\n";
    heap->display();

    heap->pop();
    heap->pop();

    cout << "max-heap al popear 3 veces:\n";
    heap->display();
    heap->ordenar();

    cout << "heap al heapsortear:\n";
    heap->vertodo();
    return 0;
}
