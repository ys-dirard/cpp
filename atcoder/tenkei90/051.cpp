#include <bits/stdc++.h>
using namespace std;
#define ll long long

// map使って愚直はTLE

ll N, K, P;
ll A[49];
map<pair<ll, ll>, ll> mp; // ((val, choose), cnt)
map<pair<ll, ll>, ll> mp2; // ((val, choose), cnt)

int main(){
    cin >> N >> K >> P;
    for(int i=1;i<=N;i++){
        cin >> A[i];
    }

    mp2[{0LL, 0LL}] = 1LL;
    for(int i=1;i<=N;i++){
        mp = mp2;
        for(auto itr=mp.begin();itr!=mp.end();itr++){
            // cout << itr->first.first << " " << itr->first.second << " " << itr->second << endl;
            ll p = itr->first.first;
            ll cnt = itr->first.second;
            if(p + A[i] <= P && cnt + 1LL <= K){
                mp2[{p + A[i], cnt + 1LL}] += mp[{p, cnt}];
            }
        }
    }

    ll ans = 0LL;
    for(auto itr=mp2.begin();itr!=mp2.end();itr++){
        if(itr->first.second == K){
            // cout << itr->first.first << " " << itr->first.second << " " << itr->second << endl;
            ans += itr->second;
        }
    }
    cout << ans << endl;
    return 0;
}