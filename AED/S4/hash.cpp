#include <iostream>
#include <vector>
using namespace std;

void printeo(vector<int>& v, string s){
    cout << s;

    for(int i = 0; i<v.size(); i++){
        if(v[i] >= 0)
            cout << " " << v[i];
        else
            cout << " _";
    }

    cout << '\n';
}


void rehash(vector<int>& arr){
    int n = arr.size();

    //vector<int> nuevo(2*n,-1);
    vector<int> old = arr;

    arr.resize(2 * n,- 1);

    for(int i = 0; i < 2 * n; i++) arr[i]=-1;

    for(int i = 0; i < n; i++){
        if(old[i] < 0)
            continue;
        ///key valido
        int newpos = old[i] % (2*n);   ///candidato a nueva posicion

        while(arr[newpos] >= 0){
            newpos++;
            if(newpos == 2*n)
                newpos = 0;
        }
        arr[newpos] = old[i];   ///si es que fuera sin conflictos
    }
    //arr=nuevo;
}

int hasheo(int key, int tam){
    return key % tam;
}

int main(){
    //vector<int> keys = {2,3,6,8,10,11,15,19,20,22,25,30};
    vector<int> keys = {2,3,6,8,10,12,13,22,23,25,26,33,35,44,56};
    int cnt = 0;
    int tam= 5;
    double maxFillFactor = 0.8;

    vector<int> hashTable(5,-1);

    for(int i = 0; i < keys.size(); i++){
        if(cnt * 1.0/tam >= maxFillFactor){
            rehash(hashTable);

            tam = tam * 2;

            printeo(hashTable,"rehash:\n");
        }

        int j = hasheo(keys[i], tam);

        if(hashTable[j] < 0){
            hashTable[j] = keys[i];
        }

        else{
            while(hashTable[j] >= 0){
                j++;

                if (j >= tam)
                    j = j-tam;
            }

            hashTable[j] = keys[i];
        }

        cnt++;
        cout << "It [" << i << "] Elem [" << keys[i] << "] ";
        printeo(hashTable,"v:\n");
    }
}
