#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main(){
    int a, b, c;

    while (true) {
        cout << "a = ";
        cin >> a;

        if (a != 0) break;
    }

    cout << "b = ";
    cin>>b;

    cout << "c = ";
    cin>>c;

    if (pow(b,2) - 4 * a * c > 0){
        cout << "Existe 2 raices solucion" << endl;

        double x1 = (-b + sqrt(pow(b,2) - 4 * a * c)) / (2 * a);
        double x2 = (-b - sqrt(pow(b,2) - 4 * a * c)) / (2 * a);

        cout << "x1 = " << fixed << setprecision(3) << x1 << endl;
        cout << "x2 = " << fixed << setprecision(3) << x2 << endl;
    } else if (pow(b,2) - 4 * a * c == 0){
        cout << "Existe 1 raiz solucion" << endl;

        double x = (-b + sqrt(pow(b,2) - 4 * a * c)) / (2 * a);

        cout << "x1 = x2 = " << fixed << setprecision(3) << x << endl;
    } else {
        cout << "No existe raices solucion" << endl;
    }
    return 0;
}
