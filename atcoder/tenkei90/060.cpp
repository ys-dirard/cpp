#include <bits/stdc++.h>
using namespace std;

const int INF = (1 << 30);
int N;
int A[300009];
int L[300009], nL[300009];
int R[300009], nR[300009];

int main(){
    cin >> N;
    for(int i=1;i<=N;i++){
        cin >> A[i];
    }
    for(int i=1;i<=N+1;i++){
        L[i] = R[i] = INF;
        L[i] = INF;
    }
    nL[0] = nR[0] = 0;

    // 左からのLIS
    for(int i=1;i<=N;i++){
        int pos = lower_bound(L+1, L+N+1, A[i]) - L;
        // cout << pos << endl;
        L[pos] = A[i];
        nL[i] = pos;
    }

    // for(int i=1;i<=N;i++){
    //     cout << L[i] << " ";
    // }
    // cout << endl;
    
    // for(int i=1;i<=N;i++){
    //     cout << nL[i] << " ";
    // }
    // cout << endl;

    // 右からのLIS
    reverse(A+1, A+N+1);
    for(int i=1;i<=N;i++){
        int pos = lower_bound(R+1, R+N+1, A[i]) - R;
        // cout << pos << endl;
        R[pos] = A[i];
        nR[i] = pos;
    }

    int ans = 0;
    for(int i=1;i<=N;i++){
        ans = max(ans, nL[i]+nR[N-i+1]-1);
    }
    cout << ans << endl;

    return 0;
}