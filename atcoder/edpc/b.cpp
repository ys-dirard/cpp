#include <bits/stdc++.h>
using namespace std;

int N, K;
int h[100009];
int dp[100009];

int main(){
    cin >> N >> K;
    for(int i=1;i<=N;i++){
        cin >> h[i];
        dp[i] = 1e9;
    }
    // memset(dp, 1e9, sizeof(dp));

    dp[1] = 0;
    for(int i=1;i<N;i++){
        for(int j=1;j<=K;j++){
            if(i+j>N) continue;
            dp[i+j] = min(dp[i+j], dp[i]+abs(h[i]-h[i+j]));
        }
    }
    // for(int i=1;i<=N;i++){
    //     cout << dp[i] << " ";
    // }
    cout << endl;
    cout << dp[N] << endl;
    return 0;
}