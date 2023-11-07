#include <iostream>
#include "graph.h"

using namespace std;

int main(){
    Graph graph;

    // Agregar 10 vértices numerados del 1 al 10
    for (int i = 1; i <= 10; ++i) {
        graph.aggregate(i);
    }

    graph.connect(1, 2, 1);
    graph.connect(1, 3, 1);
    graph.connect(2, 3, 1);
    graph.connect(2, 4, 1);
    graph.connect(3, 4, 1);
    graph.connect(3, 5, 1);
    graph.connect(4, 5, 1);
    graph.connect(4, 6, 1);
    graph.connect(5, 6, 1);
    graph.connect(5, 7, 1);
    graph.connect(6, 7, 1);
    graph.connect(6, 8, 1);
    graph.connect(7, 8, 1);
    graph.connect(7, 9, 1);
    graph.connect(8, 9, 1);
    graph.connect(8, 10, 1);
    graph.connect(9, 10, 1);
    graph.connect(1, 10, 1);
    graph.connect(2, 9, 1);

    cout << graph;
    graph.DFS();
    cout << endl;
    graph.BFS();

    return 0;
}