/* #region convenient */
#include <bits/stdc++.h>
#define rep(i,s,n) for(int i = s; i < n; i++)
#define ll long long
#define P pair<ll, ll>
using namespace std;
/* #endregion*/

ll N, M;
ll A[100009], B[100009];
vector<ll> g[100009];

int main(){
    cin >> N >> M;
    for(int i=1;i<=M;i++){
        cin >> A[i] >> B[i];
        g[A[i]].push_back(B[i]);
        g[B[i]].push_back(A[i]);
    }

    for(int i=1;i<=N;i++){
        sort(g[i].begin(), g[i].end());
        cout << g[i].size() << " ";
        for(int j=0;j<g[i].size();j++){
            cout << g[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}