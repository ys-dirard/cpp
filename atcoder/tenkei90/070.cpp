#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll N, X[100009], Y[100009];

int main(){
    cin >> N;
    for(int i=1;i<=N;i++){
        cin >> X[i] >> Y[i];
    }
    sort(X+1, X+N+1);
    sort(Y+1, Y+N+1);

    ll pos = (N+1)/2;
    ll x = X[pos];
    ll y = Y[pos];

    ll ans = 0;
    for(int i=1;i<=N;i++){
        ans += abs(X[i] - x);
        ans += abs(Y[i] - y);
    }

    cout << ans << endl;
    return 0;
}