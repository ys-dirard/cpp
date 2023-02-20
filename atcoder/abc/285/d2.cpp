#include <bits/stdc++.h>
using namespace std;

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

int N;
string S[100009], T[100009];
map<string, int> str2int;
UnionFind uf;

int main(){
    cin >> N;
    int cnt = 0;
    for(int i=1;i<=N;i++){
        cin >> S[i] >> T[i];
        if(str2int[S[i]] == 0) str2int[S[i]] = cnt++;
        if(str2int[T[i]] == 0) str2int[T[i]] = cnt++;
    }

    uf.init(cnt);

    bool flg = false;
    for(int i=1;i<=N;i++){
        if(uf.same(str2int[S[i]], str2int[T[i]])) flg = true;
        else uf.unite(str2int[S[i]], str2int[T[i]]);
    }

    if(flg) cout << "No" << endl;
    else cout << "Yes" << endl;
    return 0;
}