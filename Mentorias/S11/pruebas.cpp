#include "myvec.h"

#include <vector>


using namespace std;

int main(){
    vector<int> vec1;
    vector<int> vec2;
    vector<int> vec3(10, 1);

    vec1.push_back(1);
    vec1.push_back(2);
    vec1.push_back(3);
    vec1.push_back(4);

    vec2.push_back(1);
    vec2.push_back(2);
    vec2.push_back(3);
    vec2.push_back(4);

//    cout << vec1;

//    vec1 + vec2;

//    for (int i = 0; i < vec1.size(); ++i) {
//        cout << vec1[i] << " ";
//    }



    cout << endl;

    Myvec<int> myvec1(4);
    Myvec<int> myvec2(4);
    Myvec<int> myvec3;

    myvec1.push_back(1);
    myvec1.push_back(2);
    myvec1.push_back(3);
    myvec1.push_back(4);

    myvec2.push_back(1);
    myvec2.push_back(2);
    myvec2.push_back(3);
    myvec2.push_back(4);


    for (int i = 0; i < myvec1.Size(); ++i) {
        cout << myvec1[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < myvec2.Size(); ++i) {
        cout << myvec2[i] << " ";
    }
    cout << endl;

    myvec3 = myvec1 + myvec2;

    cout << myvec3;

    return 0;
}