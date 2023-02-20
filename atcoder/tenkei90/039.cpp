#include <bits/stdc++.h>
using namespace std;
#define ll long long

// 辺で2つのグループに分かれるとき、その辺を何回通過するか(足されるか)を考える
// 通過回数は各グループに属するノードの積(組み合わせ総数)で求まる
// 根を決めてdfsで子を含むグループの頂点数を求めていけばO(N)で解ける

ll N, a[100009], b[100009];
vector<ll> g[100009];
ll ans = 0;
vector<ll> dp(100009, 0);

void dfs(int pos, int par){
    ll tmp = 1;
    for(int i=0;i<g[pos].size();i++){
        int next = g[pos][i];
        if(next == par) continue;
        dfs(next, pos);
        tmp += dp[next];
    }
    dp[pos] = tmp;

    ans += dp[pos] * (N - dp[pos]);
}

int main(){
    cin >> N;
    for(int i=1;i<N;i++){
        cin >> a[i] >> b[i];
        g[a[i]].push_back(b[i]);
        g[b[i]].push_back(a[i]);
    }
    
    for(int i=0;i<g[1].size();i++){
        dfs(g[1][i], 1);
    }

    cout << ans << endl;
    return 0;
}