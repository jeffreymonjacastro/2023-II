#include <iostream>

using namespace std;

string reversa(string s){
    string new_s;

    for (int i = s.size() - 1; i >= 0; i--){
        new_s += s[i];
    }

    return new_s;
}

void print(string s, char c){
    for (char i : s) {
        cout << i << c;
    }
}


int fibonacci(int n){
    if (n <= 1)
        return 1;
    else
        return fibonacci(n-1) + fibonacci(n-2);
}


int main(){
//    string s;
//    cin>>s;

//    getline(cin, s);
//
//    int n;
//    cin>>n;
//

// WHILE
//    int i = 0;
//    while(i < n){
//        cout << i << " ";
//        i--;
//    }

// FOR CLASICO
//    for(int i = n; i >= 0; i--){
//        cout << i << " ";
//    }


// OTRO FOR
//    string s;
//    getline(cin, s);
//
//    for(char c : s){
//        cout << c << "/";
//    }



// DO WHILE
//    int j = 0;
//    do {
//        cout << j << " ";
//        j++;
//    } while (j < n);


// FUNCIONES
//    string s;
//    char c;
//    getline(cin, s);
//    cin>>c;
//
//    string inverso = reversa(s);
//
//    cout << inverso;

//    print(s, c);


//    int n;
//    cin>>n;
//
//    cout << fibonacci(n) << endl;


    return 0;
}
