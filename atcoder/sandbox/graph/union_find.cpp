#include <bits/stdc++.h>
using namespace std;

// not have size implementation
// class UnionFind {
// public:
// 	vector<int> par;

// 	void init(int sz) {
// 		par.resize(sz, -1);
// 	}
// 	int root(int pos) {
// 		if (par[pos] == -1) return pos;
// 		par[pos] = root(par[pos]);
// 		return par[pos];
// 	}
// 	void unite(int u, int v) {
// 		u = root(u); v = root(v);
// 		if (u == v) return;
// 		par[u] = v;
// 	}
// 	bool same(int u, int v) {
// 		if (root(u) == root(v)) return true;
// 		return false;
// 	}
// };

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

int v, e, t, x, y;
vector<pair<int, int>> g[10009];
vector<tuple<int, int, int>> tpl; // (cost, from, to)

int main(){
    cin >> v >> e;
    UnionFind uf;
    uf.init(v);

    for(int i=1;i<=e;i++){
        cin >> x >> y >> t;
        if(t != -1){
            tpl.push_back({t, x, y});
        }
    }

    sort(tpl.begin(), tpl.end());
    int ans = 0;
    for(int i=0;i<tpl.size();i++){
        x = get<1>(tpl[i]);
        y = get<2>(tpl[i]);
        t = get<0>(tpl[i]);

        if(!uf.same(x, y)){
            uf.unite(x, y);
            ans += t;
        }
    }

    cout << ans << endl;
    return 0;
}