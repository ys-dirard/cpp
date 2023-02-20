#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll mod = 1000000007LL;

ll modpow(ll a, ll b, ll m){
    ll res = 1LL;
    for(ll i=0;i<=60LL;i++){
        if(b & (1LL<<i)){
            res *= a;
            res %= m;
        }
        a = a * a;
        a %= m;
    }
    return res;
}

ll N, K;

int main(){
    cin >> N >> K;
    ll ans = 1LL;

    ans *= K;
    ans %= mod;
    if(N>1) ans *= K-1LL;
    // ans *= K-1LL;
    ans %= mod;
    if(N>2) ans *= modpow(K-2LL, N-2LL, mod);
    // modpow(K-2LL, N-2LL, mod);
    ans %= mod;
    cout << ans << endl;
    return 0;
}