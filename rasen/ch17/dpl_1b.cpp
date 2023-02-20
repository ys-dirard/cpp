#include <bits/stdc++.h>
using namespace std;

int N, W;
int v[109], w[109];
int dp[109][10009];

int main(){
    cin >> N >> W;
    for(int i=1;i<=N;i++) cin >> v[i] >> w[i];

    for(int i=0;i<=N;i++){
        for(int j=0;j<=W;j++){
            dp[i][j] = -(1<<30);
        }
    }

    dp[0][0] = 0;
    for(int i=1;i<=N;i++){
        for(int j=0;j<=W;j++){
            dp[i][j] = max(dp[i][j], dp[i-1][j]);
            if(j-w[i]>=0){
                dp[i][j] = max(dp[i][j], dp[i-1][j-w[i]]+v[i]);
            }
        }
    }
    int ans = 0;
    for(int j=0;j<=W;j++){
        ans = max(ans, dp[N][j]);
    }
    cout << ans << endl;
    return 0;
}