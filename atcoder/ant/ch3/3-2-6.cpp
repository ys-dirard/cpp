#include <bits/stdc++.h>
using namespace std;
#define ll long long

// 4 Values whose Sum is 0 (POJ No.2785)

// 要素数nの整数のリストA、B、C、Dがある
// 各リストから1つずつ取り出したときに
// 和が0になる組み合わせの個数を求める
// 
// input
// n=6
// A={-45, -41, -36, -36, -26, -32}
// B={22, -27, -53, 30, -38, -54}
// C={42, 56, -37, -75, -10, -6}
// D={-16, 30, 77, -46, 62, 45}
// output
// 5

ll N;
ll A[4009], B[4009], C[4009], D[4009];
ll CD[16000009];

int main(){
    cin >> N;
    for(int i=1;i<=N;i++) cin >> A[i];
    for(int i=1;i<=N;i++) cin >> B[i];
    for(int i=1;i<=N;i++) cin >> C[i];
    for(int i=1;i<=N;i++) cin >> D[i];

    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            CD[i*(N-1)+j] = C[i]+D[j];
        }
    }
    sort(CD+1, CD+N*N+1);
    
    ll ans = 0LL;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            ll cd = -(A[i]+B[j]);
            // CD[i]==cdとなるiの個数を求める
            ll n = upper_bound(CD+1, CD+N*N+1, cd) - lower_bound(CD+1, CD+N*N+1, cd);
            ans += n;
        }
    }

    cout << ans << endl;
    return 0;
}