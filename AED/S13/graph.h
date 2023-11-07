#ifndef PROYECTO_GRUPO_7_GRAPH_H
#define PROYECTO_GRUPO_7_GRAPH_H

#include <iostream>
#include <unordered_map>
#include <stack>
#include <queue>


#define mapita unordered_map<int, unordered_map<int, int>>

using namespace std;

class Graph {
private:
    // el primer int es el dato (no es repetido)
    // Cada dato tiene su lista de arista
    mapita adj;
public:
    Graph(){}

    void aggregate(int vtx){
        adj[vtx];
    }

    // Conectar dos vértices con un peso
    void connect(int vtx1, int vtx2, int peso){
        if (adj.find(vtx1) == adj.end()) return;
        if (adj.find(vtx2) == adj.end()) return;
        if (adj[vtx1].find(vtx2) != adj[vtx1].end())
            return;
        adj[vtx1][vtx2] = peso;
        adj[vtx2][vtx1] = peso;
    }

    // Eliminar conexión (arista)
    void deleteEdge(int vtx1, int vtx2){
        if (adj[vtx1].find(vtx2) == adj[vtx1].end())
            return;

        adj[vtx1].erase(vtx2);
        adj[vtx2].erase(vtx1);
    }

    // Eliminar un vértice
    void deleteVertex(int vertex){
        if(adj.find(vertex) == adj.end())
            return;

        for(auto i : adj[vertex]){
            adj[i.first].erase(vertex);
        }
        adj.erase(vertex);
    }

    // Display pretty
    friend ostream& operator<<(ostream& os, Graph g){
        for(auto i : g.adj){
            os << i.first << ": ";
            for(auto j : i.second){
                os << "(" << j.first << "," << j.second << ")";
            }
            os << endl;
        }
        return os;
    };


    // DFS
    void DFS(){
        if (adj.empty()) return;

        unordered_map<int,bool> visited;

        // Poniendo los vértices en visited
        for(auto i : adj){
            visited[i.first] = false;
        }

        for(auto i : adj){
            DFSrecursive(visited, i.first);
        }
    }

    void DFSrecursive(unordered_map<int, bool>& visited, int vertex){
        if (visited[vertex]) {
//            cout << "x" << vertex << "->";
            return;
        }

        visited[vertex] = true;
        cout << vertex << "->";
        for(auto i : adj[vertex]){
            DFSrecursive(visited, i.first);
        }
    }

    // BFS
    void BFS(){
        if (adj.empty()) return;

        unordered_map<int,bool> visited;

        // Poniendo los vértices en visited
        for(auto i : adj) {
            visited[i.first] = false;
        }

        for(auto i : adj){
            BFSxd(visited, i.first);
        }
    }

    void BFSxd(unordered_map<int,bool>& visited, int vertex){
        if (visited[vertex]) return;

        visited[vertex] = true;

        queue<int> Q;
        Q.push(vertex);

        while(!Q.empty()){
            int curr = Q.front();
            cout << curr << "->";
            Q.pop();

            for (auto i : adj[curr]){
                if (visited[i.first]) continue;

                Q.push(i.first);
                visited[i.first] = true;
            }
        }
    }

    void Dijkstra(){

    }


    ~Graph(){};
};

//class Graph2 {
//private:
//    struct Vertex {
//        int dato;
//        unordered_map<int, int> aristas;
//
//        Vertex() = default;
//        Vertex(int d) : dato(d) {}
//    };
//
//    unordered_map<int, Vertex> vertices;
//
//public:
//    Graph2(){}
//
//    void aggregate(int dato){
//        vertices[vertices.size() + 1] = Vertex(dato);
//    }
//
//
//
//    ~Graph2(){}
//};


#endif //PROYECTO_GRUPO_7_GRAPH_H