#include <bits/stdc++.h>
using namespace std;

const int NIL = -1;

struct Node
{
    int parent, left, right; // left child, right brother
};

int n, id, k, c[100009], D[100009];
Node T[100009];

void set_depth(int u, int p){
    D[u] = p;
    if(T[u].right != NIL){
        set_depth(T[u].right, p);
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

void print_children(int u){
    int c = T[u].left;
    while(c != NIL){
        cout << c;
        if(T[c].right != NIL){
            cout << ", ";
        }
        c = T[c].right;
    }
}

void print(int u){
    string type;
    if(T[u].parent == NIL) type = "root";
    else if(T[u].left == NIL) type = "leaf";
    else type = "internal node";

    cout << "node " << u;
    cout << ": parent = " << T[u].parent;
    cout << ", depth = " << D[u];
    cout << ", " << type;
    cout << ", [";
    print_children(u);
    cout << "]" << endl;
}

int main(){
    cin >> n;
    for(int i=0;i<n;i++) T[i].parent = T[i].left = T[i].right = NIL;

    for(int i=0;i<n;i++){
        cin >> id >> k;
        for(int j=0;j<k;j++){
            cin >> c[j];
            T[c[j]].parent = id;
            if(j==0) T[id].left = c[j];
            else T[c[j-1]].right = c[j];
        }
    }

    int root;
    for(int i=0;i<n;i++){
        if(T[i].parent == NIL) root = i;
    }
    set_depth(root, 0);

    for(int i=0;i<n;i++) print(i);
    return 0;
}