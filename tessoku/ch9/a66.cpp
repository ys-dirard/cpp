#include <bits/stdc++.h>
using namespace std;

class UnionFind{
public:
    int par[100009];
    int siz[100009];

    void init(int N){
        for(int i=1;i<=N;i++) par[i] = -1;
        for(int i=1;i<=N;i++) siz[i] = 1;
    }

    int root(int u){
        while(true){
            if(par[u] == -1) break;
            u = par[u];
        }
        return u;
    }

    void unite(int u, int v){
        int rootU = root(u);
        int rootV = root(v);
        if(rootU == rootV) return;
        if(siz[rootU]<siz[rootV]){
            par[rootU] = rootV;
            siz[rootV] = siz[rootU] + siz[rootV];
        }else{
            par[rootV] = rootU;
            siz[rootU] = siz[rootV] + siz[rootU];
        }
    }

    bool same(int u, int v){
        if(root(u) == root(v)) return true;
        else return false;
    }
};

int N, Q;
int query[100009], u[100009], v[100009];

int main(){
    cin >> N >> Q;
    for(int i=1;i<=Q;i++) cin >> query[i] >> u[i] >> v[i];
    
    UnionFind uf;
    uf.init(N);

    for(int i=1;i<=Q;i++){
        if(query[i] == 1){
            uf.unite(u[i], v[i]);
        }else{
            if(uf.same(u[i], v[i])) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
    return 0;
}