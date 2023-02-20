#include <bits/stdc++.h>
using namespace std;
#define ll long long

// A ^ N を M で割ったあまり
template<class T> T pow_mod(T A, T N, T M) {
    T res = 1 % M;
    A %= M;
    while (N) {
        if (N & 1) res = (res * A) % M;
        A = (A * A) % M;
        N >>= 1;
    }
    return res;
}

// ミラー-ラビン素数判定法(乱択アルゴリズムの一種、確率的)
// Miller-Rabin 素数判定、これで2^64以下は確率的に素数判定可能
bool is_prime(long long N) {
    if (N <= 1) return false;
    if (N == 2) return true;
    if (N % 2 == 0) return false;
    vector<long long> A = {2, 325, 9375, 28178, 450775,
                           9780504, 1795265022};
    long long s = 0, d = N - 1;
    while (d % 2 == 0) {
        ++s;
        d >>= 1;
    }
    for (auto a : A) {
        if (a % N == 0) return true;
        long long t, x = pow_mod<__int128_t>(a, d, N);
        if (x != 1) {
            for (t = 0; t < s; ++t) {
                if (x == N - 1) break;
                x = (__int128_t)(x) * x % N;
            }
            if (t == s) return false;
        }
    }
    return true;
}

int main() {
    // 入力
    int N;
    cin >> N;
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];

    // 素数判定
    for (auto a : A) {
        if (is_prime(a)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}