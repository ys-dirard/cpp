#include <bits/stdc++.h>
using namespace std;

int n, u, k, tmp;
vector<int> g[109];
int d[109], f[109], cnt[109], visited[109];
int t = 0;

void dfs(int u, int par){
    if(visited[u]) return;
    // cout << "i: " << u << endl;
    visited[u] = true;
    t++;
    d[u] = t;
    cnt[u]++;

    for(int i=0;i<g[u].size();i++){
        if(g[u][i] == par) continue;
        else{
            dfs(g[u][i], u);
        }
    }
    t++;
    f[u] = t;
    
}

int main(){
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> u >> k;
        for(int j=1;j<=k;j++){
            cin >> tmp;
            g[u].push_back(tmp);
        }
    }
    for(int i=1;i<=n;i++){
        d[i] = f[i] = cnt[i] = visited[i] = 0;
    }

    // dfs(1, 0);
    for(int i=1;i<=n;i++){
        if(g[i].size() == 0 || g[i].size() != cnt[i]) dfs(i, 0);
    }
    for(int i=1;i<=n;i++){
        cout << i << " " << d[i] << " " << f[i] << endl;
    }
    return 0;
}