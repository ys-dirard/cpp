#include <bits/stdc++.h>
using namespace std;

// 個数制限付き部分和問題
// 
// n種類の数aiがmi個ずつあります。
// これらの中からいくつか選び、その総和をちょうどKとすることができるか判定しなさい。
// 
// 制約：
// 1<=n<=100
// 1<=ai, mi<=100000
// 1<=K<=100000

int n, K;
vector<int> a(100009, 0), m(100009, 0);
int dp[109][100009];
// dp[i][j]: i番目までのaでKを作った時の使っていいaの残りの回数

int main(){
    // input (a, mの先頭の-1はダミー)
    n = 3;
    a = {-1, 3, 5, 8};
    m = {-1, 3, 2, 2};
    K = 17;
    // Yes (3*3+8)

    for(int i=0;i<=n;i++){
        for(int j=0;j<=K;j++){
            dp[i][j] = -1;
        }
    }

    dp[0][0] = 0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=K;j++){
            if(dp[i-1][j]>=0) dp[i][j] = m[i];
            else if(j-a[i] >= 0 && dp[i][j-a[i]] > 0){
                dp[i][j] = dp[i][j-a[i]]-1;
            }else{
                dp[i][j] = -1;
            }
        }
    }
    if(dp[n][K] >= 0) cout << "Yes" << endl;
    else cout << "No" << endl;

    // for(int i=0;i<=n;i++){
    //     for(int j=0;j<=K;j++){
    //         cout <<setw(10) << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    return 0;
}