#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll N;
ll a[3009];
ll dp[3009][3009]; // 区間[i, j)の時の最終的な差分の最大値

int main(){
    cin >> N;
    for(int i=1;i<=N;i++){
        cin >> a[i];
    }

    for(int i=1;i<=N;i++){
        dp[i][i+1] = a[i];
    }

    for(int LEN=2;LEN<=N;LEN++){
        for(int i=1;i<=N;i++){
            int j = i+LEN;
            if(j>N+1) continue;

            dp[i][j] = max(a[i]-dp[i+1][j], a[j-1]-dp[i][j-1]);
        }
    }
    cout << dp[1][N+1] << endl;
    return 0;
}