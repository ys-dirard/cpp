#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long

const ll mod = 1000000007ULL;
ll power10[20];

ll get_keta(ll x){
    ll keta = 0ULL;
    while(x > 0ULL){
        keta++;
        x /= 10ULL;
    }
    return keta;
}

ll modpow(ll a, ll b, ll m){
    ll ans = 1ULL;
    ll p = a;
    for(int i=0ULL;i<60ULL;i++){
        if((b & (1ULL<<i)) != 0ULL){
            ans *= p;
            ans %= m;
        }
        p = (p * p) % m;
    }
    return ans;
}

ll count_num(ll L, ll R, ll m){
    ll ketaR = get_keta(R);
    ll ketaL = get_keta(L);

    ll ans = 0ULL;
    for(ll i=ketaL;i<=ketaR;i++){
        ll a1, an;
        ll num;
        a1 = max(power10[i-1], L);
        an = min(power10[i]-1ULL, R);
        if(a1>an) continue;
        // if(i==ketaL){
        //     a1 = L;
        // }
        // if(i==ketaR){
        //     an = R;
        // }
        // if(i<ketaR){ // (a1 + al)* n / 2
        //     a1 = power10[i-1];
        //     an = power10[i]-1;
        //     // ans += (i * (power10[i] - power10[i-1]) % m);;
        // }else{
        //     a1 = power10[i-1];
        //     an = R;
        //     // ans += (i * (R - power10[i-1] + 1) % m);
        //     // cout << ans << endl;
        // }
        num = (a1 + an) % m * ((an - a1 + 1ULL + m) % m) * modpow(2ULL, m-2ULL, m) % m;
        // cout << num << endl;
        ans += (i * (num % m) % m);
        // if(i==ketaL){
        //     a1 = L-1;
        //     ans -= (i * (L - power10[i-1]) % m);
        //     cout << ans << endl;
        // }
        ans %= m;
        // cout << "ans: " << ans << endl;
    }
    return ans;
}

ll L, R;

int main(){
    power10[0] = 1ULL;
    for(int i=1ULL;i<=19ULL;i++) power10[i] = power10[i-1] * 10ULL;

    cin >> L >> R;
    // cout << get_keta(L) << " " << get_keta(R) << endl;
    cout << count_num(L, R, mod) << endl;
    // cout << 7*modpow(3, 9, 11)%11 << endl;
    return 0;
}