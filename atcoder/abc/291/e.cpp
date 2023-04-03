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

ll N, M;
ll A[200009];
int X[200009], Y[200009];
vi g1[200009];
vi g2[200009];

vector<pair<int, int>> tmp(200009);
bool visited[200009];


int main(){
    /* #region cin std::cout settings */
    ios::sync_with_stdio(0);
    cin.tie(0);
    std::cout.tie(0);
    /* #endregion */
    cin >> N >> M;
    vector<int> deg(N+1, 0); // 各頂点の出次数
    for(int i=1;i<=M;i++){
        cin >> X[i] >> Y[i];
        g1[X[i]].push_back(Y[i]);
        deg[Y[i]]++; // 入次数
    }

    for(int i=1;i<=N;i++){
        tmp[i] = make_pair(10000000, i);
    }

    bool flg = true;

    using Graph = vector<vector<int>>;
    // シンクたちをキューに挿入する
    queue<int> que;
    for (int i = 1; i <= N; ++i) if (deg[i] == 0) que.push(i);

    // 探索開始
    vector<int> order;
    while (!que.empty()) {
        // 入次数チェック
        if(que.size() != 1){
            flg = false;
            break;
        }
        // キューから頂点を取り出す
        int v = que.front(); que.pop();
        order.push_back(v);

        // v へと伸びている頂点たちを探索する
        for (auto nv : g1[v]) {
            // 辺 (nv, v) を削除する
            --deg[nv];

            // それによって nv が新たにシンクになったらキューに挿入
            if (deg[nv] == 0) que.push(nv); 
        }
    }

    // for(int i=0;i<order.size();i++){
    //     cout << order[i] << " ";
    // }
    // cout << endl;

    vector<int> ans(N+1);
    for(int i=0;i<order.size();i++){
        ans[order[i]] = i+1;
    }

    yesno(flg);
    if(!flg) return 0;

    for(int i=1;i<=N;i++){
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}