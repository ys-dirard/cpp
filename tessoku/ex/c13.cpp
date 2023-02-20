#include <bits/stdc++.h>

#define rep(i,s,n) for(int i = s; i < n; i++)
#define ll long long
#define P pair<ll, ll>

using namespace std;

ll Power(ll a, ll b, ll m){
    ll p = a;
    ll ans = 1;
    for(int i=0;i<30;i++){
        ll wari = (1 << i);
        if((b / wari) % 2 == 1){
            ans = (ans * p) % m;
        }
        p = (p * p) % m;
    }
    return ans;
}

ll division(ll a, ll b, ll mod){
    return a * Power(b, mod - 2, mod) % mod;
}

int N;
ll p, A[100009];
map<ll, ll> cnt;
ll mod = 1000000007;
ll ans = 0;

int main(){
    cin >> N >> p;
    rep(i, 1, N+1) cin >> A[i];
    rep(i, 1, N+1) A[i] %= mod;

    for(int i=1;i<=N;i++){
        if(A[i]!=0){
            ll goal = division(p, A[i], mod);
            ans += cnt[goal];
        }else{
            if(p==0) ans += i-1;
        }
        cnt[A[i]]++;
        
    }

    cout << ans << endl;
    return 0;
}