#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

struct NodeAVL{
    int data;
    int h;
    NodeAVL* left;
    NodeAVL* right;
    NodeAVL(){///construyendo nodos hoja
        data = -1;
        left= nullptr;
        right = nullptr;
        h=0;
    }
    NodeAVL(int val,int h=0){
        data = val;
        left= nullptr;
        right = nullptr;
        h=h;
    }
    void display(){
        cout<<data<<"-"<<h;
    }
    NodeAVL(int val,NodeAVL* l,NodeAVL* r, int h=0){
        data = val;
        left= l;
        right = r;
        h=h;
    }
};

int altura(NodeAVL* p){
    if(p!= nullptr)
        return p->h;
    else 
        return -1;
}

int rBalanceo(NodeAVL* p){
    if(p==nullptr)
        return 0;
    else 
        return altura(p->left) - altura(p->right);
}

class AVL{
private:
    NodeAVL* root;
public:
    AVL(){
        root =nullptr;
    }
    AVL(NodeAVL* n){
        root = n;
    }

    void rotateWithLeftChild(NodeAVL*& k2){
        
        NodeAVL* k1  = k2->left;
        k2->left = k1->right;
        k1->right = k2;
        ///update heights
        k2->h = 1 + max(altura(k2->left), altura(k2->right));
        k1->h = 1 + max(altura(k1->left), altura(k2));   //// k1->right = k2
        k2 = k1;
    }

    void rotateWithRightChild(NodeAVL*& k2){
        NodeAVL* k1  = k2->right;
        k2->right = k1->left;
        k1->left = k2;
        ///update heights
        k2->h = 1 + max(altura(k2->left), altura(k2->right));
        k1->h = 1 + max(altura(k1->left), altura(k1->right));
        k2 = k1;
    }
    void doubleWithLeftChild(NodeAVL*& k3){
        ///LR
        rotateWithRightChild(k3->left);
        rotateWithLeftChild(k3);
    }
    void doubleWithRightChild(NodeAVL*& k3){
        ///RL
        rotateWithLeftChild(k3->right);
        rotateWithRightChild(k3);
    }
    void insert(int val,NodeAVL*& n){
        if(n == nullptr){
            n = new NodeAVL(val, nullptr, nullptr);
        }
        else if(val< n->data){
            insert(val, n->left);
        }
        else if(val> n->data){
            insert(val, n->right);
        }

        balance(n);
    }
    void insert(int val){
        insert(val,root);
    }

    ///balance(t) asume que t esta balanceado o a 1 de serlo
    void balance(NodeAVL* & p){
        if(p==nullptr) return;
        if(rBalanceo(p)>1){
            ///desbalanceo izquierdo
            ///2 casos: LL o LR

            ///LL
            if(rBalanceo(p->left)>=0){
                rotateWithLeftChild(p);
            }
            ///LR
            else{
                doubleWithLeftChild(p);
            }
        }
        else{
            if(rBalanceo(p)<-1){
                ///desbalanceo derecho
                ///RL,RR

                ///RR
                if(rBalanceo(p->right)<=0){
                    rotateWithRightChild(p);
                }
                ///RL
                else
                    rotateWithRightChild(p);
            }
        }
    }

    void raiz(){
        cout<<root->data<<"\n";
    }

    void inOrder(NodeAVL*& p){
        if(p ==nullptr)
            return;

        inOrder(p->left);
        cout<<p->data<<"\t";
        inOrder(p->right);
    }

    void inOrder(){
        inOrder(root);
        cout<<"\n";
    }

    void preOrder(NodeAVL*& p){
        if(p==nullptr) return;
        cout<<p->data<<"\t";
        preOrder(p->left);
        preOrder(p->right);
    }
    void preOrder(){
        preOrder(root);
        cout<<"\n";
    }

    void postOrder(NodeAVL*& p){
        if(p==nullptr) return;
        postOrder(p->left);
        postOrder(p->right);
        cout<<p->data<<"\t";
    }
    void postOrder(){
        postOrder(root);
        cout<<"\n";
    }

    void dfs(NodeAVL*& p){
        if(p==nullptr) return;
        stack<NodeAVL*> s;
        s.push(p);
        while(!s.empty()){
            NodeAVL* x = s.top();
            cout<<x-> data<<"\t";
            s.pop();
            if(x->right) s.push(x->right);
            if(x->left) s.push(x->left);
        }
    }
    void dfs(){
        dfs(root);
        cout<<"\n";
    }

    void bfs(NodeAVL*& p){
        if(p==nullptr) return;
        queue<NodeAVL*> q;
        q.push(p);
        while(!q.empty()){
            NodeAVL* x=q.front();
            //cout<<x->data<<"-"<<x->h<<"\t";
            cout<<x->data<<"_"<<rBalanceo(x)<<"\t";
            q.pop();
            if(x->left) q.push(x->left);
            if(x->right) q.push(x->right);
        }
    }
    void bfs(){
        bfs(root);
        cout<<"\n";
    }

    bool find(NodeAVL*& p, int value){
        if(p==nullptr) return false;
        if(value< p->data)
            return find(p->left, value);
        if(value> p->data)
            return find(p->right, value);
        return true;
    }

    bool find(int value){
        return find(root,value);
    }

    NodeAVL* fMin(NodeAVL* p){
        ///recursiva:
        if(p==nullptr) return nullptr;

        if(p->left==nullptr) return p;
        return fMin(p->left);
    }

    NodeAVL* fMin(){
        return fMin(root);
    }

    NodeAVL* fMax(NodeAVL* p){
        if(p!=nullptr)
            while(p->right)
                p=p->right;
        return p;
    }
    NodeAVL* fMax(){
        return fMax(root);
    }

    void remove(int val, NodeAVL*& p){
        ///eliminacion 
        if(p==nullptr){
            return;
        }
        if(val < p->data){
            remove(val, p->left);
        }
        else if(val> p->data){
            remove(val, p->right);
        }
        ///p->data = val
        if(p->left != nullptr && p->right!= nullptr){ ///si tiene 2 descendientes
            int nuevo = fMin(p->right)->data; ///sucesor de p->data
            p->data = nuevo;
            remove(nuevo, p->right);
        }
        else{
            NodeAVL* old = p;
            ///p tiene maximo 1 descendiente
            if(p->left != nullptr){
                p = p->left;
            }
            else
                p = p->right;
            
            delete old;
        }

        ///balance()
        balance(p);
    }
    
    void remove(int val){
        remove(val, root);
    }
};

int main(){
    AVL* bstree = new AVL;
    ///vector<int> v = {3,2,1,4,5,6,7};
    cout<<"impresion bfs con altura de cada nodo:\n";
    vector<int> v = {3,2,1,4,5,6,7, 16,15,14,13,12,11,10,8,9};
    for(int i=0;i<v.size();i++){
        bstree->insert(v[i]);
        bstree->bfs();
    }

    bstree->remove(12);
    bstree->bfs();
    return 0;
}
