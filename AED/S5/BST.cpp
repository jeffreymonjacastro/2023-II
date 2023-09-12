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
        cout << endl;
    }

    ///imprime el subarbol con nodo raiz p, preOrder
    void preOrder(NodeBT*& p){
        if (p != nullptr) {
            cout << p->data << " ";
            preOrder(p->left);
            preOrder(p->right);
        }
    }

    ///imprime el arbol, preOrder
    void preOrder(){
        preOrder(root);
        cout << endl;
    }

    ///imprime el subarbol con nodo raiz p, postOrder
    void postOrder(NodeBT*& p){
        if (p != nullptr) {
            postOrder(p->left);
            postOrder(p->right);
            cout << p->data << " ";
        }
    }

    ///imprime el arbol, postOrder
    void postOrder(){
        postOrder(root);
        cout << endl;
    }

    ///imprime el subarbol con nodo raiz p, dfs
    void dfs(NodeBT*& p){
        if (p == nullptr)
            return;

        stack<NodeBT*> Stack;
        Stack.push(p);

        while(!Stack.empty()) {
            auto node = Stack.top();
            cout << node->data << " ";
            Stack.pop();
            if (node->right != nullptr)
                Stack.push(node->right);
            if (node->left != nullptr)
                Stack.push(node->left);
        }
    }

    ///imprime el arbol, dfs
    void dfs(){
        dfs(root);
        cout << endl;
    }

    ///imprime el subarbol con nodo raiz p, bfs
    void bfs(NodeBT*& p){
        if (p == nullptr)
            return;

        queue<NodeBT*> Queue;
        Queue.push(p);

        while(!Queue.empty()){
            auto node = Queue.front();
            cout << node->data << " ";
            Queue.pop();

            if(node->left != nullptr)
                Queue.push(node->left);
            if(node->right != nullptr)
                Queue.push(node->right);
        }
    }

    ///imprime el arbol, dfs
    void bfs(){
        bfs(root);
        cout << endl;
    }

    ///responde la validez de la afirmación: "value es un elemento del subarbol con raiz p"
    bool find(NodeBT*& p, int value){
        if (p == nullptr)
            return false;

        if (value < p->data)
            return find(p->left, value);
        else if (value > p->data)
            return find(p->right, value);
        else
            return true;
    }

    ///responde la validez de la afirmación: "value es un elemento del arbol"
    bool find(int value){
        return find(root, value);
    }

    ///devuelve el puntero al nodo que contiene el minimo elemento del subarbol con raiz p
    NodeBT* fMin(NodeBT*& p){
        if (p == nullptr){
            return p;
        }

        if(p->left == nullptr)
            return p;

        return fMin(p->left);
    }

    ///devuelve el puntero al nodo que contiene el minimo elemento del arbol
    NodeBT* fMin(){
        return fMin(root);
    }

    ///devuelve el puntero al nodo que contiene el maximo elemento del subarbol con raiz p
    NodeBT* fMax(NodeBT* p){
        if (p == nullptr){
            return p;
        }

        if(p->right == nullptr)
            return p;

        return fMax(p->right);
    }

    ///devuelve el puntero al nodo que contiene el maximo elemento del arbol
    NodeBT* fMax(){
        return fMax(root);
    }

    ///elimina val, si existe, del subarbol con nodo p
    void remove(int val, NodeBT*& p){
        if (p == nullptr)
            return;

        if (val < p->data)
            return remove(val, p->left);
        else if (val > p->data)
            return remove(val, p->right);

        // 3er caso 2 Hijos
        if(p->left != nullptr && p->right != nullptr){
            p->data = fMin(p->right)->data;
            return remove(p->data, p->right);
        }

        // 1er caso Hoja
        if (p->left == nullptr && p->right == nullptr) {
            p = nullptr;
            return;
        }

        // 2do caso: 1 hijo
        if (p->left == nullptr){
             auto temp = p;
             p = p->right;
             delete temp;
            return;
        }

        if( p->right == nullptr){
            auto temp = p;
            p = p->left;
            delete temp;
            return;
        }
    }

    ///elimina val del arbol, si existe
    void remove(int val){
        remove(val, root);
    }
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

int main(){
    cout<<"test1:\n";
    test1();
    cout<<"\ntest2:\n";
    test2();
    cout<<"\ntest3:\n";
    test3();
    return 0;
}