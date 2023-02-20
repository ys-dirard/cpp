#include <bits/stdc++.h>
using namespace std;

// 迷路の最短路
// 
// 大きさがNxMの迷路がある。迷路は通路と壁からできている。
// 移動は上下左右の4マスが可能。
// スタートからゴールまでの最短移動回数はいくつか？
// 
// 制約：
// 1<=N, M <=100

int N, M;
vector<string> a(101);
vector<vector<int>> visited(101, vector<int>(101, -1));
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};


// (i, j): 現在のマス、k: 何番目の連結成分か?
int bfs(int si, int sj, int gi, int gj){
    queue<pair<int, int>> q;
    visited[si][sj] = 0;
    q.push({si, sj});

    while(!q.empty()){
        pair<int, int> tmp = q.front();
        int ti = tmp.first;
        int tj = tmp.second;
        q.pop();
        if(ti==gi && tj==gj) break;
        

        for(int k=0;k<4;k++){
            int ni = ti + dy[k];
            int nj = tj + dx[k];

            if(ni >=0 && ni <N && nj >=0 && nj <M && a[ni][nj] == '.' && visited[ni][nj]==-1){
                q.push({ni, nj});
                visited[ni][nj] = visited[ti][tj] + 1;
            }    
        }
    }
    return visited[gi][gj];    
}

int main(){
    // input Wが水たまり
    N = 10, M = 10;
    a = {"#S######.#",
         "......#..#",
         ".#.##.##.#",
         ".#........",
         "##.##.####",
         "....#....#",
         ".#######.#",
         "....#.....",
         ".####.###.",
         "....#...G#"};
    // 3
    
    int si, sj, gi, gj;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(a[i][j]=='S'){
                si = i;
                sj = j;
                a[i][j] = '.';
            }else if(a[i][j]=='G'){
                gi = i;
                gj = j;
                a[i][j] = '.';
            }
        }
    }
    int ans = bfs(si, sj, gi, gj);
    cout << ans << endl;
    // for(int i=0;i<N;i++){
    //     for(int j=0;j<M;j++){
    //         cout << visited[i][j] << " ";
    //     }
    //     cout << endl;
    // }
}