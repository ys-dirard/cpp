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
int N, M;
int C[2009];
int u[2009], v[2009];
int dist[2009][2009];
// vector<int> g[2009];

int main(){
    /* #region cin std::cout settings */
    ios::sync_with_stdio(0);
    cin.tie(0);
    std::cout.tie(0);
    /* #endregion */
    cin >> T;
    
    for(int _=1;_<=T;_++){
        vector<int> g[2009];
        cin >> N >> M;
        for(int i=1;i<=N;i++){
            cin >> C[i];
        }
        for(int i=1;i<=M;i++){
            cin >> u[i] >> v[i];
            g[u[i]].push_back(v[i]);
            g[v[i]].push_back(u[i]);
        }

        memset(dist, -1, sizeof(dist));
        dist[1][N] = 0;
        queue<pii> q;
        if(C[1] != C[N]) q.push({1, N});

        while(!q.empty()){
            int tpos = q.front().first;
            int apos = q.front().second;
            q.pop();
            // cout << "t: " << tpos << ", a: " << apos << endl;

            for(int i=0;i<g[tpos].size();i++){
                for(int j=0;j<g[apos].size();j++){
                    int tnext = g[tpos][i];
                    int anext = g[apos][j];
                    if(dist[tnext][anext] < 0 && (C[tnext] != C[anext])){
                        dist[tnext][anext] = dist[tpos][apos] + 1;
                        q.push({tnext, anext});
                    }
                }
            }
        }
        cout << dist[N][1] << endl;
    }
}