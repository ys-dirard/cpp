#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll N, Q;
ll A[100009], L[100009], R[100009], V[100009];
ll S[100009], sb[100009];

int main(){
    cin >> N >> Q;
    for(int i=0;i<=N+1;i++){
        S[i] = sb[i] = 0;
    }
    for(int i=1;i<=N;i++) cin >> A[i];

    ll pre_err = 0;
    for(int i=1;i<=N-1;i++){
        pre_err += abs(A[i]-A[i+1]);
    }
    // cout << pre_err << endl;

    for(int i=1;i<=Q;i++){
        cin >> L[i] >> R[i] >> V[i];
        if(L[i]!=1){
            pre_err -= abs(A[L[i]-1]-A[L[i]]-sb[L[i]]);
            // cout << "-L:" << abs(A[L[i]-1]-A[L[i]]-sb[L[i]]) << endl;
        }
        if(R[i]!=N){
            pre_err -= abs(A[R[i]]-A[R[i]+1]-sb[R[i]+1]);
            // cout << "-R:" << abs(A[R[i]]-A[R[i]+1]-sb[R[i]+1]) << endl;
        }
        sb[L[i]] += V[i];
        sb[R[i]+1] -= V[i];
        if(L[i]!=1){
            pre_err += abs(A[L[i]-1]-A[L[i]]-sb[L[i]]);
            // cout << "+L:" << abs(A[L[i]-1]-A[L[i]]-sb[L[i]]) << endl;
        }
        if(R[i]!=N){
            pre_err += abs(A[R[i]]-A[R[i]+1]-sb[R[i]+1]);
            // cout << "+R:" << abs(A[R[i]]-A[R[i]+1]-sb[R[i]+1]) << endl;
        }
        cout << pre_err << endl;
    }

    // for(int i=1;i<=N;i++){
    //     S[i] = S[i-1] + sb[i];
    // }

    // ll ans = 0;
    // for(int i=1;i<=N-1;i++){
    //     ans += abs(A[i] + S[i] - A[i+1] - S[i+1]);
    // }
    // cout << ans << endl;
    return 0;
}