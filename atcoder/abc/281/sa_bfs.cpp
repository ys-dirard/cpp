#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// N: 頂点数, M: 辺の数, A[i]↔B[i]: 無向辺
int N, M, A[100009], B[100009];
// 隣接リスト用vectorの配列
vector<int> graph[100009];
// 最短距離記録用配列
// dist[pos] == -1 → posは白色、 
// visited[pos] != -1 → posは灰色
int dist[100009];

void bfs(int start){
    // distの初期化(すべて白色に塗る)
    for(int i = 1; i <= N; i++) dist[i] = -1;
    
    // キューの準備
    queue<int> Q;
    
    // 頂点posを灰色に塗り、キューに追加(最短距離更新)
    dist[start] = 0;
    Q.push(start);

    // キューが空になるまで繰り返す
    while(!Q.empty()){
        // キューの先頭を取り出す
        int pos = Q.front();
        Q.pop();
        // 隣接する頂点について調べる
        for(int i = 0; i < graph[pos].size(); i++){
            int next = graph[pos][i];
            // 隣接する頂点が白色なら
            // 灰色に塗りキューに追加(最短距離更新)
            if(dist[next] == -1){
                dist[next] = dist[pos] + 1;
                Q.push(next);
            }
        }
    }
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

    // 幅優先探索(頂点1からスタート)
    bfs(1);

    // 各頂点への最短距離を出力
    for(int i = 1; i<=N; i++) cout << dist[i] << endl;
    
    return 0;
}