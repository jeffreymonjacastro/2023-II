#include <iostream>

using namespace std;

const double PI = 3.1415;

void imprimir(int n, float lista[]){
    for(int i = 0; i < n; i++){
        cout << lista[i] << "\t" ;
    }
    cout << endl;
}

void area_esfera(float &radio, float *area){
    *area = 4 * PI * (radio * radio);
}

void volumen_esfera(float *radio, float &volumenEsfera){
    volumenEsfera = 4/3 * PI * ((*radio) * (*radio) * (*radio));
}

int main(){
    int n;
    do {
        cout<<"N pokebolas: ";
        cin>>n;
    } while( n <= 0 );

    float areas[n];
    float volumenes[n];
    float r;

    for (int i = 0; i < n; ++i) {
        cout << "Radio de la pokebola [" << i << "]: ";
        cin>>r;

        area_esfera(r, &areas[i]);
        volumen_esfera(&r, volumenes[i]);
    }

    cout << "Areas: ";
    imprimir(n, areas);

    cout << "Volumenes: ";
    imprimir(n, volumenes);



    return 0;
}
