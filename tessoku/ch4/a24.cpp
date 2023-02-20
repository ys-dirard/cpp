#include <bits/stdc++.h>
using namespace std;

int N, A[100009];
int dp[100009], L[100009];
// L[x]は長さxとなる部分列の最後の要素(dp[i]=x)として考えられるモノ(A[i])の中で最小のもの
// dp[i]=(L[pos]<A[i]をみたすもののなかで最大のpos + 1)
int LEN=0;

int main(){
    cin >> N;
    for (int i=1; i<=N; i++) cin >> A[i];

    L[0] = 0;
    dp[0] = 0;
    dp[1] = 1;

    for (int i=1; i<=N; i++){
        int pos = lower_bound(L+1, L+LEN+1, A[i]) - L;
        dp[i] = pos;

        L[dp[i]] = A[i];
        if (dp[i] > LEN) LEN += 1;
    }

    cout << LEN << endl;
    return 0;
}