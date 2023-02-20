#include <bits/stdc++.h>

#define rep(i,s,n) for(int (i) = (s); (i) < (n); (i)++)
#define ll long long
#define P pair<ll, ll>

using namespace std;

ll N, A[500009];
ll dp1[500009], dp2[500009];


int main(){
    cin >> N;
    rep(i, 1, N+1) cin >> A[i];
    
    dp1[0] = 0;
    dp2[0] = 0;
    rep(i, 1, N+1){
        dp1[i] = dp2[i-1] + A[i];
        dp2[i] = max(dp1[i-1], dp2[i-1]); 
    }
    cout << max(dp1[N], dp2[N]) << endl;
    return 0;
}