/* #region convenient */
#include <bits/stdc++.h>
#define rep(i,s,n) for(int i = s; i < n; i++)
#define ll long long
#define P pair<ll, ll>
using namespace std;
/* #endregion*/

ll N, M, A[200009];
// ll ans = 0;
map<ll, ll> mp;
vector<ll> sums;
ll total = 0;
ll ans = (1LL << 60);

int main(){
    /* #region cin cout settings */
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    /* #endregion */
    cin >> N >> M;
    rep(i, 1, N+1){
        cin >> A[i];
        mp[A[i] % M]++;
        total += A[i];
    }

    auto begin = mp.begin(), end = mp.end();
    // ll tmp = 0;
    ll pre_num = -2;
    for (auto iter = begin; iter != end; iter++) {
        // cout << "itr: " << iter->first << endl;
        if((iter->first == pre_num + 1)){
            // sums.back() += iter->first * iter->second;
            // sums.push_back(tmp);
            // tmp = 0;
        }else{
            sums.push_back(0);
        }
        
        // ll tmp_num = iter->first;
        // tmp += iter->first * iter->second;
        sums.back() += iter->first * iter->second;
        pre_num = iter->first;
        // cout << "tmp: " << tmp << endl;
    }

    if(sums.size() == 1){
        cout << 0 << endl;
        return 0;
    }

    if(begin->first == 0 && (--end)->first == (M-1)){
        sums[0] += sums[sums.size()-1];
        sums.erase(sums.end()-1);

    }
    // sums[0] += sums[sums.size()-1];
    // sums.erase(sums.end()-1);

    // sort(sums.begin(), sums.end());
    // if(begin->first == 0 && (--end)->first == (M-1)){
    //     sums.erase(sums.end()-1);
    // }
    for(int i=0;i<sums.size();i++){
        ans = min(ans, total - sums[i]);
    }

    cout << ans << endl;
    // cout << sums.size() << endl;
    // for(int i=0;i<sums.size();i++){
    //     cout << sums[i] << endl;;
    // }
    return 0;
}