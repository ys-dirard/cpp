/* #region convenient */
#include <bits/stdc++.h>
#define rep(i,s,n) for(int i = s; i < n; i++)
#define ll long long
#define P pair<ll, ll>
using namespace std;
/* #endregion*/

int N, K;
vector<int> A(209, 0);

int main(){
    /* #region cin cout settings */
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    /* #endregion */
    cin >> N >> K;
    rep(i, 1, N+1) cin >> A[i];
    
    rep(i, 1+K, N+1+K){
        cout << A[i] << " ";
    }
    cout << endl;
    return 0;
}