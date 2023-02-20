#include <bits/stdc++.h>
using namespace std;
#define ll long long

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

ll sgn(int x){
    return (x>=0) ? 1 : -1;
}

ll N, Q;
ll T[100009], X[100009], Y[100009], V[100009];
ll val[100009];
ll S[100009]; // S[i] = X[i]+X[i+1]

int main(){
    cin >> N >> Q;
    for(int i=1;i<=Q;i++){
        cin >> T[i] >> X[i] >> Y[i] >> V[i];
    }
    for(int i=1;i<=N;i++){
        val[i] = 0;
        S[i] = 0;
    }

    UnionFind uf;
    uf.init(N+1);

    // 結合、隣接和の保持
    for(int i=1;i<=Q;i++){
        if(T[i] == 0){
            // uf.unite(X[i], Y[i]);
            S[X[i]] = V[i];
        }
    }

    // クエリ先読み
    for(int i=1;i<N;i++){
        val[i+1] = S[i] - val[i];
        // if(uf.same(i, i+1)){
        //     val[i+1] = S[i] - val[i];
        // }
    }

    // 回答クエリ処理
    for(int i=1;i<=Q;i++){
        if(T[i] == 0){
            uf.unite(X[i], Y[i]);
        }else if(T[i] == 1){
            if(uf.same(X[i], Y[i])){
                ll diff = V[i] - val[X[i]];
                ll sn = (abs(Y[i] - X[i]) % 2 == 0) ? 1 : -1;
                cout << val[Y[i]] + sn * diff << endl;
            }else{
                cout << "Ambiguous" << endl;
            }
        }
    }
    return 0;
}