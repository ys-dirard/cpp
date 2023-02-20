#include <bits/stdc++.h>
using namespace std;

int N, M, A[109][19], iA[109];
int dp[109][1030];

int main(){
    cin >> N >> M;
    for (int i=1; i<=M; i++){
        for (int j=0; j<N; j++){
            cin >> A[i][j];
            iA[i] += A[i][j] * (1 << j);
        }
    }

    for (int i=0; i<=M; i++){
        for (int j=0; j<1030; j++){
            dp[i][j] = 1 << 15;
        }
    }
    dp[0][0] = 0;

    for (int i=1; i<=M; i++){
        for (int j=0; j<(1<<N); j++){
            dp[i][j] = min(dp[i][j], dp[i-1][j]);

            int u = (j | iA[i]);
            dp[i][u] = min(dp[i][u], dp[i-1][j]+1);
        }
    }

    if (dp[M][(1<<N)-1] == 1 << 15) cout << -1 << endl;
    else cout << dp[M][(1<<N)-1] << endl;

    return 0;
}