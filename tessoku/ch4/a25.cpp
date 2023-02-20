#include <bits/stdc++.h>
using namespace std;

int H, W;
char c[39][39];
long long dp[39][39];

int main(){
    cin >> H >> W;
    for (int i=1; i<=H; i++){
        for (int j=1; j<=W; j++){
            cin >> c[i][j];
        }
    }
    for (int i=0; i<=H; i++){
        for (int j=0; j<=W; j++){
            dp[i][j] = 0;
        }
    }

    for (int i=1; i<=H; i++){
        for (int j=1; j<=W; j++){
            if (i ==1 && j == 1) dp[i][j] = 1;
            else if (c[i][j] == '.') {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
    }
    cout << dp[H][W] << endl;
    return 0;
}