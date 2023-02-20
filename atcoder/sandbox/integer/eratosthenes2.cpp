#include <iostream>
#include <vector>
using namespace std;

// 高速素因数分解、高速約数列挙つきversion
// minfactor[q] = p: qはpで割り切れる最小の数(>=2)
// n / manifactor[n] を繰り返すと素因数分解、約数列挙ができる

// エラトステネスの篩 (O(N log log N))
struct Eratosthenes {
    // 素数の数
    long long nprime = 0LL;
    // テーブル
    vector<bool> isprime;

    // 整数 i を割り切る最小の素数
    vector<long long> minfactor;

    // コンストラクタで篩を回す
    Eratosthenes(long long N) : isprime(N+1, true),
                          minfactor(N+1, -1) {
        // 1 は予めふるい落としておく
        isprime[1] = false;
        minfactor[1] = 1;

        // 篩
        for (long long p = 2; p <= N; ++p) {
            // すでに合成数であるものはスキップする
            if (!isprime[p]) continue;
            nprime++;

            // p についての情報更新
            minfactor[p] = p;

            // p 以外の p の倍数から素数ラベルを剥奪
            for (long long q = p * 2; q <= N; q += p) {
                // q は合成数なのでふるい落とす
                isprime[q] = false;

                // q は p で割り切れる旨を更新
                if (minfactor[q] == -1) minfactor[q] = p;
            }
        }
    }

    // 高速素因数分解 (O log N)
    // pair (素因子, 指数) の vector を返す
    vector<pair<long long,long long>> factorize(long long n) {
        vector<pair<long long,long long>> res;
        while (n > 1) {
            long long p = minfactor[n];
            long long exp = 0;

            // n で割り切れる限り割る
            while (minfactor[n] == p) {
                n /= p;
                ++exp;
            }
            res.emplace_back(p, exp);
        }
        return res;
    }

    // 高速約数列挙 (O(σ(n)), σ(n): num of divisors of n)
    vector<long long> divisors(long long n) {
        vector<long long> res({1});

        // n を素因数分解 (メンバ関数使用)
        auto pf = factorize(n);

        // 約数列挙
        for (auto p : pf) {
            long long s = (long long)res.size();
            for (long long i = 0; i < s; ++i) {
                long long v = 1;
                for (long long j = 0; j < p.second; ++j) {
                    v *= p.first;
                    res.push_back(res[i] * v);
                }
            }
        }
        return res;
    }
};

int main() {
    // エラトステネスの篩
    Eratosthenes er(50);

    // 結果表示
    for (int n = 2; n <= 50; ++n) {
        auto pf = er.factorize(n);
        cout << n << ": ";
        for (int i = 0; i < pf.size(); ++i) {
            if (i > 0) cout << " * ";
            cout << pf[i].first << "^" << pf[i].second;
        }
        cout << endl;
    }
}