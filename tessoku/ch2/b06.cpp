#include <iostream>
using namespace std;
#define rep(i, n) for (int i=1; i<=n; i++)

int main () {
    int N, Q, A[100001], T[100001], F[100001];
    cin >> N;
    T[0] = F[0] = 0;
    rep(i, N) {
        cin >> A[i];
        if (A[i] == 1) {
            T[i] = T[i-1] + 1;
            F[i] = F[i-1];
        } else {
            T[i] = T[i-1];
            F[i] = F[i-1] + 1;
        }
    }

    cin >> Q;

    rep(i, Q) {
        long long l, r;
        cin >> l >> r;
        string ans;
        long long n_t = T[r] - T[l - 1];
        long long n_f = F[r] - F[l - 1];
        if (n_t > n_f) ans = "win";
        else if (n_t < n_f) ans = "lose";
        else ans = "draw";

        cout << ans << endl;
    }
    return 0;
}