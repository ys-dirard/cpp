#include <bits/stdc++.h>
using namespace std;

int N, A[69], B[69];

int main(){
    cin >> N;
    for(int i=1;i<=N;i++) cin >> A[i];
    for(int i=1;i<=N;i++) cin >> B[i];

    sort(A+1, A+N+1);
    sort(B+1, B+N+1, greater<int>());
    int ans = 0;
    for(int i=1;i<=N;i++) ans += A[i]*B[i];

    cout << ans << endl; 
    return 0;
}