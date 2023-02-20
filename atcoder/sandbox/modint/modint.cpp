#include <bits/stdc++.h>
using namespace std;

const long long mod = 1000000007; // 998244353
const int keta = 30;
const int num_elements = 200009;

long long fact[num_elements];
long long X, Y;

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

// combination
long long ncr(long long* fact, int n, int r, long long m){
    return division(fact[n], fact[r] * fact[n - r] % m, m);
}

int main(){
    // N!は先に求めておくとよい！！！(必要な要素数分確保しておく必要あり)
    fact[0] = 1;
    for(int i=1; i<=num_elements;i++){
        fact[i] = 1LL * i * fact[i-1] % mod;
    }

    cin >> X >> Y;
    cout << ncr(fact, X+Y, Y, mod) << endl;
    return 0;
}