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

int H, W;
char a[1009][1009];
mint dp[1009][1009];

int main(){
    cin >> H >> W;
    for(int i=1;i<=H;i++){
        for(int j=1;j<=W;j++){
            cin >> a[i][j];
        }
    }

    dp[1][1] = 1;
    for(int i=1;i<=H;i++){
        for(int j=1;j<=W;j++){
            if(a[i][j]=='.'){
                if(i+1<=H){
                    
                    dp[i+1][j] += dp[i][j];
                }
                if(j+1<=W){
                    dp[i][j+1] += dp[i][j];
                }
            }
        }
    }
    cout << dp[H][W] << endl;
    return 0;
}