#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll mod = 1e9 + 7LL;

ll N, Q;
ll x[59], y[59], z[59], w[59];
ll xb[59][60], yb[59][60], zb[59][60], wb[59][60]; // (i, bit)

void int2bit(ll n, ll *xb){
    for(ll j=0LL;j<60LL;j++){
        if(n & (1LL<<j)){
            xb[j] = 1LL;
        }else{
            xb[j] = 0LL;
        }
    }
}

int main(){
    cin >> N >> Q;
    for(ll i=0LL;i<Q;i++){
        cin >> x[i] >> y[i] >> z[i] >> w[i];
        x[i]--; y[i]--; z[i]--;
    }

    for(ll i=0;i<Q;i++){
        for(ll j=0LL;j<60;j++){
            if(w[i] & (1LL<<j)){
                wb[i][j] = 1LL;
            }
        }
    }

    ll ans = 1LL;
    // bit loop (ビットごとに条件を確認する)
    for(ll i=0;i<60;i++){
        // N loop (iビット目のN個の組み合わせをビット全探索)
        ll comb = 0LL;
        for(ll j=0LL;j<(1LL<<N);j++){
            ll tmp[60];
            // jの各ビットが立っているかを確認(O(N))
            int2bit(j, tmp);

            // 条件をcheck(O(Q))
            bool flg = true;
            for(ll k=0LL;k<Q;k++){
                if((tmp[x[k]] | tmp[y[k]] | tmp[z[k]]) != wb[k][i]) flg = false;
            }
            if(flg){
                comb++;
                comb %= mod;
            }
        }
        ans *= comb % mod;
        ans %= mod;
    }

    cout << ans << endl;
    return 0;
}