#include <bits/stdc++.h>

#define rep(i,s,n) for(int i = s; i < n; i++)
#define ll long long
#define P pair<ll, ll>

using namespace std;

ll W;
ll mod = 1000000007;

int main(){
    // ans = 12*7^(W-1)
    cin >> W;
    ll doubling[69];
    doubling[1] = 7;
    rep(i, 2, 61){
        doubling[i] = doubling[i-1] * doubling[i-1] % mod;
    }
    ll ans = 12;
    rep(i, 1, 61){
        if((W-1) & (1LL << (i-1))){
            ans = ans * doubling[i] % mod;
        }
    }
    cout << ans << endl;
    return 0;
}