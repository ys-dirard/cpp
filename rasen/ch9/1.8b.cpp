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
        // cout << msg << endl;

        if(msg == "insert"){
            cin >> k;
            // cout << k << endl;
            insert(k);
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