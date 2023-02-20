#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll mod = 1e9 + 7;

ll N, A[109][7];
ll ans = 1LL;

int main(){
    cin >> N;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=6;j++){
            cin >> A[i][j];
        }
    }

    for(int i=1;i<=N;i++){
        ll S = 0;
        for(int j=1;j<=6;j++){
            S += A[i][j];
        }
        ans *= S;
        ans %= mod;
    }

    cout << ans << endl;
    return 0;
}