#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e17;

// Prim
// O(|V|^2)
const long long MAX_V = 100009;  // 最大頂点数
long long cost[MAX_V][MAX_V];    // cost[u][v]: 辺e=(u, v)のコスト(存在しない場合はINF)
long long mincost[MAX_V];        // 集合Xからの辺の最小コスト
bool used[MAX_V];          // 頂点iが集合Xに含まれているか
int V;                     // 頂点数

int prim(){
    for(int i=0;i<V;i++){
        mincost[i] = INF;
        used[i] = false;
    }

    mincost[0] = 0; // 0-origin
    int res = 0;

    while(true){
        int v = -1;
        // Xに属さない頂点のうち、辺のコストが最小になる頂点を探す
        for(int u=0;u<V;u++){
            if(!used[u] && (v == -1 || mincost[u] < mincost[v])) v = u;
        }

        if(v == -1) break;
        used[v] = true;
        res += mincost[v];

        for(int u=0;u<V;u++){
            mincost[u] = min(mincost[u], cost[v][u]);
        }
    }
    return res;
}

// kruscal
// O(|E| log |V|)
class UnionFind{
public:
    vector<int> parent, siz;

    void init(int N){
        parent.resize(N, -1);
        siz.resize(N, 1);
    }

    int root(int x){
        if(parent[x] == -1){
            return x;
        }else{
            return parent[x] = root(parent[x]);
        }
    }

    void unite(int x, int y){
        int rx = root(x), ry = root(y);
        if(rx == ry) return;
        if(siz[rx] > siz[ry]){
            parent[ry] = rx;
            siz[rx] += siz[ry];
        }else{
            parent[rx] = ry;
            siz[ry] += siz[rx];
        }
    }

    bool same(int x, int y){
        return root(x) == root(y);
    }
};

struct edge{
    int u, v, cost;
};

bool comp(const edge& e1, const edge& e2){
    return e1.cost < e2.cost;
}

const int MAX_E = 1000009;
edge edges[MAX_E];          // 辺の集合
int V, E;                   // 頂点数、辺の数

int kruscal(){ // priority_queueでもよい
    sort(edges, edges+E, comp);
    UnionFind uf;
    uf.init(V);
    int res = 0;
    for(int i=0;i<E;i++){
        edge e = edges[i];
        if(!uf.same(e.u, e.v)){
            uf.unite(e.u, e.v);
            res += e.cost;
        }
    }
    return res;
}

int main(){
    return 0;
}