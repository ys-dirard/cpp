#include <bits/stdc++.h>
using namespace std;

class UnionFind{
public:
    int parent[100009], siz[100009];

    void init(int N){
        for(int i=0;i<N;i++){
            parent[i] = -1;
            siz[i] = 1;
        }
    }

    int root(int x){
        int p = parent[x];
        while(p != -1){
            x = p;
            p = parent[x];
        }
        return x;
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

int n, m, q, t1, t2;

int main(){
    cin >> n >> m;
    UnionFind uf;
    uf.init(n);

    for(int i=0;i<m;i++){
        cin >> t1 >> t2;
        if(!uf.same(t1, t2)) uf.unite(t1, t2);
    }

    cin >> q;
    for(int i=0;i<q;i++){
        cin >> t1 >> t2;
        if(uf.same(t1, t2)){
            cout << "yes" << endl;
        }else{
            cout << "no" << endl;
        }
    }
    return 0;
}