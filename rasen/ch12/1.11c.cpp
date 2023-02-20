#include <bits/stdc++.h>
using namespace std;

int n, u, k, tmp;
vector<int> g[109];
queue<int> q;
vector<int> dist(109, -1);

int main(){
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> u >> k;
        for(int j=1;j<=k;j++){
            cin >> tmp;
            g[u].push_back(tmp);
        }
    }
    dist[1] = 0;
    q.push(1);
    while(!q.empty()){
        int p = q.front();
        q.pop();
        for(int i=0;i<g[p].size();i++){
            if(dist[g[p][i]] != -1) continue;
            dist[g[p][i]] = dist[p] + 1;
            q.push(g[p][i]);
        }
    }

    for(int i=1;i<=n;i++) cout << i << " " << dist[i] << endl;
    return 0;
}