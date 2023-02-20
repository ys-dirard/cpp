#include <bits/stdc++.h>
using namespace std;

// 部分和問題
// 
// 整数a1, a2, ..., anが与えられる。
// その中からいくつか選び、和をちょうどkにすることができるかを判定する。
// 
// 制約：
// 1<=L<=10^6
// -10^8<=xi<=10^8
// -10^8<=k<=10^8

// n=iまでの目標金額k'円として再帰関数を呼び出しdfsする
// dpでも解けるけど、、、。

int n, k;
vector<int> a(20, 0);

bool dfs(int i, int k){
    if(k == 0) return true;
    if(k < 0 || i >= n) return false;

    bool ans = false;
    ans |= dfs(i + 1, k);
    ans |= dfs(i + 1, k - a[i]);

    return ans;
}

int main(){
    // input1
    n = 4;
    a = {1, 2, 4, 7};
    k = 13;
    // Yes

    // input2
    n = 4;
    a = {1, 2, 4, 7};
    k = 15;
    // No
    
    bool ans = dfs(0, k);

    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;
}