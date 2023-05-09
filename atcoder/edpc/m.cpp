#include <bits/stdc++.h>
using namespace std;

/* #region modint */
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
/* #endregion */

int N, K;
int a[109];
mint dp[109][100009];
mint cum[100009];

int main(){
    cin >> N >> K;
    for(int i=1;i<=N;i++){
        cin >> a[i];
    }

    dp[0][0] = 1;
    for(int i=1;i<=N;i++){
        cum[0] = 0;
        for(int j=1;j<=K;j++){
            cum[j] = cum[j-1] + dp[i-1][j];
        }

        for(int j=0;j<=K;j++){
            int l = max(0, j-a[i]);
            dp[i][j] = cum[j] - cum[l] + dp[i-1][l];
        }
    }
    cout << dp[N][K] << endl;
    return 0;
}