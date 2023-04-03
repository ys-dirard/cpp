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

int N, M;
int u[2009], v[2009];
vi g[2009];
vector<bool> visited;
queue<pii> q;

ll ans = 0;

void dfs(int s0, int s, int p){
    if(visited[s]) return;
    visited[s] = true;

    if(p != s0 && *find(g[s0].begin(), g[s0].end(), s)==0) ans++;
    for(int i=0;i<g[s].size();i++){
        int nex = g[s][i];
        if(visited[nex]) continue;
        dfs(s0, nex, s);
    }
}

int main(){
    /* #region cin std::cout settings */
    ios::sync_with_stdio(0);
    cin.tie(0);
    std::cout.tie(0);
    /* #endregion */
    cin >> N >> M;
    rep(i, 1, M+1){
        cin >> u[i] >> v[i];
        g[u[i]].push_back(v[i]);
    }

    for(int i=1;i<=N;i++){
        visited = vector<bool>(N+1, false);
        q.push({i, 0});
        visited[i] = true;

        while(!q.empty()){
            pii p = q.front();
            int s = p.first;
            int dist = p.second;
            // cout << s << " " << dist << endl;
            q.pop();
            if(dist > 1) ans++;

            for(int i=0;i<g[s].size();i++){
                int nex = g[s][i];
                if(visited[nex]) continue;
                q.push({nex, dist+1});
                visited[nex] = true;
            }
        }

        // dfs(i, i, -1);
    }
    cout << ans << endl;
    return 0;
}