#include <bits/stdc++.h>
using namespace std;
#define ll long long

constexpr int mod = 1000000007;
class mint {
public:
    long long x;
    constexpr mint(long long x=0) : x((x%mod+mod)%mod) {}
    constexpr mint operator-() const { 
      return mint(-x);
    }
    constexpr mint& operator+=(const mint& a) {
        if ((x += a.x) >= mod) x -= mod;
        return *this;
    }
    constexpr mint& operator-=(const mint& a) {
        if ((x += mod-a.x) >= mod) x -= mod;
        return *this;
    }
    constexpr mint& operator*=(const mint& a) {
        (x *= a.x) %= mod;
        return *this;
    }
    constexpr mint operator+(const mint& a) const {
        mint res(*this);
        return res+=a;
    }
    constexpr mint operator-(const mint& a) const {
        mint res(*this);
        return res-=a;
    }
    constexpr mint operator*(const mint& a) const {
        mint res(*this);
        return res*=a;
    }
    constexpr mint pow(long long t) const {
        if (!t) return 1;
        mint a = pow(t>>1);
        a *= a;
        if (t&1) a *= *this;
        return a;
    }

    // for prime mod
    constexpr mint inv() const {
        return pow(mod-2);
    }
    constexpr mint& operator/=(const mint& a) {
        return (*this) *= a.inv();
    }
    constexpr mint operator/(const mint& a) const {
        mint res(*this);
        return res/=a;
    }
};
ostream& operator<<(ostream& os, const mint& m){
    os << m.x;
    return os;
}

// combination
mint ncr(mint* fact, int n, int r){
    return fact[n] / fact[r] / fact[n - r];
}

// N個の中からa個選ぶとすると、選んだあとに間隔を k-1 以上開けないといけない
// → {N - (k-1)(a-1)}C{a} 通りとなる (最後のa個目以外は空白とセットに考えると選べる球の個数はN - (k-1)(a-1))
// Σ_k (Σ_a (combination)) を計算する！
// aとkの選び方はkを固定すると、
// N-(a-1)(k-1)>=a を満たさなければいけないので、a<=(N+k-1)/k となりざっと 各kに対し N/k 個ある
// よって、aとkの選び方の総数は
// N+N/2+N/3+...+N/N = N(1+1.2+...+1/N) ⇒ N O(log N) = O(Nlog N) である
// 各a, kの組に対し、{N - (k-1)(a-1)}C{a}でO(1)で求まるので全体の計算量もO(N log N)となる

ll N;
mint ans[100009];
mint fact[100009];

int main(){
    cin >> N;
    fact[0] = 1LL;
    for(int i=1;i<=N;i++){
        fact[i] = fact[i-1]*i;
        ans[i] = 0;
    }
    
    for(int k=1;k<=N;k++){
        int a_max = (N+k-1) / k;
        for(int a=1;a<=a_max;a++){
            ans[k] += ncr(fact, N-(k-1)*(a-1), a);
        }
    }

    for(int i=1;i<=N;i++){
        cout << ans[i].x << endl;
    }
    return 0;
}