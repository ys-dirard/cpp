#include <bits/stdc++.h>
using namespace std;

long long N, A[100009], B[100009];

int main(){
    cin >> N;
    for (int i=1;i<=N;i++){
        cin >> A[i] >> B[i];
    }
    long long pp=0, pn=0, np=0, nn=0;
    long long ans = 0;
    for (int i=1;i<=N;i++){
        if (A[i] + B[i] > 0) pp += A[i] + B[i];
        if (A[i] - B[i] > 0) pn += A[i] - B[i];
        if (-A[i] + B[i] > 0) np += -A[i] + B[i];
        if (-A[i] - B[i] > 0) nn += -A[i] - B[i];
    }
    
    ans = max({pp, pn, np, nn});
    cout << ans << endl;
    return 0;
}