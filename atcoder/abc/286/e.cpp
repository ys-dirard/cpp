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

ll N, Q;
ll A[309], U[100009], V[100009];
char s[309][309];
vvl dist(309, vl(309, 1LL<<60)), pre(309, vl(309, 1LL<<60)), val(309, vl(309, 0));
int ans = 0;

/* get_path(prev, s, t)
    入力：warshall_floyd で得た prev, スタート s, ゴール t
    出力：s から t への最短路のパス
*/
vector<int> get_path(int s, int t) {
    vector<int> path;
    for (int cur = t; cur != s; cur = pre[s][cur]) {
        path.push_back(cur);
    }
    path.push_back(s);
    reverse(path.begin(), path.end());
    return path;
}

/* warshall_floyd(dist)
    入力：初期化した dist
    計算量：O(|V|^3)
    副作用：dis[i][j]にiからjへの最短路のコストを格納
*/
void warshall_floyd() {
    // int V = dist.size();
    for (int k = 1; k <= N; k++) { // 経由点
        for (int i = 1; i <= N; i++) { // 始点
            for (int j = 1; j <= N; j++) { // 終点
                if((dist[i][j] > dist[i][k] + dist[k][j])){
                    dist[i][j] = dist[i][k] + dist[k][j];
                    pre[i][j] = pre[k][j];
                    val[i][j] = val[i][k] + val[k][j];
                }else if((dist[i][j] == dist[i][k] + dist[k][j]) && (val[i][j] < val[i][k] + val[k][j])){
                    val[i][j] = val[i][k] + val[k][j];
                }                    
            }
        }
    }
}

int main(){
    /* #region cin std::cout settings */
    ios::sync_with_stdio(0);
    cin.tie(0);
    std::cout.tie(0);
    /* #endregion */
    cin >> N;
    for(int i=1;i<=N;i++){
        cin >> A[i];
    }
    
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin >> s[i][j];
            if(i==j){
                dist[i][j] = 0LL;
                val[i][j] = 0LL;
            }
            if(s[i][j]=='Y') dist[i][j] = 1, val[i][j] = A[j];
            pre[i][j] = i;
        }
    }

    warshall_floyd();
    
    cin >> Q;
    for(int i=1;i<=Q;i++){
        cin >> U[i] >> V[i];
        if(dist[U[i]][V[i]] < (1LL<<58)){
            vi path = get_path(U[i], V[i]);
            cout << dist[U[i]][V[i]] << " " << val[U[i]][V[i]] + A[U[i]] << endl;
            // for(int i=0;i<path.size();i++){
            //     cout << path[i] << " ";
            // }
            // cout << endl;
        }else{
            cout << "Impossible" << endl;
        }
    }
}