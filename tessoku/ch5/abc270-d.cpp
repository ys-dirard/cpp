#include <bits/stdc++.h>
using namespace std;

int N, K, A[109];
int dp[10009];

int main(){
    cin >> N >> K;
    for (int i=1; i<=K; i++) cin >> A[i];
    
    dp[0] = 0;
    dp[1] = 1;
    for (int i=2; i<=N; i++){
        dp[i] = -1;
        for (int j=1; j<=K; j++){
             if (i < A[j]) continue;
             dp[i]= max(dp[i], i-dp[i-A[j]]); 
        }
    }
    cout << dp[N] << endl;
    return 0;
}