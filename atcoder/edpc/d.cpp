#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll N, W;
ll w[109], v[109];
ll dp[109][100009];

int main(){
    cin >> N >> W;
    for(int i=1;i<=N;i++){
        cin >> w[i] >> v[i];
    }

    for(int i=1;i<=N;i++){
        for(int j=0;j<=W;j++){
            if(j-w[i]>=0) dp[i][j] = max({dp[i][j], dp[i-1][j], dp[i-1][j-w[i]]+v[i]});
            else dp[i][j] = max(dp[i][j], dp[i-1][j]);
        }
    }
    cout << dp[N][W] << endl;
    return 0;
}