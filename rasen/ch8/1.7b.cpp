#include <bits/stdc++.h>
using namespace std;

const int NIL = -1;

struct Node
{
    int parent, left, right; // left child, right child
};

int n, id, l, r, D[100009], H[100009], deg[100009];
Node T[100009];

void set_depth(int u, int p){
    D[u] = p;
    if(T[u].right != NIL){
        set_depth(T[u].right, p+1);
    }
    if(T[u].left != NIL){
        set_depth(T[u].left, p+1);
    }
}

int get_depth(int u){
    int d = 0;
    while(T[u].parent != NIL){
        u = T[u].parent;
        d++;
    }
    return d;
}

int set_height(int u){
    int h1 = 0, h2 = 0;
    if(T[u].left != NIL){
        h1 = set_height(T[u].left) + 1;
    }
    if(T[u].right != NIL){
        h2 = set_height(T[u].right) + 1;
    }
    return H[u] = max(h1, h2);
}

void set_degree(){
    for(int i=0;i<n;i++){
        deg[i] = (T[i].left != NIL) + (T[i].right != NIL);
    }
}

void print_brother(int u){
    int p = T[u].parent;
    if (p == NIL){
        cout << -1;
        return;
    }
    int bro = (T[p].left == u) ? T[p].right : T[p].left;
    cout << bro;
    return;
}

void print(int u){
    string type;
    if(T[u].parent == NIL) type = "root";
    else if(T[u].left == NIL && T[u].right == NIL) type = "leaf";
    else type = "internal node";

    cout << "node " << u;
    cout << ": parent = " << T[u].parent;
    cout << ", sibling = ";
    print_brother(u);
    cout << ", degree = " << deg[u];
    cout << ", depth = " << D[u];
    cout << ", height = " << H[u];
    cout << ", " << type << endl;
}

int main(){
    cin >> n;
    for(int i=0;i<n;i++) T[i].parent = T[i].left = T[i].right = NIL;

    for(int i=0;i<n;i++){
        cin >> id >> l >> r;
        T[id].left = l;
        T[id].right = r;
        T[l].parent = id;
        T[r].parent = id;
    }

    int root;
    for(int i=0;i<n;i++){
        if(T[i].parent == NIL) root = i;
    }
    set_depth(root, 0);
    set_height(root);
    set_degree();

    for(int i=0;i<n;i++) print(i);
    return 0;
}