#include <bits/stdc++.h>
using namespace std;

long long N, W, L, R, X[150009];
long long dp[150009], sum[150009];
long long wari = 1000000007;

int main(){
    cin >> N >> W >> L >> R;
    for(int i=1;i<=N;i++) cin >> X[i];
    X[0] = 0;
    X[N+1] = W;

    dp[0] = 1;
    sum[0] = 1;
    for(int i=1;i<=N+1;i++){
        long long posL = lower_bound(X, X+N+2, X[i]-R) - X;
        long long posR = lower_bound(X, X+N+2, X[i]-L+1) - X;
        posR--;

        dp[i] = sum[posR];
        if(posL >= 1) dp[i] -= sum[posL - 1];
        dp[i] = (dp[i] + wari) % wari;
        sum[i] = sum[i-1] + dp[i];
    }
    cout << dp[N+1] << endl;
    return 0;
}