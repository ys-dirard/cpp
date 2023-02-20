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

class state{
public:
    ll c, l, r;
    state(int c=0, int l=0, int r=0): c(c), l(l), r(r){}

    bool operator<(state s){
        return this->c < s.c;
    }
};

int N, M;
ll C[100009], L[100009], R[100009];
state s[100009];
UnionFind uf;

int main(){
    cin >> N >> M;
    for(int i=1;i<=M;i++){
        cin >> C[i] >> L[i] >> R[i];
        s[i] = state(C[i], L[i], R[i]);
    }

    sort(s+1, s+M+1);
    uf.init(N+1);
    
    ll cost = 0;
    for(int i=1;i<=M;i++){
        if(!uf.same(s[i].l-1, s[i].r)){
            uf.unite(s[i].l-1, s[i].r);
            cost += s[i].c;
        }
    }

    set<int> rt;
    for(int i=0;i<=N;i++){
        rt.insert(uf.root(i));
        // cout << uf.root(i) << endl;
    }

    if(rt.size() == 1) cout << cost << endl;
    else cout << -1 << endl;
    return 0;
}