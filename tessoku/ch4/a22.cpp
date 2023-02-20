#include <bits/stdc++.h>
using namespace std;
long long N, A[100009], B[100009];
long long dp[100009];

int main(){
    cin >> N;
    for (int i=1; i<N; i++) cin >> A[i];
    for (int i=1; i<N; i++) cin >> B[i];

    dp[1] = 0;
    for (int i=2; i<=N; i++) dp[i] = -(1LL << 30);
    for (int i=1; i<N; i++){
        dp[A[i]] = max(dp[A[i]], dp[i]+100);
        dp[B[i]] = max(dp[B[i]], dp[i]+150);
    }
    cout << dp[N] << endl;
    return 0;
}