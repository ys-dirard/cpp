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
#define all(c) begin(c), end(c)
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

int N;
string S, T;
int cs[30], ct[30];
vector<int> pt[30];

int main(){
    /* #region cin cout settings */
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    /* #endregion */
    cin >> N >> S >> T;
    reverse(S.begin(), S.end());
    reverse(T.begin(), T.end());
    for(int i=0;i<N;i++){
        cs[S[i]-'a']++;
        ct[T[i]-'a']++;
        pt[T[i]-'a'].push_back(i);
    }
    for(int i=0;i<30;i++){
        pt[i].push_back(1<<30);
        sort(pt[i].begin(), pt[i].end());
    }
    for(int i=0;i<30;i++){
        if(cs[i] != ct[i]){
            cout << -1 << endl;
            return 0;
        }
    }

    int cnt_all = 0;
    int pos = 0;
    
    int cnt = 0;
    int npos = 0;
    while(pos<N){
        auto next = lower_bound(pt[S[pos]-'a'].begin(), pt[S[pos]-'a'].end(), npos);// - pt[S[i]-'a'].begin();
        if(*next == (1<<30)) break;
        // else if(npos < *next){
        // // else if(npos < pt[S[i]-'a'][next]){
        //     cnt++;
        //     pos = pos + 1;
        //     npos = *next;
        // }
        cnt++;
        pos = pos + 1;
        npos = *next+1;
    }
    chmax(cnt_all, cnt);
    
    cout << N - cnt_all << endl;
    return 0;
}