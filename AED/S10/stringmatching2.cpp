#include <iostream>
#include <chrono>
#include <ctime>
#include <unistd.h>
#include "smatching2.h"
using namespace std;

string generarTexto(int N){
    string alfabeto = "";
    /*alfabeto += "ABCDEFGHIJKLMNOPQRSTUVWXYZ ";
    alfabeto += "abcdefghijklmnopqrstuvwxyz ";
    alfabeto += "0123456789 ";
    */
    alfabeto="ACGT";
    string resultado = "";
    for (size_t i = 0; i < N; i++)
        resultado += alfabeto[rand() %  alfabeto.size()];
    return resultado;
}

void testInocente(string Texto, string Patron)
{
    auto start = std::chrono::steady_clock::now();

    //execute the algorithm
    vector<int> v_ino = inocente(Texto,Patron);
    //TODO
    cout<<"indices1: ";
    for(int i=0;i<v_ino.size();i++) cout<<v_ino[i]<<"\n "[i+1<v_ino.size()];
    auto end = std::chrono::steady_clock::now();
    //show the elapsed time
    cout << "Elapsed time in milliseconds: "
        << chrono::duration_cast<chrono::microseconds>(end - start).count()
        << " ms" << endl;
}

void testBoyerMoore(string Texto, string Patron)
{
    auto start = std::chrono::steady_clock::now();

    //execute the algorithm
    vector<int> v_bm= boyerMoore(Texto,Patron);
    //TODO
    cout<<"indices2: ";
    for(int i=0;i<v_bm.size();i++) cout<<v_bm[i]<<"\n "[i+1<v_bm.size()];

    auto end = std::chrono::steady_clock::now();
    //show the elapsed time
    cout << "Elapsed time in milliseconds: "
        << chrono::duration_cast<chrono::microseconds>(end - start).count()
        << " ms" << endl;
}

int main()
{
    srand(time(NULL));
//    //generate text
    size_t N = 1000000;
    int m = 10;
    string Texto = generarTexto(N);
    string Patron = generarTexto(m);
    //cout<<"texto: "<<Texto<<"\n";
    cout<<"size de texto a buscar: "<<N<<"\n";
    cout<<"Patron: "<<Patron<<"\n";
    testInocente(Texto, Patron);
    testBoyerMoore(Texto, Patron);

    return 0;
}

