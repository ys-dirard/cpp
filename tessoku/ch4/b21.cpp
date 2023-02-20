#include <bits/stdc++.h>
using namespace std;

int N;
string S;
int dp[1009][1009];

int main(){
    cin >> N >> S;
    for (int i=0; i<N; i++) dp[i][i] = 1;
    for (int i=0; i<N-1; i++){
        if (S[i] == S[i+1]) dp[i][i+1] = 2;
        else dp[i][i+1] = 1;
    }

    for (int LEN=2; LEN<=N-1; LEN++){
        for (int l = 0; l<N-LEN; l++){
            int r = l + LEN;

            if (S[l] == S[r]){
                dp[l][r] = max({dp[l][r-1], dp[l+1][r], dp[l+1][r-1]+2});
            } else {
                dp[l][r] = max(dp[l][r-1], dp[l+1][r]);
            }
        }
    }
    cout << dp[0][N-1] << endl;
    return 0;
}