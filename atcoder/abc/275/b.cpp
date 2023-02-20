#include <bits/stdc++.h>

#define rep(i,s,n) for(int i = s; i < n; i++)
#define ll long long
#define P pair<ll, ll>

using namespace std;

ll A, B, C, D, E, F;
ll mod = 998244353;

int main(){
    cin >> A >> B >> C >> D >> E >> F;
    A = A % mod;
    B = B % mod;
    C = C % mod;
    D = D % mod;
    E = E % mod;
    F = F % mod;

    ll ans = ((A * B) % mod) * C % mod - ((D * E) % mod) * F % mod;
    if (ans < 0) ans += mod;
    cout << ans << endl;
    return 0;
}