#include <bits/stdc++.h>
using namespace std;

int N, Q, A[300009], B[300009];

int main(){
    cin >> N;
    for(int i=1;i<=N;i++) cin >> A[i];
    cin >> Q;
    for(int i=1;i<=Q;i++) cin >> B[i];

    sort(A+1, A+N+1);
    for(int i=1;i<=Q;i++){
        int pos = lower_bound(A+1, A+N+1, B[i]) - A;
        if(pos==1) cout << A[1] - B[i] << '\n';
        else if(pos==N+1) cout << B[i] - A[N] << '\n';
        else cout << min(A[pos]-B[i], B[i]-A[pos-1]) << '\n'; 
    }
    return 0;
}