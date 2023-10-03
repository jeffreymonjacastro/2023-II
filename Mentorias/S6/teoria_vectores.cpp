#include <iostream>
#include <vector>

using namespace std;

int main(){
    // Declaración
    vector<int> v1;
    vector<string> v2;

    vector<int> v3(10);
    vector<int> v4(10,5);

    vector<int> v5 = {1,2,3};

    v5.push_back(4);
    v5.emplace_back(5);
    v5.insert(v5.begin() + 1,9);

    v5[1] = 10;
//
//    for (int i = 0; i < v5.size(); ++i) {
//        cout << v5[i] << " ";
//    }
//
//    cout << endl;

    // Leer/Iterar
//    vector<int> v6;
//    for (int i = 0; i < 5; ++i) {
//        int x;
//        cin>>x;
//        v6.push_back(x);
//    }
//
//    for (int i = 0; i < v6.size(); ++i) {
//        cout << v6[i] << " ";
//    }

//    v5.clear();
//
//    for (int i = 0; i < v5.size(); ++i) {
//        cout << v5[i] << " ";
//    }

//    cout << endl;
//    cout << v5.size() << endl;
//    cout << v5.capacity() << endl;
//    cout << v5.empty() << endl;
//    cout << v5.front() << endl;
//    cout << v5.back() << endl;

    //ITERAR
//    int* arr = new int[5];
    vector<int> v7;

    // Índices
    for (int i = 0; i < 5; ++i) {
//        v7[i] = i+1;
        v7.push_back(i+1);
    }

    // i -> value
//    for(auto i : v7){
//        cout << i << " ";
//    }
//
//    cout << endl;
//
//    //iterator -> dirección de cada valor
//    for(auto it = v7.begin(); it != v7.end(); it++){
//        cout << *it << " ";
//    }
//
//
    vector<vector<int>> matrix = {{},{},{}};
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
//            matrix[i][j] = 1;
            matrix[i].push_back(4);
        }
    }

    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[0].size(); ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }


    return 0;
}