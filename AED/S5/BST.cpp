#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

/**
    Completar los métodos vistos en clase
    si quieren verificar el correcto display de los recorridos sugiero que
    tambien a la mano tengan graficado cómo varía el arbol
    recordar que las funciones tambien pueden ser llamadas cuando el bst es vacío
    para esto está el test 3

**/

struct NodeBT{
    int data;
    NodeBT* left;
    NodeBT* right;

    NodeBT(){
        data = -1;
        left = nullptr;
        right = nullptr;
    }

    NodeBT(int val){
        data = val;
        left = nullptr;
        right = nullptr;
    }

    void display(){
        cout<<data<<"\n";
    }

    NodeBT(int val, NodeBT* l, NodeBT* r){
        data = val;
        left = l;
        right = r;
    }
};

class BST{
private:
    NodeBT* root;
public:
    BST(){ root = nullptr; }

    BST(NodeBT* n){
        root = n;
    }

    ///esta funcion inserta el valor val, en el subarbol con raiz n.
    void insert(int val, NodeBT*& n){
        if (n == nullptr) {
            n = new NodeBT(val);
            return;
        }

        if (val < n->data) {
            insert(val, n->left);
        } else if (val > n->data) {
            insert(val, n->right);
        } else {
            return; // no admite repetidos
        }
    }

    ///esta funcion inserta el valor val en el arbol.
    void insert(int val){
        insert(val, root);
    }

    ///esta funcion imprime el valor del nodo raíz, si este existe.
    void raiz(){
        if (root != nullptr)
            cout << root->data << endl;
        else
            cout << "Empty Tree" << endl;
    }

    ///imprime el subarbol con nodo raiz p, inOrder
    void inOrder(NodeBT*& p){
        if (p != nullptr) {
            inOrder(p->left);
            cout << p->data << " ";
            inOrder(p->right);
        }
    }

    ///imprime el arbol inOrder
    void inOrder(){
        inOrder(root);
    }

    ///imprime el subarbol con nodo raiz p, preOrder
    void preOrder(NodeBT*& p){}

    ///imprime el arbol, preOrder
    void preOrder(){}

    ///imprime el subarbol con nodo raiz p, postOrder
    void postOrder(NodeBT*& p){}

    ///imprime el arbol, postOrder
    void postOrder(){}

    ///imprime el subarbol con nodo raiz p, dfs
    void dfs(NodeBT*& p){}

    ///imprime el arbol, dfs
    void dfs(){}

    ///imprime el subarbol con nodo raiz p, bfs
    void bfs(NodeBT*& p){}

    ///imprime el arbol, dfs
    void bfs(){}

    ///responde la validez de la afirmación: "value es un elemento del subarbol con raiz p"
    bool find(NodeBT*& p, int value){}

    ///responde la validez de la afirmación: "value es un elemento del arbol"
    bool find(int value){}

    ///devuelve el puntero al nodo que contiene el minimo elemento del subarbol con raiz p
    NodeBT* fMin(NodeBT*& p){}

    ///devuelve el puntero al nodo que contiene el minimo elemento del arbol
    NodeBT* fMin(){}

    ///devuelve el puntero al nodo que contiene el maximo elemento del subarbol con raiz p
    NodeBT* fMax(NodeBT* p){}

    ///devuelve el puntero al nodo que contiene el maximo elemento del arbol
    NodeBT* fMax(){}

    ///elimina val, si existe, del subarbol con nodo p
    void remove(int val, NodeBT*& p){}

    ///elimina val del arbol, si existe
    void remove(int val){}
};


void test1(){
    NodeBT* nodo = new NodeBT(5,nullptr,nullptr);
    nodo->display();
}

void test2(){
    BST* bstree = new BST;
    vector<int> v = {8, 3, 10, 1, 6, 14, 4, 7, 13};
    for(int i = 0; i < v.size(); i++){
        bstree->insert(v[i]);
    }
    cout<<"inOrder:\n";
    bstree->inOrder();

    cout<<"preOrder:\n";
    bstree->preOrder();

    cout<<"postOrder:\n";
    bstree->postOrder();

    cout<<"dfs:\n";
    bstree->dfs();

    cout<<"bfs:\n";
    bstree->bfs();

    for(int i=0;i<15;i++){
        if(bstree->find(i)){
            cout<<i<<" aparece\n";
        }
        else
            cout<<i<<" no aparece\n";
    }
    bstree->fMin()->display();
    bstree->fMax()->display();

    bstree->remove(8);
    bstree->inOrder();
    bstree->dfs();
}

void test3(){
    BST* bstri = new BST;
    bstri->insert(1);
    bstri->insert(1);
    bstri->inOrder();
    bstri->remove(1);
    bstri->remove(1);   ///remover un elemento en un bst vacio
    bstri->inOrder();   ///lineas 109-114 es para verificar que las busquedas no cuelgan el programa si reciben un bst vacio
    bstri->preOrder();
    bstri->postOrder();
    bstri->bfs();
    bstri->dfs();
    bstri->raiz();
    bstri->insert(2);
    bstri->insert(6);

    bstri->insert(1);
    bstri->insert(3);
    bstri->insert(5);
    bstri->insert(7);
    bstri->inOrder();
}

void testing(){
    BST* bstree = new BST;
    vector<int> v = {8, 3, 10, 1, 6, 14, 4, 7, 13};
    for(int i = 0; i < v.size(); i++){
        bstree->insert(v[i]);
    }
    cout<<"inOrder:\n";
    bstree->inOrder();
}

int main(){
//    cout<<"test1:\n";
//    test1();
//    cout<<"\ntest2:\n";
//    test2();
//    cout<<"\ntest3:\n";
//    test3();
    testing();
    return 0;
}