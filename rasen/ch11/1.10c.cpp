#include <bits/stdc++.h>
using namespace std;

int q;
string X, Y;

int LCS(string X, string Y){
    int dp[1009][1009];
    for(int i=0;i<=X.size();i++){
        for(int j=0;j<=Y.size();j++){
            dp[i][j] = -1000000000;
        }
    }
    for(int i=0;i<=X.size();i++){
                dp[i][0] = 0;
    }
    for(int j=0;j<=Y.size();j++){
        dp[0][j] = 0;
    }

    for(int i=1;i<=X.size();i++){
        for(int j=1;j<=Y.size();j++){
            if(X[i-1]==Y[j-1]){
                dp[i][j] = max({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]+1});
            }else{
                dp[i][j] = max({dp[i-1][j], dp[i][j-1]});
            }
        }
    }
    return dp[X.size()][Y.size()];
}

int main(){
    cin >> q;
    for(int i=0;i<q;i++){
        cin >> X >> Y;
        cout << LCS(X, Y) << endl;
    }
    return 0;
}