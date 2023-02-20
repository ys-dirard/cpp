#include <bits/stdc++.h>
using namespace std;

string S, T;
int dp[2009][2009];

int main(){
    cin >> S >> T;
    for (int i=0; i<=S.size(); i++){
        dp[i][0] = i;
    }
    for (int j=0; j<=T.size(); j++){
        dp[0][j] = j;
    }

    for (int i=1; i<=S.size(); i++){
        for (int j=1; j<=T.size(); j++){
            if (S[i-1] == T[j-1]){
                dp[i][j] = min({dp[i-1][j]+1, dp[i][j-1]+1, dp[i-1][j-1]});
            } else {
                dp[i][j] = min({dp[i-1][j]+1, dp[i][j-1]+1, dp[i-1][j-1]+1});
            }
        }
    }
    cout << dp[S.size()][T.size()] << endl;
    return 0;
}