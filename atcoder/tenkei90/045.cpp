#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct point{
    ll x, y;
};

ll N, K;
ll X[20], Y[20];
point p[20];
ll d[40009]; // d[bit]: 選択状態がbitのグループ内の距離の最大値
ll dp[40009][20]; // dp[i][j]: iをすでに選んだ点、jを現在のグループ数としたときのスコアの最小値
// dp[bit][cnt] = min_{b in bit} max(dp[b][cnt-1], d[bit-b]) # cnt-1個のグループに新たに1個のグループを追加したときどうなるか？

ll get_distance(point a, point b){
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

ll max_in_group(ll b){
    ll ans = 0;
    vector<ll> in_group;
    for(ll i=0;i<N;i++){
        if(b & (1<<i)) in_group.push_back(i+1);
    }
    for(ll i=0;i<in_group.size();i++){
        for(ll j=i+1;j<in_group.size();j++){
            ans = max(ans, get_distance(p[in_group[i]], p[in_group[j]]));
        }
    }
    return ans;
}

ll b_in_bit(ll b, ll bit){
    bool flg = true;
    for(ll i=0;i<N;i++){
        if((b & (1LL<<i)) > (bit & (1LL<<i))){
            flg = false;
            break;
        }
    }
    return flg;
}

ll bit_count(ll b){
    ll ans = 0;
    for(ll i=0;i<N;i++){
        if((b & (1LL<<i))){
            ans += 1;
        }
    }
    return ans;
}

int main(){
    cin >> N >> K;
    for(ll i=1;i<=N;i++){
        cin >> X[i] >> Y[i];
        p[i] = {X[i], Y[i]};
    }

    // dの計算
    for(ll i=0;i<(1<<N);i++){
        d[i] = max_in_group(i);
        // cout << i << " " << d[i] << endl;
    }
    
    // init
    for(ll i=0;i<(1<<N);i++){
        for(ll j=0;j<=K;j++){
            dp[i][j] = (1LL<<60);
        }
    }
    for(ll i=1;i<(1<<N);i++){
        dp[i][1] = d[i];
    }

    // dp
    // b in bit(b<=bit)はb = (b-1) & bitでループすると漏らさず網羅できる
    for(ll cnt=2;cnt<=K;cnt++){
        for(ll bit=1;bit<(1LL<<N);bit++){
            for(ll b=bit;b!=0;b=(b-1)&bit){
                dp[bit][cnt] = min(dp[bit][cnt], max(dp[bit-b][cnt-1], d[b]));
            }
        }
    }

    cout << dp[(1LL<<N)-1][K] << endl;
    // for(ll j=1;j<=K;j++){
    //     for(ll i=1;i<(1<<N);i++){
    //         cout << i << " " << j << " " << dp[i][j] << endl;
    //     }
    // }
    return 0;
}