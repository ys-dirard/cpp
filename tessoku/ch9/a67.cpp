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

int N, M;
int A[100009], B[100009], C[100009];
vector<pair<int, int>> edges;

int main(){
    cin >> N >> M;
    for(int i=1;i<=M;i++){
        cin >> A[i] >> B[i] >> C[i];
        edges.push_back(make_pair(C[i], i));
    }
    sort(edges.begin(), edges.end());

    UnionFind uf;
    uf.init(N);

    int ans = 0;
    for(int i=0;i<M;i++){
        int pos = edges[i].second;
        int cost = edges[i].first;
        if(uf.same(A[pos], B[pos])==false){
            uf.unite(A[pos], B[pos]);
            ans += cost;
        }
    }

    cout << ans << endl;
    return 0;
}