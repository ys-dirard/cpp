#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 1000000007;

ll N;
string S, target = "atcoder";
ll dp[100009][10]; // dp[i][j]: Sのi文字目までのatcoderのj文字目までの通り数

int main(){
    cin >> N >> S;
    for(int i=0;i<=N;i++){
        for(int j=0;j<=7;j++){
            dp[i][j] = 0;
        }
    }

    dp[0][0] = 1;
    for(int i=1;i<=N;i++){
        for(int j=0;j<=7;j++){
            // not adopt S[i-1]
            dp[i][j] += dp[i-1][j];
            // adopt S[i-1]
            if(j > 0 && S[i-1]==target[j-1]){
                dp[i][j] += dp[i-1][j-1];
            }
            dp[i][j] %= mod;
        }
    }
    // for(int i=0;i<=N;i++){
    //     for(int j=0;j<=7;j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << dp[N][7] << endl;
    return 0;
}