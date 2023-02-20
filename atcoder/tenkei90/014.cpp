#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll N, A[100009], B[100009];

int main(){
    cin >> N;
    for(int i=1;i<=N;i++) cin >> A[i];
    for(int i=1;i<=N;i++) cin >> B[i];

    ll ans = 0;
    sort(A+1, A+N+1);
    sort(B+1, B+N+1);
    for(int i=1;i<=N;i++){
        ans += abs(A[i]-B[i]);
    }
    cout << ans << endl;
    return 0;
}