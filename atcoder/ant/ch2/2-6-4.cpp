#include <iostream>
#include <vector>
using namespace std;

// 区間篩

// エラトステネスの区間篩
// [a, b)に含まれる素数を求める
// b未満の素数でない整数の最小の素因数はたかだか√bなので、
// √b以下の素数の表があればエラトステネスの篩を[a, b)に適用できる
// [2, b)から素数が得られる度に[a, b)からその倍数を除けばよい
// 実装は同時にやっている風に行う
struct Eratosthenes {
    // 素数の数
    long long nprime = 0LL;
    // テーブル
    vector<bool> isprime;
    // isprime_small[i] == true <--> a+iが素数
    vector<bool> isprime_small;

    // コンストラクタで篩を回す
    Eratosthenes(long long a, long long b) : isprime(b - a, true),
                          isprime_small(b, true) {
        
        // 篩
        for (long long p = 2LL; p * p < b; ++p) {
            // [2, b)内の素数に対して篩を行う
            if (isprime_small[p]){
                for(long long i = 2LL * p; i * i < b ; i += p){ // [2, b)の篩
                    isprime_small[i] = false;
                }
                for(long long i = max(2LL,  (a + p - 1LL) / p) * p; i < b ; i += p){ // [a, b)の篩
                    isprime[i - a] = false;
                }
            }
        }

        for(long long p = a; p < b; p++){
            nprime += isprime[p - a];
        }
    }
};

int main() {
    long long a, b;
    cin >> a >> b;
    // エラトステネスの篩
    Eratosthenes er(a, b);

    cout << er.nprime << endl;
}