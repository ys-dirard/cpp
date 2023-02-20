#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e17;

// ※頂点番号は0-originになっている！！！

struct edge{
    int to, cost;
};

const int MAX_V = 100009;
long long cost[MAX_V][MAX_V];  // 1 cost[u][v]: 辺e=(u, v)のコスト(存在しない場合はINF)
long long dist[MAX_V];         // 1,2,3 頂点sからの最短距離
bool used[MAX_V];              // 1 既に使われたかのフラグ
int V;                         // 1,2,3 頂点数
vector<edge> graph[MAX_V];     // 2,3 隣接リスト
int prev[MAX_V];               // 3 最短路の直前の頂点(-1で初期化しておく)

// Dijkstra法
// 計算量O(|V|^2)
void dijkstra(int s){
    fill(dist, dist+V, INF);
    fill(used, used+V, false);
    dist[s] = 0;

    while(true){
        int v = -1;
        // まだ使われていない頂点から距離が最小のモノを探す
        for(int u=0;u<V;u++){
            if(!used[u] && (v == -1 || dist[u] < dist[v])) v = u;
        }

        if(v == -1) break;

        used[v] = true;

        for(int u=0;u<V;u++){
            dist[u] = min(dist[u], dist[v] + cost[v][u]);
        }
    }
}

// Dijkstra法
// 計算量O(|E| log |V|)
void dijkstra2(int s){
    // first=最短距離, second=頂点番号
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
    fill(dist, dist+V, INF);
    dist[s] = 0;
    pq.push({0, s});

    while(!pq.empty()){
        pair<long long, long long> p = pq.top();
        pq.pop();
        int v = p.second;
        if(dist[v] < p.first) continue;
        // まだ使われていない頂点から距離が最小のモノを探す
        for(int i=0;i<graph[v].size();i++){
            edge e = graph[v][i];
            if(dist[e.to] > dist[v] + e.cost){
                dist[e.to] = dist[v] + e.cost;
                pq.push({dist[e.to], e.to});
            }
        }
    }
}

// Dijkstra法
// 経路復元用
// 計算量O(|E| log |V|)
void dijkstra3(int s){
    // first=最短距離, second=頂点番号
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
    fill(dist, dist+V, INF);
    fill(prev, prev+V, -1);
    dist[s] = 0;
    pq.push({0, s});

    while(!pq.empty()){
        pair<long long, long long> p = pq.top();
        pq.pop();
        int v = p.second;
        if(dist[v] < p.first) continue;
        // まだ使われていない頂点から距離が最小のモノを探す
        for(int i=0;i<graph[v].size();i++){
            edge e = graph[v][i];
            if(dist[e.to] > dist[v] + e.cost){
                dist[e.to] = dist[v] + e.cost;
                pq.push({dist[e.to], e.to});
                // 最短距離が更新されたときにprevを書き換える
                prev[v] = e.to;
            }
        }
    }
}

// 頂点tへの最短経路
// prevから復元
vector<int> get_path(int t){
    vector<int> path;
    while(t!=-1){
        path.push_back(t);
        t = prev[t];
    }
    reverse(path.begin(), path.end());
    return path;
}

// 頂点tへの最短経路
// distから復元
vector<int> get_path2(int t){
    vector<int> path;
    path.push_back(t);
    while(dist[t]!=0){
        for(int i=0;i<graph[t].size();i++){
            edge e = graph[t][i];
            if(dist[e.to] == dist[t] - e.cost){
                t = e.to;
                path.push_back(t);
                break;
            }
        }
    }
    reverse(path.begin(), path.end());
    return path;
}

int main(){
    return 0;
}