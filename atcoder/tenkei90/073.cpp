#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 1e9 + 7LL;

ll N;
char c[100009];
ll a[100009], b[100009];
vector<ll> g[100009];
ll dp[100009][3];
// pos=1を根とする木について以下を考える
// dp[i][j]: pos=iを含む部分木が状態jであるような辺の削除の通り数
// 状態 0: 赤のみ, 1: 青のみ, 2: 赤青両方含む (aを赤、bを青とする)
// 部分木について、pos=iを含まない部分(削除されて切り離された部分)は赤青両方含んでいる必要がある
// 状態遷移について：
// c[pos=i]=赤のときを考えると
// dp[pos][0] = Π_child(dp[b_k][0] + dp[b_k][2])
// # posとb_kの辺について考えると、つなぐ場合はdp[b_k][0]通り、
// # 削除する場合は切り離した部分が赤白両方持つ必要があるのでdp[b_k][2]通り
// dp[pos][1] = 0 # 青しか含まない状態はありえない
// dp[pos][2] = Π_child(dp[b_k][0] + dp[b_k][1] + 2 * dp[pos][2]) - Π_child(dp[b_k][0] + dp[b_k][2])
// # dp[pos][2]は辺のつなぎ方(削除の仕方)の総数から赤のみになる総数(dp[pos][0])を引いたもの
// # 総数についてはposとb_kの辺について考えると、つなぐ操作はb_kが土の状況でも可能なので
// # dp[b_k][0] + dp[b_k][1] + dp[pos][2]通り、
// # 削除する場合は切り離した部分が赤白両方持つ必要があるのでdp[b_k][2]通り
// 
// c[pos=i]=青の場合も同様に考えればよい

void dfs(ll pos, ll par){
    ll val1 = 1LL; // posと同色のみのパターン
    ll val2 = 1LL; // 赤青両方含むパターン

    int single = c[pos] - 'a';

    for(int child : g[pos]){
        if(child == par) continue;
        dfs(child, pos);

        val1 *= (dp[child][single] + dp[child][2]) % mod;
        val2 *= (dp[child][0] + dp[child][1] + 2LL * dp[child][2]) % mod;
        val1 %= mod;
        val2 %= mod;
    }

    dp[pos][single] = val1;
    dp[pos][2] = (val2 - val1 + mod) % mod;
}

int main(){
    cin >> N;
    for(int i=1;i<=N;i++) cin >> c[i];
    for(int i=1;i<N;i++){
        cin >> a[i] >> b[i];
        g[a[i]].push_back(b[i]);
        g[b[i]].push_back(a[i]);
    }
    for(int i=1;i<=N;i++){
        for(int j=0;j<3;j++){
            dp[i][j] = 0LL;
        }
    }

    dfs(1, -1);
    // for(int i=1;i<=N;i++){
    //     for(int j=0;j<3;j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    cout << dp[1][2] << endl;

    return 0;
}