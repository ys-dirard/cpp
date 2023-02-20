#include <bits/stdc++.h>
using namespace std;
#define P pair<int, int>
const int INF = 1<<30;

// Roadblocks (POJ No.3255)

// R本の道とN個の交差点がある。道路は両方向に通行可能。
// 1番の交差点からN番の交差点への2番目の最短路の長さを求めなさい。
// ただし、2番目の最短路とは最短路よりも真に長いもののうちで
// 最短のものをいう。同じ道路を複数通ってもかまわない。
// 
// 制約：
// 1<=N<=5000
// 1<=R<=100000

// dijkstra
// dist1 : 最短路, dist2 : 2番目の最短路
// dist < dist1 -> dist1 = dist, dist2 = dist1
// else if dist == dist1 continue
// else if dist < dist2 -> dist2 = dist (dist1 < dist)

struct edge{
    int to, cost;
};

int N, R;
vector<vector<edge>> g;
vector<int> dist1, dist2;

void init(int N){
    g.resize(N+1);
    dist1.resize(N+1, INF);
    dist2.resize(N+1, INF);
}

void dijkstra(int s){
    dist1[s] = 0;
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push({0, s});

    while(!pq.empty()){
        P p = pq.top();
        pq.pop();
        int v = p.second;
        if(p.first > dist2[v]) continue;

        for(int i=0;i<g[v].size();i++){
            edge e = g[v][i];
            int dist = p.first + e.cost;
            if(dist < dist1[e.to]){
                dist2[e.to] = dist1[e.to];
                dist1[e.to] = dist;
                pq.push({dist, e.to});
            }else if(dist == dist1[e.to]){
                continue;
            }else if(dist < dist2[e.to]){
                dist2[e.to] = dist;
                pq.push({dist, e.to});
            }
        }
    }
}

int main(){
    // input
    // N R
    // A_1 B_1 C_1
    // ...
    // A_R B_R C_R

    cin >> N >> R;
    init(N);
    int a, b, c;
    for(int i=1;i<=R;i++){
        cin >> a >> b >> c;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }

    dijkstra(1);
    cout << dist2[N] << endl;
    return 0;
}