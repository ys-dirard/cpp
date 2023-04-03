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

int N;
int X[200009], C[200009];
vi g[200009];
bool visited[200009], kakutei[200009];

int dfs(int s){
    // cout << s << endl;
    visited[s] = true;

    int res = -1;
    for(int i=0;i<g[s].size();i++){
        int nex = g[s][i];
        if(visited[nex] && !kakutei[nex]) return nex;
        if(!kakutei[nex]) chmax(res, dfs(nex));
    }
    return res;
}

void dfs2(int s){
    // cout << s << endl;
    kakutei[s] = true;
    visited[s] = true;

    int res = -1;
    for(int i=0;i<g[s].size();i++){
        int nex = g[s][i];
        if(visited[nex]) return;
        dfs(nex);
    }
    return;
}

int min_loop(int s, int s0){
    kakutei[s] = true;
    int m = C[s];
    for(int i=0;i<g[s].size();i++){
        int nex = g[s][i];
        int cost = C[nex];

        if(nex==s0){
            // cout << "cost: " << cost << endl;
            return min(m, cost);
        }

        chmin(m, min_loop(nex, s0));
    }
    // cout << "m: " << m << endl;
    return m;
}

int main(){
    /* #region cin cout settings */
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    /* #endregion */
    cin >> N;
    rep(i, 1, N+1){
        cin >> X[i];
        g[i].push_back(X[i]);
    }
    rep(i, 1, N+1){
        cin >> C[i];
    }

    ll ans = 0;
    for(int i=1;i<=N;i++){
        int rt;
        if(!kakutei[i]){
            memset(visited, 0, sizeof(visited));
            rt = dfs(i);
            // cout << i << " " << rt << endl;
            if(rt != -1){
                // cout << ans << endl;
                ans += min_loop(rt, rt);
            }
        }
        memset(visited, 0, sizeof(visited));
        dfs2(i);
    }

    cout << ans << endl;

    return 0;
}