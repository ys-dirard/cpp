#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int N, L;
vector<int> dp(100009, 0); // comb to n step.

int main(){
    cin >> N >> L;
    dp[0] = 1;
    for(int i=0;i<N;i++){
        dp[i+1] += dp[i];
        dp[i+1] %= mod;
        if(i+L<=N){
            dp[i+L] += dp[i];
            dp[i+L] %= mod;
        }
    }
    // for(int i=0;i<=N;i++){
    //     cout << dp[i] << " ";
    // }
    // cout << endl;
    cout << dp[N] << endl;
    return 0;
}