#include <bits/stdc++.h>

// #include <atcoder/modint>
// using mint = atcoder::modint998244353;
using namespace std;

const long long mod = 998244353;
const int keta = 30;
const int num_elements = 200009;

// a^b (mod m)
long long modpow(long long a, long long b, long long m){
    long long p = a, ans = 1;
    for(int i=0;i<keta;i++){
        if((b & (1 << i)) != 0){
            ans *= p;
            ans %= m;
        }
        p *= p;
        p %= m;
    }
    return ans;
}

// a / b (mod m) <- [b^(m-1) === 1 => b^(m-2) === 1/b (mod m)]
long long division(long long a, long long b, long long m){
    return (a * modpow(b, m - 2, m)) % m;
}

int main() {
    long long n, p;
    cin >> n >> p;
    vector<long long> dp(n + 1, 0LL);
    double pd = p / 100LL;
    long long critical = division(p, 100LL, mod), normal = division((100LL - p), 100LL, mod);
    // cout << critical << endl;
    // cout << normal << endl;
    for(int i = 1; i <= n; i++)
        dp[i] = ((dp[max(0, i - 2)] * critical % mod + dp[i - 1] * normal % mod) + 1LL)%mod;
        // dp[i] = (dp[max(0, i-2)] + 1)*critical + (dp[i-1] + 1)*normal
    cout << dp[n] << endl;
}
