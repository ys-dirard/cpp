#include <bits/stdc++.h>
using namespace std;

int main(){
    long long N, M, B;
    cin >> N >> M >> B;
    long long A[200009], C[200009];
    for (int i=1; i<=N; i++) cin >> A[i];
    for (int i=1; i<=M; i++) cin >> C[i];

    long long ans = 0;
    for (int i=1; i<=N; i++) ans += M * A[i];
    for (int i=1; i<=M; i++) ans += N * C[i];
    ans += B * M * N;

    cout << ans << endl;
    return 0;
}