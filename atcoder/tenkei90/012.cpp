#include <bits/stdc++.h>
using namespace std;

int parent[5000009], siz[5000009];

class UnionFind{
public:
    // int parent[4000009], siz[4000009];

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

int H, W, Q;
int t, r, c, ra, ca, rb, cb;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
bool red[2009][2009];

int main(){
    cin >> H >> W >> Q;
    UnionFind uf;
    uf.init((H+1)*(W+1)); // numbering = i*W+j
    for(int i=1;i<=H;i++){
        for(int j=1;j<=W;j++){
            red[i][j] = false;
        }
    }

    for(int i=1;i<=Q;i++){
        cin >> t;
        if(t==1){
            cin >> r >> c;
            red[r][c] = true;
            // uf.unite(0, r*W+c);
            for(int i=0;i<4;i++){
                if(r+dx[i]>=1 && r+dx[i]<=H && c+dy[i]>=1 && c+dy[i]<=W && red[r][c] && red[r+dx[i]][c+dy[i]] && !uf.same((r-1)*W+c, (r-1+dx[i])*W+c+dy[i])) uf.unite((r-1)*W+c, (r-1+dx[i])*W+c+dy[i]);
            }
        }else{
            cin >> ra >> ca >> rb >> cb;

            // cout << uf.root(ra*W+ca) << " " << uf.root(rb*W+cb) << endl;
            if(red[ra][ca] && red[rb][cb] && uf.same((ra-1)*W+ca, (rb-1)*W+cb)) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }

    return 0;
}