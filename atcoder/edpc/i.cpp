#include <bits/stdc++.h>
using namespace std;

int N;
double p[3000];
double dp[3000][3000]; // i番目までのコインで表がj回以上となる確率

int main(){
    cin >> N;
    for(int i=1;i<=N;i++){
        cin >> p[i];
    }

    dp[0][0] = 1;
    for(int i=1;i<=N;i++){
        for(int j=0;j<=N;j++){
            if(j>0) dp[i][j] = dp[i-1][j] + (dp[i-1][j-1] - dp[i-1][j])*p[i];
            else dp[i][j] = 1;
        }
    }

    int n = N/2+1;
    cout << fixed << setprecision(15) << dp[N][n] << endl;
    return 0;
}