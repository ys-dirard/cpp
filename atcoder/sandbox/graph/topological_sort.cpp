#include <bits/stdc++.h>
using namespace std;

int N, M;
int A[100009], B[100009];
vector<vector<int>> g(100009, vector<int>());
vector<bool> visited(100009, false);
deque<int> ans;

// トポロジカルソート(dfs版)、サイクルがなく可能であれば(DAGであれば)trueを返す、サイクルがあればfalseを返す
// トポロジカルソートはDAGのでの概念
// スタートのposは葉からスタートする必要がある
bool dfs(int pos, int par){
    bool no_cycle = true;
    if(visited[pos]) return false;
    visited[pos] = true;
    for(int i=0;i<g[pos].size();i++){
        if(g[pos][i] != par){
            no_cycle &= dfs(g[pos][i], pos);
        }
    }
    ans.push_front(pos);
    return no_cycle;
};

int main(){
    cin >> N >> M;
    for(int i=1;i<=M;i++){
        cin >> A[i] >> B[i];
        // A[i] -> B[i] に辺を張る
        g[A[i]].push_back(B[i]);
    }

    bool no_cycle = dfs(1, -1);
    if(no_cycle) cout << "DAG" << endl;
    else cout << "cycle" << endl;
    for(int i=0;i<ans.size();i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}


// BFS版、queueをpriority_queueにすると辞書順にソート可能！
// using Graph = vector<vector<int>>;

// int main() {
//     // 頂点数と辺数
//     int N, M; cin >> N >> M;

//     // グラフ入力受取
//     Graph G(N+1);
//     vector<int> deg(N+1, 0); // 各頂点の出次数
//     for (int i = 1; i <= M; ++i) {
//         int a, b;
//         cin >> a >> b;
//         G[a].push_back(b); // 辺を張る
//         deg[b]++; // 入次数
//     }

//     // シンクたちをキューに挿入する
//     queue<int> que;
//     for (int i = 1; i <= N; ++i) if (deg[i] == 0) que.push(i);

//     // 探索開始
//     vector<int> order;
//     while (!que.empty()) {
//         // キューから頂点を取り出す
//         int v = que.front(); que.pop();
//         order.push_back(v);

//         // v へと伸びている頂点たちを探索する
//         for (auto nv : G[v]) {
//             // 辺 (nv, v) を削除する
//             --deg[nv];

//             // それによって nv が新たにシンクになったらキューに挿入
//             if (deg[nv] == 0) que.push(nv); 
//         }
//     }

//     return 0;
// }