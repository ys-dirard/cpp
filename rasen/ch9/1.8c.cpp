#include <bits/stdc++.h>
using namespace std;

struct  Node
{
    int key;
    Node *parent, *left, *right;
};

Node *root, *NIL;

void insert(int k){
    Node *y = NIL;
    Node *x = root;
    Node *z;

    z = (Node *)malloc(sizeof(Node));
    z->key = k;
    z->left = NIL;
    z->right = NIL;

    while(x != NIL){
        y = x;
        if(z->key < x->key){
            x = x->left;
        }else{
            x = x->right;
        }
    }

    z->parent = y;
    if(y==NIL){
        root = z;
    }else{
        if(z->key < y->key){
            y->left = z;
        }else{
            y->right = z;
        }
    }
}

Node* find(Node *x, int k){
    while(x != NIL && k != x->key){
        if(k < x->key){
            x = x->left;
        }else{
            x = x->right;
        }
    }
    return x;
}

Node* getMinimum(Node* x){
    while(x->left != NIL){
        x = x->left;
    }
    return x;
}

Node* getSuccessor(Node* x){
    Node *y;
    if(x->right != NIL){
        y = getMinimum(x->right);
    }else{
        y = x->parent;
        while(y != NIL && x != y->right){
            x = y;
            y = x->parent;
        }
    }
    return y;
}

void delete_node(Node *z){
    Node *y; // 削除対象
    if(z->left == NIL || z->right == NIL){
        y = z;
    }else{
        y = getSuccessor(z);
    }

    Node *x; // 繋ぎ変える子
    if(y->left != NIL){
        x = y->left;
    }else{
        x = y->right;
    }

    // xの親がyの親になるように
    if (x != NIL) x->parent = y->parent;

    // yの親の子をxに
    if(y->parent == NIL){ // yがroot
        root = x;
    }else if(y->parent->left == y){ // yが親の左の子
        y->parent->left = x;
    }else{ // yが親の右の子
        y->parent->right = x;
    }

    // zの子が2個の場合のキー変更
    if(y != z){
        z->key = y->key;
    }
}

void inorder(Node *u){
    if(u == NIL) return;
    inorder(u->left);
    cout << " " << u->key;
    inorder(u->right);
}

void preorder(Node *u){
    if(u == NIL) return;
    cout << " " << u->key;
    preorder(u->left);
    preorder(u->right);
}

int main(){
    int n, k;
    string msg;
    
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> msg;
        // cout << i << endl;
        // cout << "-----" << msg << endl;

        if(msg == "insert"){
            cin >> k;
            // cout << k << endl;
            insert(k);
        }else if(msg == "delete"){
            cin >> k;
            delete_node(find(root, k));
        }else if(msg == "find"){
            cin >> k;
            Node* res = find(root, k);
            if(res != NIL) cout << "yes" << endl;
            else cout << "no" << endl;
        }else{
            inorder(root);
            cout << endl;
            preorder(root);
            cout << endl;
        }
    }
    return 0;
}