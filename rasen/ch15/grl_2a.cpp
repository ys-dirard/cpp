#include <bits/stdc++.h>
using namespace std;

class UnionFind{
public:
    int parent[100009], siz[100009];

    void init(int N){
        for(int i=0;i<=N;i++){
            parent[i] = -1;
            siz[i] = 1;
        }
    }

    int root(int x){
        if(parent[x] == -1){
            return x;
        }else{
            return parent[x] = root(parent[x]);
        }
        // int p = parent[x];
        // while(x != -1){
        //     x = p;
        //     p = parent[x];
        // }
        // return x;
    }

    void unite(int x, int y){
        int rx = root(x), ry = root(y);
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