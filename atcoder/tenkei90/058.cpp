#include <bits/stdc++.h>
using namespace std;
#define ll long long

// 10^18 < 2^60
ll N, K;
ll dg[60][100009];
const ll mod = 100000;


ll keta_sum(ll x){
    ll ans = 0;
    while(x > 0){
        ans += x % 10;
        x /=10;
    }
    return ans;
}

int main(){
    cin >> N >> K;
    for(ll j=0;j<100000;j++){
        ll y = keta_sum(j);
        dg[0][j] = (j + y) % mod;
    }

    for(int i=1;i<60;i++){
        for(int j=0;j<100000;j++){
            dg[i][j] = dg[i-1][dg[i-1][j]];
        }
    }

    ll ans = N;
    for(ll i=0;i<60;i++){
        // cout << (K & (1LL<<i)) << endl;
        if((K & (1LL<<i))){
            ans = dg[i][ans];
        }
        // cout << ans << endl;
    }

    cout << ans << endl;

    // for(int i=0;i<10;i++){
    //     for(int j=0;j<=10;j++){
    //         cout << dg[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    return 0;
}