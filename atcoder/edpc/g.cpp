#include <bits/stdc++.h>
using namespace std;

int N, M;
int x[100009], y[100009];
vector<int> g[100009];
int dp[100009];

int dfs(int p, int n){
    // if(g[p].size()==0){
    //     return n;
    // }
    int mx = 0;
    for(int i=0;i<g[p].size();i++){
        int nex = g[p][i];
        int nn;
        if(dp[nex]>=0){
            nn = dp[nex] + 1;
        }else{
            nn = dfs(nex, n+1);
        }
        mx = max(mx, nn);
    }
    dp[p] = mx;
    return mx + 1;
}

int main(){
    cin >> N >> M;
    for(int i=1;i<=M;i++){
        cin >> x[i] >> y[i];
        g[x[i]].push_back(y[i]);
    }
    for(int i=1;i<=N;i++) dp[i] = -1;

    for(int i=1;i<=N;i++){
        if(dp[i]==-1) dfs(i, 0);
    }
    
    int ans = 0;
    for(int i=1;i<=N;i++){
        ans = max(ans, dp[i]);
    }

    // for(int i=1;i<=N;i++){
    //     cout << dp[i] << " ";
    // }
    // cout << endl;
    cout << ans << endl;
    return 0;
}