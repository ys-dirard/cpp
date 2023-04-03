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

int H, W, Ch, Dh, Cw, Dw;
char S[1009][1009];
vvi dist(1009, vi(1009, 1e9));

const int di[4] = {1, 0, -1, 0};
const int dj[4] = {0, 1, 0, -1};

const int wi[20] = {-2, -2, -2, -2, -2, -1, -1, -1, -1, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2, 2};
const int wj[20] = {-2, -1, 0, 1, 2, -2, -1, 1, 2, -2, 2, -2, -1, 1, 2, -2, -1, 0, 1, 2};

int main(){
    /* #region cin cout settings */
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    /* #endregion */
    cin >> H >> W >> Ch >> Cw >> Dh >> Dw;
    rep(i, 1, H+1) rep(j, 1, W+1){
        cin >> S[i][j];
    }

    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

    pq.push({0, Ch, Cw});
    dist[Ch][Cw] = 0;

    while(!pq.empty()){
        tuple<int, int, int> t = pq.top();
        pq.pop();
        int d = get<0>(t);
        int pi = get<1>(t);
        int pj = get<2>(t);

        for(int i=0;i<4;i++){
            int ni = pi + di[i];
            int nj = pj + dj[i];
            if(ni < 1 || ni > H || nj < 1 || nj > W || S[ni][nj] == '#') continue;

            if(dist[ni][nj] <= d) continue;
            dist[ni][nj] = d;
            pq.push({d, ni, nj});
        }

        for(int i=0;i<20;i++){
            int ni = pi + wi[i];
            int nj = pj + wj[i];
            if(ni < 1 || ni > H || nj < 1 || nj > W || S[ni][nj] == '#') continue;

            if(dist[ni][nj] <= d+1) continue;
            dist[ni][nj] = d+1;
            pq.push({d+1, ni, nj});
        }
    }
    
    if(dist[Dh][Dw] < 1e9) cout << dist[Dh][Dw] << endl;
    else cout << -1 << endl;

    // rep(i, 1, H+1){
    //     rep(j, 1, W+1){
    //         cout << dist[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    return 0;
}