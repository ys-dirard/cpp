/* #region convenient */
#include <bits/stdc++.h>
#define rep(i,s,n) for(int i = s; i < n; i++)
#define ll long long
#define P pair<ll, ll>
using namespace std;
/* #endregion*/

int ans = 0;
string s;

int main(){
    /* #region cin cout settings */
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    /* #endregion */
    cin >> s;
    rep(i, 0, s.size()){
        if(s[i]=='v'){
            ans++;
        }else{
            ans += 2;
        }
    }

    cout << ans << endl;
    return 0;
}