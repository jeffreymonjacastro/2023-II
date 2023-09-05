#include <iostream>

using namespace std;

void calcular(int temp, int* f, int* t, int* c){
    if (temp <= 15){
        (*f)++;
    } else if (temp > 15 and temp <= 21){
        (*t)++;
    } else {
        (*c)++;
    }
}

void imprimirReporte(int* f, int* t, int* c){
    cout << "Reporte" << endl;
    cout << "Dias frios: " << *f << endl;
    cout << "Dias templados: " << *t << endl;
    cout << "Dias calurosos: " << *c << endl;
}

int main(){
    int n;
    while (true){
        cout << "Numero dias: ";
        cin>>n;

        if(n > 0 && n < 10){
            break;
        }
    }

    int frios = 0, templados = 0, calurosos = 0;

    for(int i = 0; i < n; i++){
        int temp;
        cout << "Temperatura dia " << i+1 << ":";
        cin >> temp;

        calcular(temp, &frios, &templados, &calurosos);
    }

    imprimirReporte(&frios, &templados, &calurosos);

    return 0;
}