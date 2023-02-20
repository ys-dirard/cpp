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

int N, M, A[100009], B[100009];
int Q, query[100009], x[100009], u[100009], v[100009];
string ans[100009];

UnionFind uf;
bool cancelled[100009];

int main(){
    cin >> N >> M;
    for(int i=1;i<=M;i++) cin >> A[i] >> B[i];
    cin >> Q;
    for(int i=1;i<=Q;i++){
        cin >> query[i];
        if(query[i]==1) cin >> x[i];
        else cin >> u[i] >> v[i];
    }

    for(int i=1;i<=M;i++) cancelled[i] = false;
    for(int i=1;i<=Q;i++){
        if(query[i]==1) cancelled[x[i]] = true;
    }

    uf.init(N);
    for(int i=1;i<=M;i++){
        if(cancelled[i]==false && uf.same(A[i], B[i])==false){
            uf.unite(A[i], B[i]);
        }
    }

    for(int i=Q;i>0;i--){
        if(query[i]==1){
            if(uf.same(A[x[i]], B[x[i]])==false) uf.unite(A[x[i]], B[x[i]]);
        }else{
            if(uf.same(u[i], v[i])==true) ans[i] = "Yes";
            else ans[i] = "No";
        }
    }

    for(int i=1;i<=Q;i++){
        if(query[i]==2) cout << ans[i] << endl;
    }
    return 0;
}