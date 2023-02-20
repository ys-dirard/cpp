#include <bits/stdc++.h>
using namespace std;

int H, W;
char c[20][20];
bool visited[20][20];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int dfs(int x, int y, int sx, int sy, int l){
    // cout << x << " " << y << endl;
    if(x==sx && y==sy && l>0) return l;
    int len = -1;
    if(x!=sx || y!=sy) visited[x][y] = true;

    for(int i=0;i<4;i++){
        int tx = x+dx[i];
        int ty = y+dy[i];
        if(tx>=1 && tx<=H && ty>=1 && ty<=W && c[tx][ty]=='.' && !visited[tx][ty]){
            len = max(len, dfs(tx, ty, sx, sy, l+1));
        }
    }

    visited[x][y] = false;
    return len;
}

int main(){
    cin >> H >> W;
    for(int i=1;i<=H;i++){
        for(int j=1;j<=W;j++){
            cin >> c[i][j];
            visited[i][j] = false;
        }
    }

    int ans = -1;
    for(int i=1;i<=H;i++){
        for(int j=1;j<=W;j++){
            if(c[i][j]=='.'){
                ans = max(ans, dfs(i, j, i, j, 0));
            }
        }
    }
    if(ans >= 4) cout << ans << endl;
    else cout << -1 << endl;
    return 0;
}