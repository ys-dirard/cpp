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

int N, M, K;
int u[2009], v[2009], p[2009], d[2009];
vi g[2009];
int dist[2009][2009];
vi color(2009, 1); // 0:白, 1:黒


int main(){
    /* #region cin cout settings */
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    /* #endregion */
    cin >> N >> M;
    rep(i, 1, M+1){
        cin >> u[i] >> v[i];
        g[u[i]].push_back(v[i]);
        g[v[i]].push_back(u[i]);
    }
    cin >> K;
    rep(i, 1, K+1){
        cin >> p[i] >> d[i];
    }

    rep(i, 1, N+1) rep(j, 1, N+1) dist[i][j] = -1;

    rep(i, 1, N+1){
        queue<int> q;
        q.push(i);
        dist[i][i] = 0;
        while(!q.empty()){
            int pos = q.front();
            q.pop();
            rep(j, 0, g[pos].size()){
                // cout << i << " " << j << endl;
                int nex = g[pos][j];
                if(dist[i][nex]==-1){
                    // cout << i << " " << nex << endl;
                    dist[i][nex] = dist[i][pos] + 1;
                    q.push(nex);
                }
            }
        }
    }
    
    // rep(i, 1, N+1){
    //     rep(j, 1, N+1){
    //         cout << dist[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    int black_cnt = N;
    rep(i, 1, K+1){
        int pos = p[i];
        int dst = d[i];
        rep(j, 1, N+1){
            if(color[j]==1 && dist[pos][j]<dst){
                color[j] = 0;
                black_cnt--;
            }
        }
    }
    bool flg = true;
    rep(i, 1, K+1){
        int pos = p[i];
        bool tmp = false;
        rep(j, 1, N+1){
            tmp |= (color[j]==1 && dist[pos][j]==d[i]);
        }
        flg &= tmp;
    }
    if(flg && black_cnt>0){
        cout << "Yes" << endl;
        for(int i=1;i<=N;i++){
            cout << color[i];
        }
        cout << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}