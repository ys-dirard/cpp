#include <bits/stdc++.h>
using namespace std;

int N, X[20], Y[20];
double dp[1<<15][15];

int main(){
    cin >> N;
    for (int i=0; i<N; i++) cin >> X[i] >> Y[i];

    for (int i=0; i<(1<<N); i++){
        for (int j=0; j<N; j++){
            dp[i][j] = 1e9;
        }
    }
    dp[0][0] = 0;

    for (int i=0; i<(1<<N); i++){
        for (int j=0; j<N; j++){
            if (dp[i][j] >= 1e9) continue;

            for (int k=0; k<N; k++){
                if ((i / (1<<k)) % 2 == 1) continue;
                else {
                    double dist = sqrt(pow(X[j] - X[k], 2) + pow(Y[j] - Y[k], 2));
                    dp[i +(1<<k)][k] = min(dp[i + (1<<k)][k], dp[i][j]+dist);
                }
            }
        }
    }
    printf("%.12lf", dp[(1<<N) - 1][0]);
    return 0;
}