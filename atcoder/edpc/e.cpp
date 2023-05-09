#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll N, W;
ll w[109], v[109];
ll dp[109][100009]; // i番目の品物までを選んだ時の価値jとなる時の重さの最小値

int main(){
    cin >> N >> W;
    for(int i=1;i<=N;i++){
        cin >> w[i] >> v[i];
    }
    for(int i=0;i<=N;i++){
        for(int j=0;j<=100000;j++){
            dp[i][j] = (1LL<<30);
        }
    }
    dp[0][0] = 0;
    for(int i=1;i<=N;i++){
        for(int j=0;j<=100000;j++){
            if(j-v[i]>=0) dp[i][j] = min({dp[i][j], dp[i-1][j], dp[i-1][j-v[i]]+w[i]});
            else dp[i][j] = min(dp[i-1][j], dp[i][j]);
        }
    }

    ll ans = 0;
    for(int j=0;j<=100000;j++){
        if(dp[N][j]<=W) ans = max(ans, (ll)j);
    }
    cout << ans << endl;
    return 0;
}