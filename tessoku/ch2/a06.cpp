#include <iostream>
using namespace std;
#define rep(i, n) for (int i=1; i<=n; i++)

int main () {
    long long N, Q, A[100001], S[100001];
    cin >> N >> Q;
    rep(i, N) {
        cin >> A[i];
        if (i == 1) S[i] = A[i];
        else S[i] = S[i - 1] + A[i];
    }

    rep(i, Q) {
        long long l, r;
        cin >> l >> r;
        cout << S[r] - S[l] + A[l] << endl;
    }
    return 0;
}