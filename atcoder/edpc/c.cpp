#include <bits/stdc++.h>
using namespace std;

int N;
int state[3][100009]; // 0:a, 1:b, 2:c
int dp[3][100009];

int main(){
    cin >> N;
    for(int i=1;i<=N;i++){
        cin >> state[0][i] >> state[1][i] >> state[2][i];
    }

    dp[0][0] = dp[1][0] = dp[2][0] = 0;
    for(int i=1;i<=N;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                if(j==k) continue;
                dp[j][i] = max(dp[j][i], dp[k][i-1]+state[j][i]);
            }
        }
    }
    int ans = 0;
    ans = max({ans, dp[0][N], dp[1][N], dp[2][N]});
    cout << ans << endl;
    return 0;
}