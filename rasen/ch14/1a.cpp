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
        if(same(x, y)) return;
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

int n, q, com, x, y;
vector<pair<int, int>> g[109];
vector<tuple<int, int, int>> tpl; // (cost, from, to)

int main(){
    cin >> n >> q;
    UnionFind uf;
    uf.init(n);

    for(int i=0;i<q;i++){
        cin >> com >> x >> y;

        if(com == 0){
            uf.unite(x, y);
        }else{
            cout << uf.same(x, y) << endl;
        }
    }

    return 0;
}