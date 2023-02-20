#include <bits/stdc++.h>
using namespace std;

// 個数制限なしナップザック問題
// 
// 重さと価値がそれぞれwi, viであるようなn種類の品物があります。
// これらの品物から、重さの総和がWを超えないように選んだ時の価値の最大値を求めなさい。
// ただし、同じ種類の品物をいくつでも選ぶことができます。
// 
// 制約：
// 1<=n<=100
// 1<=wi, vi<=100
// 1<=W<=10000

int n, W;
vector<int> w(109, 0), v(109, 0);
int dp[109][10009];

int main(){
    // input (w, vの先頭の-1はダミー)
    n = 3;
    w = {-1, 3, 4, 2};
    v = {-1, 4, 5, 3};
    W = 7;
    // 10 (w0*1+w2*2)

    for(int i=0;i<=n;i++){
        for(int j=0;j<=W;j++){
            dp[i][j] = -(1<<30);
        }
    }

    dp[0][0] = 0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=W;j++){
            if(j-w[i]<0){
                dp[i][j] = max(dp[i][j], dp[i-1][j]);
            }else{
                dp[i][j] = max({dp[i][j], dp[i][j-w[i]]+v[i]});
            }
        }
    }
    int ans = 0;
    for(int j=0;j<=W;j++){
        ans = max(ans, dp[n][j]);
    }
    cout << ans << endl;
    return 0;
}