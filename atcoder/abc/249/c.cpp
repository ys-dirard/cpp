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

// {0, 1, ..., n-1}
// 0を下位ビット(1ビット目)とする
template<class Tm>
class BitSet{
public:
    int siz;
    BitSet(int siz=0): siz(siz){}
    // sizeの準備
    void set_size(int sz){
        siz = sz;
    }
    // 空集合
    Tm empty(){
        return (Tm)0;
    }
    // n個全てからなる集合
    Tm all(){
        return (((Tm)(1)<<siz) - 1);
    }
    // Sにi(番目)が含まれるか
    bool include(Tm S, int i){
        return (S>>i) & (Tm)(1);
    }
    // 集合Sに要素iを加える S∨{i}
    Tm add_set(Tm S, int i){
        return S | ((Tm)(1)<<i);
    }
    // 集合Sから要素iを取り除く S\{i}
    Tm remove_set(Tm S, int i){
        return S & ~((Tm)(1)<<i);
    }
    // 集合SとTの和集合
    Tm or_set(Tm S, Tm T){
        return S | T;
    }
    // 集合SとTの積集合
    Tm and_set(Tm S, Tm T){
        return S & T;
    }
    // 文字列からint生成("01011"->11)
    Tm str2int(string s){
        Tm S = (Tm)0;
        for(int i=0;i<(int)s.size();i++){
            // if(i>=(int)s.size()) break;
            S += (s[s.size()-i-1]-'0')<<i;
        }
        return S;
    }
};

ll N, K;
string S[20];

int main(){
    /* #region cin cout settings */
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    /* #endregion */
    cin >> N >> K;
    rep(i, 0, N) cin >> S[i];
    
    using T = int;
    BitSet<T> bs(N);
    
    // N個からK個選ぶ部分集合についての探索
    // int K = 3;
    T comb = (1LL<<K) - 1; // 下位Kビットの要素{0, 1, ..., K-1}を選択したものからスタート
    int ans = 0;
    // bit全探索
    for(T i=0;i<=bs.all();i++){
        // 各要素についての処理
        vector<int> cnt(100, 0);
        // cout << i << endl;
        for(int j=0;j<N;j++){
            if(i&(1<<j)){
                for(int k=0;k<S[j].size();k++){
                    cnt[S[j][k]-'a']++;
                }
            }
        }

        int tmp = 0;
        for(int j=0;j<26;j++){
            if(cnt[j]==K) tmp++;
        }
        chmax(ans, tmp);
    }
    
    cout << ans << endl;
    return 0;
}