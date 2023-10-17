#include <vector>

using namespace std;

vector<int> inocente(string Texto, string Patron)
{
    vector<int> resultado;
    int n = Texto.size();
    int m = Patron.size();

    for (int i = 0; i <= n - m; ++i) {
        int j = 0;
        while (Patron[j] == Texto[i+j] && j < m)
            j++;
        if (j == m)
            resultado.push_back(i);
    }

    return resultado;
}

int* buildPositions(string patron){
	int* array = new int[256];

    for (int i = 0; i < 256; ++i)
        array[i] = -1;

    for (int i = 0; i < patron.size(); i++)
        array[patron[i]] = i;

    // Letras
//    for (int i = 65; i < 91; ++i) {
//        cout << char(i) << ": " << array[i] << endl;
//    }

	return array;
}

vector<int> boyerMoore(string Texto, string Patron)
{
    int n = Texto.size();
    int m = Patron.size();
    int* positions = buildPositions(Patron);

    vector<int> resultado;

    for (int i = 0; i <= n-m; ) {
        int j = m-1;
        while (j >= 0 && Patron[j] == Texto[i+j]){
            j--;
        }

        if (j >= 0) {
            i += max(1, j - positions[Texto[i + j]]);
        } else {
            resultado.push_back(i);
            i += m;
        }
    }
    return resultado;
}
