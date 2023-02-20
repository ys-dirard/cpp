#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll N, M;
ll A[200009], B[200009];
vector<ll> g[100009];
vector<ll> rg[100009];
vector<bool> visited(100009, false);
vector<ll> num(100009, -1);
vector<ll> scc[100009];

ll cnt = 0;
void dfs(ll s){
    visited[s] = true;
    for(int i=0;i<g[s].size();i++){
        if(visited[g[s][i]]) continue;
        dfs(g[s][i]);
    }
    num[++cnt] = s;
}

void dfs_rev(ll s, ll n){
    visited[s] = true;
    for(int i=0;i<rg[s].size();i++){
        if(visited[rg[s][i]]) continue;
        dfs_rev(rg[s][i], n);
    }
    scc[n].push_back(s);
}

int main(){
    cin >> N >> M;
    for(int i=1;i<=M;i++){
        cin >> A[i] >> B[i];
        g[A[i]].push_back(B[i]);
        g[B[i]].push_back(A[i]);
        rg[A[i]].push_back(B[i]);
        rg[B[i]].push_back(A[i]);
    }

    for(int i=1;i<=N;i++){
        if(!visited[i]) dfs(i);
    }
    // for(int i=1;i<=N;i++){
    //     cout << num[i] << " ";
    // }
    // cout << endl;

    // visited.resize(N+1, false);
    for(int i=1;i<=N;i++){
        visited[i] = false;
        // cout << visited[i] << " ";
    }
    // cout << endl;
    int c = 0;
    for(int i=N;i>=1;i--){
        // cout << "rev" << endl;
        if(!visited[num[i]]){
            // cout << "start: " << num[i] << endl;
            dfs_rev(num[i], c++);
            // cout << cb << endl;
        }
    }
    // ll ans = 0;
    // for(int i=0;i<c;i++){
    //     ans += scc[i].size()*(scc[i].size()-1)/2;
    //     // cout << scc[i].size() << endl;
    // }
    cout << c << endl;
    return 0;
}