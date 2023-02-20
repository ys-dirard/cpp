#include <bits/stdc++.h>

#include <atcoder/all>
using mint = atcoder::modint998244353;
using namespace std;

int main() {
    int n, p;
    cin >> n >> p;
    vector<mint> dp(n + 1, mint(0));
    mint critical = mint(p) / 100;
    mint normal = 1 - critical;
    for(int i = 1; i <= n; i++)
        dp[i] = (dp[max(0, i - 2)] * critical + dp[i - 1] * normal) + 1;
        // dp[i] = (dp[max(0, i-2)] + 1)*critical + (dp[i-1] + 1)*normal
    cout << dp.back().val() << endl;
}
