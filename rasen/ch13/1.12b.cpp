#include <bits/stdc++.h>
using namespace std;

const int MAX = 10009;

int n, u, k, v, c;
vector<pair<int, int>> g[MAX];
// (cost, point)
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
bool kakutei[MAX];
int dist[MAX];

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> u >> k;
        for(int j=0;j<k;j++){
            cin >> v >> c;
            g[u].push_back({v, c});
        }
    }

    pq.push({0, 0});
    while(!pq.empty()){
        pair<int, int> tmp = pq.top();
        pq.pop();

        if(kakutei[tmp.second]) continue;
        kakutei[tmp.second] = true;
        dist[tmp.second] = tmp.first;

        for(int i=0;i<g[tmp.second].size();i++){
            if(kakutei[g[tmp.second][i].first]) continue;
            pq.push({tmp.first + g[tmp.second][i].second, g[tmp.second][i].first});
        }
    }

    for(int i=0;i<n;i++){
        cout << i << " " << dist[i] << endl;
    }
    return 0;
}