#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class BST {
private:
    struct Node {
        int data;
        Node* left;
        Node* right;
    };

    Node* root;
public:
    BST(){root = nullptr;}

    void insert(int val, Node*& n){
        if (n == nullptr) {
            n = new Node(val);
            return;
        }

        if (val < n->data) {
            insert(val, n->left);
        } else if (val > n->data) {
            insert(val, n->right);
        } else {
            return;
        }
    }

    void insert(int val){
        insert(val, root);
    }


    void print_by_levels(Node* root){
        vector<pair<int,int>> v;
        queue<pair<Node*, int>> q;
        q.push({root,0});

        while(!q.empty()){
            auto c = q.front();
            q.pop();
            v.push_back({c.first->data, c.second});

            if(c.first->left) {
                q.push({c.first->left, c.second + 1});
            }
            if(c.first->right) {
                q.push({c.first->right, c.second + 1});
            }
        }

        int count = 0;

        for (int i = 0; i < v.size(); ++i) {
            if (v[i].second > count){
                cout << endl;
                count++;
            }

            cout << v[i].first << " ";
        }
    }

    void print_by_levels(){
        print_by_levels(root);
    }
};


int main(){
    BST tree;
    vector<int> v = {8, 3, 10, 1, 6, 14, 4, 7, 13};

    for (int i = 0; i < v.size(); ++i) {
        tree.insert(v[i]);
    }

    tree.print_by_levels();

    return 0;
}
