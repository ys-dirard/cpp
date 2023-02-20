#include <bits/stdc++.h>
using namespace std;
#define ll long long

// map使って愚直はTLE

ll N, K, P;
ll A[49];
vector<ll> L, R;
vector<ll> vl[49];
vector<ll> vr[49];

ll int2choose(ll n){
    ll ans = 0;
    while(n>0){
        if(n & 1) ans++;
        n = n >> 1;
    }
    return ans;
}

ll int2price(ll n, vector<ll> &p){
    ll ans = 0;
    ll i = 0;
    while(n > 0){
        if(n & 1) ans += p[i];
        i++;
        n = n >> 1;
    }
    return ans;
}

int main(){
    cin >> N >> K >> P;
    ll m = N/2;
    for(int i=1;i<=N;i++){
        cin >> A[i];
        if(i<=m) L.push_back(A[i]);
        else R.push_back(A[i]);
    }

    // 左半分全列挙
    // cout << "left" << endl;
    for(ll i=0;i<(1<<L.size());i++){
        ll c = int2choose(i);
        ll p = int2price(i, L);
        if(c <= K && p <= P) vl[c].push_back(p);
        // cout << c << " " << p << endl;
    }

    // 右半分全列挙
    // cout << "right" << endl;
    for(ll i=0;i<(1<<R.size());i++){
        ll c = int2choose(i);
        ll p = int2price(i, R);
        if(c <= K && p <= P) vr[c].push_back(p);
        // cout << c << " " << p << endl;

    }

    for(int i=0;i<=K;i++){
        sort(vr[i].begin(), vr[i].end());
    }
    
    // LとRを組み合わせる
    // cout << "combination" << endl;
    ll ans = 0;
    for(int i=0;i<=K;i++){
        for(ll j=0;j<vl[i].size();j++){
            ll c = i;
            ll p = vl[c][j];

            ll cnt = upper_bound(vr[K-c].begin(), vr[K-c].end(), P-p) - vr[K-c].begin();
            // cout << c << " " << p << " " << cnt << endl;
            ans += cnt;
        }
    }

    cout << ans << endl;

    return 0;
}