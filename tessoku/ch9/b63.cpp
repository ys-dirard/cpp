#include <bits/stdc++.h>
using namespace std;

int R,C, sy, sx, gy, gx,A[100009],B[100009];
bool visited[59][59];
char c[59][59];
queue<pair<int, int>> q;
int path[59][59];

int main(){
    cin >> R >> C >> sy >> sx >> gy >> gx;
    for(int i=1;i<=R;i++){
        for(int j=1;j<=C;j++){
            cin >> c[i][j];
        }
    }

    path[sy][sx] = 0;
    visited[sy][sx] = true;
    q.push(make_pair(sy, sx));
    while(!q.empty()){
        pair<int, int> pos = q.front();
        q.pop();

        if(!visited[pos.first+1][pos.second] && c[pos.first+1][pos.second]=='.'){
            path[pos.first+1][pos.second] = path[pos.first][pos.second] + 1;
            visited[pos.first+1][pos.second] = true;
            q.push(make_pair(pos.first+1, pos.second));
        }
        if(!visited[pos.first-1][pos.second] && c[pos.first-1][pos.second]=='.'){
            path[pos.first-1][pos.second] = path[pos.first][pos.second] + 1;
            visited[pos.first-1][pos.second] = true;
            q.push(make_pair(pos.first-1, pos.second));
        }
        if(!visited[pos.first][pos.second+1] && c[pos.first][pos.second+1]=='.'){
            path[pos.first][pos.second+1] = path[pos.first][pos.second] + 1;
            visited[pos.first][pos.second+1] = true;
            q.push(make_pair(pos.first, pos.second+1));
        }
        if(!visited[pos.first][pos.second-1] && c[pos.first][pos.second-1]=='.'){
            path[pos.first][pos.second-1] = path[pos.first][pos.second] + 1;
            visited[pos.first][pos.second-1] = true;
            q.push(make_pair(pos.first, pos.second-1));
        }
    }

    cout << path[gy][gx] << endl;
    return 0;
}