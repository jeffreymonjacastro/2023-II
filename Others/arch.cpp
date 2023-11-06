#include <iostream>

using namespace std;

int minfun(int* a, int b){
    if (b == 0)
        return a[0];
    else
        return min(a[b-1], minfun(a , b-1));
}

int min(int x, int y) {
    if (x <= y)
        return x;
    else
        return y;
}

int main(){
    int* array = new int[4]{2, 10, 5, 3};
    int size = 4;
    int result;

    result = minfun(array, size);

    cout << result;

    return 0;
}