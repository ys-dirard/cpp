#include <bits/stdc++.h>
using namespace std;

int v, e, s, t;
int parent[100009], prenum[100009], lowest[100009];
bool kakutei[100009];
vector<int> g[100009];

int timer = 0;
set<int> ap;

void dfs(int u, int p){
    prenum[u] = lowest[u] = ++timer;
    kakutei[u] = true;

    for(int i=0;i<g[u].size();i++){
        if(!kakutei[g[u][i]]){
            parent[g[u][i]] = u;
            dfs(g[u][i], u);

            lowest[u] = min(lowest[u], lowest[g[u][i]]);
        }else if(g[u][i] != p){
            lowest[u] = min(lowest[u], prenum[g[u][i]]);
        }
    }
}

int main(){
    cin >> v >> e;
    for(int i=0;i<v;i++){
        parent[i] = prenum[i] = -1;
        lowest[i] = (1<<30);
        kakutei[i] = false;
    }
    for(int i=0;i<e;i++){
        cin >> s >> t;
        g[s].push_back(t);
        g[t].push_back(s);
    }

    dfs(0, -1);

    int np = 0;
    for(int i=0;i<v;i++){
        if(parent[i] == 0) np++;
        else if(parent[i] != -1 && prenum[parent[i]] <= lowest[i]) ap.insert(parent[i]);
    }
    if(np > 1) ap.insert(0);

    for(auto itr=ap.begin();itr!=ap.end();itr++){
        cout << *itr << endl;
    }
    return 0;
}