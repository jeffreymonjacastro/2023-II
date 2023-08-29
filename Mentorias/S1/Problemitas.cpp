//#include <iostream>
//
//using namespace std;
//
//int main(){
//    int n, m = 0;
//    cout << "Ingrese n: ";
//    cin>>n;
//
//    m += (n % 10) * 100;
//    n /= 10;
//    m += (n % 10) * 10;
//    n /= 10;
//    m += n;
//
//    cout << m;
//
//    return 0;
//}


#include <iostream>

using namespace std;

int main(){
    // VALIDACIÓN FORMA 1
    //    int a,b;
//    cout << "Ingrese a y b: ";
//    cin>>a>>b;

//    while (b < a){
//        cout << "Ingrese a y b: ";
//        cin>>a>>b;
//    }

    // VALIDACIÓN FORMA 2
//    int a,b;
//
//    while (true) {
//        cout << "Ingrese a y b: ";
//        cin >> a >> b;
//
//        if ( b > a )
//            break;
//    }

// VALIDACIÓN FORMA 3
    int a,b, sum = 0;

    do {
        cout << "Ingrese a y b: ";
        cin>>a>>b;
    } while (b < a);

    cout << "[" << a << "," << b << "]" << endl;

    for (int i = a; i <= b; ++i) {
        if (i % 2 == 1)
            cout << i << " ";
    }

    cout << endl;

    for (int i = a + 1; i < b; ++i) {
        if (i % 2 == 1)
            sum += i;
    }

    cout << sum;



    return 0;
}