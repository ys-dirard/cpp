#include <bits/stdc++.h>

#define rep(i,s,n) for(int i = s; i < n; i++)
#define ll long long
#define P pair<ll, ll>

using namespace std;

int N, M, K, A[59], B[59];
int dp[19][300];

int score(int l, int r){
    int cnt = 0;
    for(int i=1;i<=M;i++){
        if(l <= A[i] && B[i] <= r) cnt++;
    }
    return cnt;
}


int main(){
    cin >> N >> M >> K;
    for(int i=1;i<=M;i++) cin >> A[i] >> B[i];

    for(int i=0;i<=K;i++){
        for(int j=0;j<=N;j++) dp[i][j] = -10000000;
    }
    
    dp[0][0] = 0;
    for(int i=1;i<=K;i++){
        for(int j=1;j<=N;j++){
            for(int k=0;k<=j-1;k++){
                dp[i][j] = max(dp[i-1][k]+score(k+1, j), dp[i][j]);
            }
        }
    }

    cout << dp[K][N] << endl;
    return 0;
}