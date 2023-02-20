#include <bits/stdc++.h>
using namespace std;

string S, T;
int dp[2009][2009];

int main(){
    cin >> S >> T;
    for (int i=0; i<=S.size(); i++){
        for (int j=0; j<=T.size(); j++){
            dp[i][j] = (1LL << 15);
        }
    }

    for (int i=0; i<=S.size(); i++){
        for (int j=0; j<=T.size(); j++){
            if (i==0 || j==0) dp[i][j] = 0;
            else {
                if (S[i-1] == T[j-1]) dp[i][j] = max(dp[i-1][j-1] + 1, max(dp[i-1][j], dp[i][j-1]));
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    cout << dp[S.size()][T.size()] << endl;
    return 0;
}