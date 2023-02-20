#include <bits/stdc++.h>

#define rep(i,s,n) for(int i = s; i < n; i++)
#define ll long long
#define P pair<ll, ll>

using namespace std;

ll N, C[100009];
ll Q, X[100009];
ll S[100009];

int main(){
    cin >> N;
    rep(i, 1, N+1) cin >> C[i];
    cin >> Q;
    rep(i, 1, Q+1) cin >> X[i];

    sort(C+1, C+N+1);
    S[0] = 0;
    rep(i, 1, N+1) S[i] = S[i-1]+C[i];

    for(int i=1;i<=Q;i++){
        int idx = lower_bound(S, S+N+1, X[i]+1) - S;
        idx--;
        cout << idx << endl;
    }
    return 0;
}