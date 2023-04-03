#include <bits/stdc++.h>
using namespace std;

string S, T;
int dp[3009][3009];

int main(){
    cin >> S >> T;
    for(int i=1;i<=S.size();i++){
        for(int j=1;j<=T.size();j++){
            dp[i][j] = -(1<<30);
        }
    }

    for(int i=1;i<=S.size();i++){
        for(int j=1;j<=T.size();j++){
            if(S[i-1]==T[j-1]){
                dp[i][j] = max({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]+1});
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    string ans = "";
    int l = S.size(), r = T.size();
    int len = dp[l][r];
    while(len>0){
        if(S[l-1]==T[r-1]){
            ans = S[l-1] + ans;
            l--;
            r--;
            len--;
        }else if(dp[l][r]==dp[l-1][r]){
            l--;
        }else{
            r--;
        }
    }

    cout << ans << endl;

    // cout << dp[S.size()][T.size()] << endl;
    return 0;
}