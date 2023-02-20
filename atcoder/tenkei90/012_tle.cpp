#include <bits/stdc++.h>
using namespace std;

class Point{
    public:
    int x, y;

    Point(int x, int y): x(x), y(y){}
};

int H, W, Q;
bool red[2009][2009];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int t, r, c, ra, ca, rb, cb;
bool visited[2009][2009];

bool dfs(int tx, int ty, int x, int y, int px, int py){
    // cout << "(" << x << ", " << y << ")" << endl;
    visited[x][y] = true;
    if(x == tx && y == ty) return true;
    bool flg = false;
    for(int i=0;i<4;i++){
        if(x+dx[i] >= 1 && x+dx[i] <=H && y+dy[i] >= 1 && y+dy[i] <=W && !(visited[x+dx[i]][y+dy[i]]) && red[x+dx[i]][y+dy[i]]){
            flg |= dfs(tx, ty, x+dx[i], y+dy[i], x, y);
        }
    }
    return flg;
}

void init(){
    for(int i=1;i<=H;i++){
        for(int j=1;j<=W;j++){
            visited[i][j] = false;
        }
    }
}

int main(){
    cin >> H >> W >> Q;
    for(int i=0;i<=H;i++){
        for(int j=0;j<=W;j++){
            red[i][j] = false;
        }
    }

    for(int i=1;i<=Q;i++){
        cin >> t;
        if(t==1){
            cin >> r >> c;
            red[r][c] = true;
        }else{
            cin >> ra >> ca >> rb >> cb;
            init();
            bool flg = dfs(rb, cb, ra, ca, ra, ca);
            if(!red[ra][ca]) flg = false;

            if(flg) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
    return 0;
}