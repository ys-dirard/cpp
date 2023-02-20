/* #region convenient */
#include <bits/stdc++.h>
#define rep(i,s,n) for(int i = s; i < n; i++)
#define ll long long
#define P pair<ll, ll>
using namespace std;
/* #endregion*/

int H, W;
vector<string> S, T;
string tmp;
map<ll, int> ms, mt;

int main(){
    /* #region cin cout settings */
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    /* #endregion */
    cin >> H >> W;
    rep(i, 0, H){
        cin >> tmp;
        S.push_back(tmp);
    }
    rep(i, 0, H){
        cin >> tmp;
        T.push_back(tmp);
    }

    for(int j=0;j<W;j++){
        ll t = 0LL;
        for(ll i=0;i<H;i++){
            if(S[i][j]=='#'){
                t += (1<<i);
            }
        }
        ms[t]++;
    }
    for(int j=0;j<W;j++){
        ll t = 0LL;
        for(ll i=0;i<H;i++){
            if(T[i][j]=='#'){
                t += (1<<i);
            }
        }
        mt[t]++;
    }

    bool flg = true;
    for(auto itr = ms.begin();itr!=ms.end();itr++){
        if(itr->second != mt[itr->first]) flg = false;
    }
    for(auto itr = mt.begin();itr!=mt.end();itr++){
        if(itr->second != ms[itr->first]) flg = false;
    }

    if(flg) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}