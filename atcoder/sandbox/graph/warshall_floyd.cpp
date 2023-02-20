#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e17;

/* warshall_floyd(dist)
    入力：初期化した dist
    計算量：O(|V|^3)
    副作用：dis[i][j]にiからjへの最短路のコストを格納
*/
void warshall_floyd(vector<vector<long long>> &dist) {
    int V = dist.size();
    for (int k = 0; k < V; k++) { // 経由点
        for (int i = 0; i < V; i++) { // 始点
            for (int j = 0; j < V; j++) { // 終点
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

/* warshall_floyd_restoraction(dist,prev)
    入力：初期化した dist, prev
    計算量：O(|V|^3)
    副作用：dis[i][j]にiからjへの最短路のコストを格納、prev[i][j]にiからjへの最短路でのjの1つ前の点を格納
    prevは prev[i][j] = i で初期化しておく
*/
void warshall_floyd_restoraction(vector<vector<long long>> &dist, vector<vector<long long>> &prev) {
    int V = dist.size();
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    prev[i][j] = prev[k][j];
                }
            }
        }
    }
}

/* get_path(prev, s, t)
    入力：warshall_floyd で得た prev, スタート s, ゴール t
    出力：s から t への最短路のパス
*/
vector<int> get_path(const vector<vector<long long>> &prev, int s, int t) {
    vector<int> path;
    for (int cur = t; cur != s; cur = prev[s][cur]) {
        path.push_back(cur);
    }
    path.push_back(s);
    reverse(path.begin(), path.end());
    return path;
}

/* warshall_floyd_restoraction2(dist,prev)
    入力：初期化した dist, prev
    計算量：O(|V|^3)
    副作用：dis[i][j]にiからjへの最短路のコストを格納、next[i][j]にiからjへの最短路でのjの1つ後の点を格納
    nextは next[i][j] = j で初期化しておく
*/
void warshall_floyd_restoraction2(vector<vector<long long>> &dist, vector<vector<long long>> &next) {
    int V = dist.size();
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    next[i][j] = next[i][k];
                }
            }
        }
    }
}

/* get_path2(prev, s, t) reconstruction2に対応
    入力：warshall_floyd で得た next, スタート s, ゴール t
    出力：s から t への最短路のパス
*/
vector<int> get_path(const vector<vector<long long>> &next, int s, int t) {
    vector<int> path;
    for (int cur = s; cur != t; cur = next[cur][t]) {
        path.push_back(cur);
    }
    path.push_back(t);
    return path;
}

/* is_negative(dist)
    入力：warshall_floyd で得た dist
    出力：負の有向路を含むかどうか(負の閉路検出)
*/
bool is_negative(const vector<vector<long long>> &dist) {
    int V = dist.size();
    for (int i = 0; i < V; i++) {
        if (dist[i][i] < 0) {
            return true;
        }
    }
    return false;
}

// 隣接行列形式
vector<vector<long long>> dist = {{0, 5, -1, INF},
                                  {INF, 0, INF, 3},
                                  {INF, INF, 0, 1},
                                  {INF, INF, 4, 0}};

// long long N ;
// vector<vector<long long>> dist(N, vector<long long>(N));

int main() {
    int V = (int)dist.size();  // 頂点数
    warshall_floyd(dist);      // 更新

    // 出力
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] >= INF / 2) {
                cout << "INF";
            } else {
                cout << dist[i][j];
            }
            if (j != V - 1) {
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}