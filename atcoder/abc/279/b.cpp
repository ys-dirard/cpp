/* #region convenient */
#include <bits/stdc++.h>
#define rep(i,s,n) for(int i = s; i < n; i++)
#define ll long long
#define P pair<ll, ll>
using namespace std;
/* #endregion*/

string S, T;

int main(){
    /* #region cin cout settings */
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    /* #endregion */
    cin >> S >> T;
    bool flg = false;
    for(int i=0;i<S.size();i++){
        bool tmp = true;
        for(int j=0;j<T.size();j++){
            if(S[i+j]!=T[j]){
                tmp = false;
                break;
            }
        }
        flg = flg | tmp;
    }

    if(flg) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}