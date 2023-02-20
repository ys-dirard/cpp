#include <bits/stdc++.h>
using namespace std;

long long N, W, w[109], v[109], V=100000;
// 品物iまでで価値がjになる中の重さの最小値
long long dp[109][100009];

int main(){
    cin >> N >> W;
    for (int i=1; i<=N; i++) cin >> w[i] >> v[i];
    for (int i=0; i<=N; i++){
        for (int j=0; j<=V;j++){
            dp[i][j] = (1LL << 30);
        }
    }

    dp[0][0] = 0;
    for (int i=1; i<=N; i++){
        for (int j=0; j<=V;j++){
            if (j >= v[i]) {
                dp[i][j] = min(dp[i-1][j], dp[i-1][j-v[i]]+w[i]);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    long long ans = 0;
    for (int j=1; j<=V; j++) {
        if (dp[N][j] <= W) ans = j;
    }

    cout << ans << endl;
    return 0;
}