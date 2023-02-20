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
    if(flg) std::cout << "Yes" << endl;
    else std::cout << "No" << endl;
}

void yes() {
    std::cout << "Yes" << endl;
}

void no() {
    std::cout << "No" << endl;
}

void err() {
    std::cout << -1 << endl;
}
/* #endregion*/

int T;
int N[1009], M[1009];
int C[1009][2009];
int u[1009][2009], v[1009][2009];
bool vt[2009], va[2009];
vector<int> g[1009][2009];
int ans[2009];

void init(int N){
    for(int i=1;i<=N;i++){
        vt[i] = false;
        va[i] = false;
    }
}

void dfs(int i, int pos_t, int pos_a, int step){
    // cout << "i: " << i << ", t: " << pos_t << ", a: " << pos_a << ", step: " << step << endl; 
    if(pos_t==N[i] && pos_a==1){
        chmin(ans[i], step);
        return;
    }

    // vt[pos_t] = true;
    // va[pos_a] = true;

    for(int j=0;j<g[i][pos_t].size();j++){
        for(int k=0;k<g[i][pos_a].size();k++){
            int next_t = g[i][pos_t][j];
            int next_a = g[i][pos_a][k];
            if(vt[next_t] || va[next_a] || (C[i][next_t]==C[i][next_a])) continue;

            vt[next_t] = true;
            va[next_a] = true;

            dfs(i, next_t, next_a, step+1);

            vt[next_t] = false;
            va[next_a] = false;
        }
    }
}

int main(){
    /* #region cin std::cout settings */
    ios::sync_with_stdio(0);
    cin.tie(0);
    std::cout.tie(0);
    /* #endregion */
    cin >> T;
    for(int i=1;i<=T;i++){
        cin >> N[i] >> M[i];
        for(int j=1;j<=N[i];j++){
            cin >> C[i][j];
        }
        for(int j=1;j<=M[i];j++){
            cin >> u[i][j] >> v[i][j];
            g[i][u[i][j]].push_back(v[i][j]);
            g[i][v[i][j]].push_back(u[i][j]);
        }
        ans[i] = 1e9;
    }
    
    for(int i=1;i<=T;i++){
        init(N[i]);
        vt[1] = true;
        va[N[i]] = true;
        dfs(i, 1, N[i], 0);
    }

    for(int i=1;i<=T;i++){
        if(ans[i] == 1e9) ans[i] = -1;
        cout << ans[i] << endl;
    }
}