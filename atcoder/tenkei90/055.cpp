#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll N, P, Q;
ll A[109];
// map<ll, ll> mod;

int main(){
    cin >> N >> P >> Q;
    for(int i=1;i<=N;i++){
        cin >> A[i];
        A[i] %= P;
        // mod[A[i] % P]++;
    }

    int ans = 0;
    ll tmp = 0;
    for(int i=1;i<=N;i++){
        for(int j=i+1;j<=N;j++){
            for(int k=j+1;k<=N;k++){
                for(int l=k+1;l<=N;l++){
                    for(int m=l+1;m<=N;m++){
                        tmp = (A[i] % P);
                        tmp = tmp * A[j] % P;
                        tmp = tmp * A[k] % P;
                        tmp = tmp * A[l] % P;
                        tmp = tmp * A[m] % P;
                        if(tmp == Q) ans++;
                    }
                }
            }
        }
    }
    cout << ans;
    return 0;
}