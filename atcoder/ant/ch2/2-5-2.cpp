#include <bits/stdc++.h>
using namespace std;

// Conscription (POJ No.3723)

/*
N人の女とM人の男を徴兵したい。一人を徴兵するには10000ドルのコストがかかる。
既に親しい間柄の人が徴兵されている場合、より安い費用で徴兵が可能。
いくつかの男女の間には1~9999の親密度が定まっており、
ある人を徴兵する際の費用は10000-(既に徴兵されている人のうちで最も高い親密度)
となる。
全員を徴兵するのに最小な費用はいくらか？

制約：
1<=N, M<=10000
0<=R<=50000 (親密な関係の数)
0<d<10000 (親密度)

unionfindっぽい
人aを徴兵するときに人bとの関係を使う場合にab間の辺を張ることを考える
→閉路は存在しない
→最終的に(有向)森になる
→krascal

入力例：
[N M R]
[x y d] x R
5 5 8
4 3 6831
1 3 4583
0 0 6592
0 1 3063
3 3 4975
1 3 2049
4 2 2104
2 2 781

出力：
71071
*/

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

int N, M, R;
int x[50009], y[50009], d[50009];
UnionFind uf;
vector<edge> v;

int main(){
    cin >> N >> M >> R;
    for(int i=0;i<R;i++){
        cin >> x[i] >> y[i] >> d[i];
        // 男は+Nしておく
        v.push_back({x[i], y[i]+N, d[i]});
    }
    sort(v.begin(), v.end(), comp);
    reverse(v.begin(), v.end());

    uf.init(N+M);

    int good = 0;
    for(int i=0;i<v.size();i++){
        if(!uf.same(v[i].u, v[i].v)){
            good += v[i].cost;
            uf.unite(v[i].u, v[i].v);
        }
    }
    cout << (N + M) * 10000 - good << endl;
    return 0;
}