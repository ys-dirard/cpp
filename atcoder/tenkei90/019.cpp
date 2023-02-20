#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF = 1e9+7;

int N;
ll A[409];
ll dp[409][409]; // [l, r)まで取り除く時の最小コスト

int main(){
    cin >> N;
    for(int i=1;i<=2*N;i++){
        cin >> A[i];
    }
    for(int i=0;i<=2*N;i++){
        for(int j=0;j<=2*N+1;j++){
            dp[i][j] = INF;
        }
    }

    // [l, l)
    for(int i=1;i<=2*N;i++){
        dp[i][i] = 0LL;
    }
    // [l, l+2)
    for(int i=1;i<=2*N-1;i++){
        dp[i][i+2] = abs(A[i] - A[i+1]);
    }

    // dp
    for(int LEN=4;LEN<=2*N;LEN+=2){
        for(int l=1;l+LEN<=2*N+1;l++){
            int r = l+LEN;
            
            for(int k=l;k<=r;k++){
                dp[l][r] = min(dp[l][r], dp[l][k] + dp[k][r]);
            }
            dp[l][r] = min(dp[l][r], dp[l+1][r-1]+abs(A[l]-A[r-1]));

        }
    }
    // for(int i=1;i<=2*N;i++){
    //     for(int j=1;j<=2*N+1;j++){
    //         cout << setw(4) << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << dp[1][2*N+1] << endl;
    return 0;
}