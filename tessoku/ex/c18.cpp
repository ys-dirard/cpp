#include <bits/stdc++.h>

#define rep(i,s,n) for(int i = s; i < n; i++)
#define ll long long
#define P pair<ll, ll>

using namespace std;

int N, A[409];
int dp[409][409];

int main(){
    cin >> N;
    rep(i, 1, 2*N+1) cin >> A[i];

    rep(i, 1, 2*N+1){
        rep(j, 1, 2*N+1) dp[i][j] = 1000000000;
    }

    rep(i, 1, 2*N) dp[i][i+1] = abs(A[i] - A[i+1]);

    rep(LEN, 2, 2*N){
        for(int l=1;l<=2*N-LEN;l++){
            int r = l + LEN;

            dp[l][r] = min(dp[l][r], dp[l+1][r-1] + abs(A[l]-A[r]));

            for(int m=l;m<r;m++){
                dp[l][r] = min(dp[l][r], dp[l][m] + dp[m+1][r]);
            }
        }
    }

    cout << dp[1][2*N] << endl;
    return 0;
}