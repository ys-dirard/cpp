/* #region convenient */
#include <bits/stdc++.h>
#define rep(i,s,n) for(int i = s; i < n; i++)
#define ll long long
#define P pair<ll, ll>
using namespace std;
/* #endregion*/

int N, Q, T[200009], A[200009], B[200009];
map<int, set<int>> m;
int ans = 1;

int main(){
    /* #region cin cout settings */
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    /* #endregion */
    cin >> N >> Q;
    rep(i, 1, Q+1){
        cin >> T[i] >> A[i] >> B[i];
    }

    rep(i, 1, Q+1){
        if(T[i]==1){
            m[A[i]].insert(B[i]);
        }else if(T[i]==2){
            m[A[i]].erase(B[i]);
        }else{
            bool flg = (m[A[i]].count(B[i])) && (m[B[i]].count(A[i]));
            if(flg) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
    
    return 0;
}