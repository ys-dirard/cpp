/* #region convenient */
#include <bits/stdc++.h>
#define rep(i,s,n) for(int i = s; i < n; i++)
#define ll long long
#define P pair<ll, ll>
using namespace std;
/* #endregion*/

int N, X, p[109];

int main(){
    /* #region cin cout settings */
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    /* #endregion */
    cin >> N >> X;
    rep(i, 1, N+1) cin >> p[i];
    
    int pos;
    rep(i, 1, N+1){
        if(p[i]==X){
            pos = i;
            break;
        }
    }
    cout << pos << endl;
    return 0;
}