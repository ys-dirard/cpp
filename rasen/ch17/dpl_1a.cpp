#include <bits/stdc++.h>
using namespace std;

int n, m;
int c[29];
int dp[29][50009];

int main(){
    cin >> n >> m;
    for(int i=1;i<=m;i++){
        cin >> c[i];
    }
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            dp[i][j] = 1<<30;
        }
    }

    dp[0][0] = 0;
    for(int i=1;i<=m;i++){
        for(int j=0;j<=n;j++){
            dp[i][j] = min(dp[i][j], dp[i-1][j]);
            if(j-c[i]>=0){
                dp[i][j] = min(dp[i][j], dp[i-1][j-c[i]]+1);
            }
            if(j-c[i]>=0 && dp[i][j-c[i]]<(1<<30)){
                dp[i][j] = min(dp[i][j], dp[i][j-c[i]]+1);
            }
        }
    }

    cout << dp[m][n] << endl;
    return 0;
}