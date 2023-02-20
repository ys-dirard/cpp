#include <bits/stdc++.h>
using namespace std;

// 重複組み合わせ
// 
// n種類の個の品物があり、i番目の品物はai個ある。
// 異なる種類の品物通しは区別できますが、同じ種類の品物は区別できない。
// これらの品物の中からm個選ぶ組み合わせの総数を求め、Mで割った余りを答えなさい。
// 
// 制約：
// 1<=n<=1000
// 1<=m<=1000
// 1<=ai<=1000
// 2<=M<=10000

// dp[i][j]: i番目までの品物でj個選ぶ時の選び方の総数
// 
// 遷移は、
// dp[i][j] = Σ_{0<=k<=min(ai, j)} dp[i-1][j-k]
// 
// ここで、
// Σ_{0<=k<=min(ai, j)} dp[i-1][j-k]
//   = dp[i-1][j-0] + dp[i-1][j-1] + ... + dp[i-1][j-min(ai, j)] 
// 
// min(ai, j) = j  → = dp[i-1][j-0] + dp[i-1][j-1] + ... + dp[i-1][j-j]
//                   = dp[i-1][j] + dp[i-1][j-1] + ... + dp[i-1][0]
//                   = Σ_{0<=k<=j-1} (dp[i-1][j-1-k]) + dp[i-1][j]
// 
// min(ai, j) = ai → = dp[i-1][j-0] + dp[i-1][j-1] + ... + dp[i-1][j-ai]
//                   = dp[i-1][j] + dp[i-1][j-1] + ... + dp[i-1][j-ai]
//                   = dp[i-1][j] + dp[i-1][j-1] + ... + dp[i-1][j-ai] + dp[i-1][j-ai-1] - dp[i-1][j-ai-1]
//                   = Σ_{0<=k<=ai} (dp[i-1][j-1-k]) + dp[i-1][j] - dp[i-1][j-1-ai]
//  
//   = Σ_{0<=k<=min(ai, j-1)} (dp[i-1][j-1-k]) + dp[i-1][j] - dp[i-1][j-1-ai] (第一行は定義から、最終項はai>jなら0)
// なので、
// dp[i][j] = dp[i][j-1] + dp[i-1][j] - dp[i-1][j-1-ai]

int n, m, M;
vector<int> a(1009);
int dp[1009][1009];

int main(){
    // input
    n = 3;
    m = 3;
    a = {-1, 1, 2, 3}; // -1はダミー
    M = 10000;
    // 6 (0+0+3, 0+1+2, 0+2+1, 1+0+2, 1+1+1, 1+2+0の6通り)

    for(int i=0;i<=n;i++){
        dp[i][0] = 1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(j-1-a[i]>=0) dp[i][j] = (dp[i][j-1] + dp[i-1][j] - dp[i-1][j-1-a[i]] + M) % M;
            else dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % M;
        }
    }

    cout << dp[n][m] << endl;
    return 0;
}