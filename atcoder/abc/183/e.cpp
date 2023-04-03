/* #region convenient */
#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
#define rep(i, s, n) for(int i = s; i < n; i++)
#define fore(i, a) for(auto &&i : a)
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vl vector<ll>
#define vb vector<bool>
#define vvi vector<vector<int>>
#define vvvi vector<vector<vector<int>>>
#define vvl vector<vector<ll>>
#define vvvl vector<vector<vector<ll>>>
#define mii map<int, int>
#define mll map<ll, ll>
#define mil map<int, ll>
#define mli map<ll, int>
#define fi first
#define se second
#define pb push_back
#define ppb pop_back
#define ppf pop_front
#define eb emplace_back
#define drop(s) cout << #s << endl, exit(0)
#define si(c) (int)(c).size()
#define lb(c, x) distance((c).begin(), lower_bound(all(c), (x)))
#define ub(c, x) distance((c).begin(), upper_bound(all(c), (x)))
// rng(l, r) = [l, r]
#define rng(v, l, r) v.begin() + (l), v.begin() + (r)
// #define all(c) begin(c), end(c)
#define rall(c) rbegin(c), rend(c)
#define vec(type, name, ...) vector<type> name(__VA_ARGS__)
#define vv(type, name, h, ...) vector<vector<type>> name(h, vector<type>(__VA_ARGS__))
#define vvv(type, name, h, w, ...) vector<vector<vector<type>>> name(h, vector<vector<type>>(w, vector<type>(__VA_ARGS__)))
#define vvvv(type, name, a, b, c, ...)                                                                                                                         \
    vector<vector<vector<vector<type>>>> name(a, vector<vector<vector<type>>>(b, vector<vector<type>>(c, vector<type>(__VA_ARGS__))))
constexpr pii dx4[4] = {pii{1, 0}, pii{0, 1}, pii{-1, 0}, pii{0, -1}};
constexpr pii dx8[8] = {{1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};

template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

void yesno(bool flg){
    if(flg) cout << "Yes" << endl;
    else cout << "No" << endl;
}

void yes() {
    cout << "Yes" << endl;
}

void no() {
    cout << "No" << endl;
}

void err() {
    cout << -1 << endl;
}
/* #endregion*/

/* #region modint */
constexpr int mod = 1000000007;
// constexpr int mod = 998244353;
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

ll H, W;
char S[2009][2009];
mint X[2009][2009], Y[2009][2009], Z[2009][2009]; // X: 縦方向の累積和, Y: 横方向の累積和, Z: 斜め方向の累積和
mint dp[2009][2009];

int main(){
    /* #region cin cout settings */
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    /* #endregion */
    cin >> H >> W;
    rep(i, 1, H+1){
        rep(j, 1, W+1){
            cin >> S[i][j];
        }
    }
    
    dp[1][1] = 1;
    rep(i, 1, H+1){
        rep(j, 1, W+1){
            if(i==1&&j==1) continue;
            if(S[i][j]=='#') continue;
            
            if(i>0) X[i][j] = X[i-1][j] + dp[i-1][j];
            if(j>0) Y[i][j] = Y[i][j-1] + dp[i][j-1];
            if(i>0&&j>0) Z[i][j] = Z[i-1][j-1] + dp[i-1][j-1];

            dp[i][j] = X[i][j] + Y[i][j] + Z[i][j];
        }
    }

    cout << dp[H][W] << endl;

    // cout << "X" << endl;
    // rep(i, 1, H+1){
    //     rep(j, 1, W+1){
    //         cout << X[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << "Y" << endl;
    // rep(i, 1, H+1){
    //     rep(j, 1, W+1){
    //         cout << Y[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << "Z" << endl;
    // rep(i, 1, H+1){
    //     rep(j, 1, W+1){
    //         cout << Z[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << "dp" << endl;
    // rep(i, 1, H+1){
    //     rep(j, 1, W+1){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    return 0;
}