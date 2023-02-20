#include <bits/stdc++.h>
using namespace std;

// Lake Counting (POJ No.2386)
// 
// 大きさがNxMの庭がある。そこに雨が降り水たまりができる。
// 水たまりは8近傍で隣接しているときにつながっているとみなす。
// 全部でいくつの水たまりがあるか？
// 
// 制約：
// 1<=N, M <=100

// dfsで連結成分の数を求める(bfsとかunionfindでもいけるはず)

int N, M;
vector<string> a(101);
vector<vector<int>> visited(101, vector<int>(101, -1));
int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};


// (i, j): 現在のマス、k: 何番目の連結成分か?
void dfs(int i, int j, int k){
    visited[i][j] = k;
    // a[i][j] = '.';

    for(int l=0;l<8;l++){
        if(i+dy[l] >=0 && i+dy[l] <N && j+dx[l] >=0 && j+dx[l] <M && a[i+dy[l]][j+dx[l]] == 'W' && visited[i+dy[l]][j+dx[l]]==-1){
            dfs(i+dy[l], j+dx[l], k);
        }
    }    
}

int main(){
    // input Wが水たまり
    N = 10, M = 12;
    a = {"W........WW.",
         ".WWW.....WWW",
         "....WW...WW.",
         ".........WW.",
         ".........W..",
         "..W......W..",
         ".W.W.....WW.",
         "W.W.W.....W.",
         ".W.W......W.",
         "..W.......W."};
    // 3
    
    int cnt = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(visited[i][j]==-1 && a[i][j]=='W'){
                dfs(i, j, cnt++);
            }
        }
    }
    cout << cnt << endl;
}