#include <iostream>

#define ll long long

using namespace std;

void fun(int n){
    cout<< n << " ";

    if (n == 1) {
        return;
    }
    else if (n % 2 == 0)
        n = n/2;
    else
        n = n * 3 + 1;

    fun(n);
}

int main(){
    string s;

    cout << s << endl;

  return 0;
}
