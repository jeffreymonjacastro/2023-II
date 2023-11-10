#include "graph.h"

int main(){
    Graph graph;

    // Agregar 10 vértices numerados del 1 al 10
    for (int i = 1; i <= 10; ++i) {
        graph.aggregate(i);
    }

    graph.connect(1, 2, 20);
    graph.connect(1, 3, 5);
    graph.connect(2, 3, 7);
    graph.connect(2, 4, 12);
    graph.connect(3, 4, 1);
    graph.connect(3, 5, 2);
    graph.connect(4, 5, 9);
    graph.connect(4, 6, 6);
    graph.connect(5, 6, 3);
    graph.connect(5, 7, 4);
    graph.connect(6, 7, 1);
    graph.connect(6, 8, 40);
    graph.connect(7, 8, 7);
    graph.connect(7, 9, 11);
    graph.connect(8, 9, 13);
    graph.connect(8, 10, 19);
    graph.connect(9, 10, 2);
    graph.connect(1, 10, 5);
    graph.connect(2, 9, 1);

    graph.Dijkstra();

    return 0;
}
