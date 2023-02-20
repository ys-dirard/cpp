#include <iostream>
#include <vector>
using namespace std;

// N: 頂点数, M: 辺の数, A[i]↔B[i]: 無向辺
int N, M, A[100009], B[100009];
// 隣接リスト用vectorの配列
vector<int> graph[100009];
// visited[pos] == false → posは白色、 visited[pos] == true → posは灰色
bool visited[100009];

void dfs(int pos){
    // 頂点posを灰色に塗る
    visited[pos] = true;
    // 隣接する頂点について調べる
    for(int i = 0; i < graph[pos].size(); i++){
        int next = graph[pos][i];
        // 白色の隣接頂点なら、探索を継続
        if(visited[next] == false){
            dfs(next);
        }
    }
    // 頂点posの探索を終えたら抜ける
    // → この抜けることが一歩戻るに対応する
}

int main(){
    // input
    cin >> N >> M;
    for(int i = 1; i <= M; i++){
        cin >> A[i] >> B[i];
        // 頂点A[i]が頂点B[i]と隣接していることを記録
        graph[A[i]].push_back(B[i]);
        // 頂点B[i]が頂点A[i]と隣接していることを記録
        graph[B[i]].push_back(A[i]);
    }

    // 深さ優先探索
    dfs(1);

    // 連結判定
    bool ans = true;
    for(int i = 1; i<=N; i++){
        if(visited[i] == false){
            ans = false;
        }
    }
    if(ans == true) cout << "The graph is connected." << endl;
    else cout << "The graph is not connected." << endl;
    return 0;
}