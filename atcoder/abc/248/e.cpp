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

int N, K;
int X[309], Y[309];
pii p[309];

const long double EPS = 1e-20;
const long double PI = 3.1415926535897932;

int main(){
    /* #region cin cout settings */
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    /* #endregion */
    cin >> N >> K;
    rep(i, 1, N+1){
        cin >> X[i] >> Y[i];
        p[i] = {X[i], Y[i]};
    }

    if(K==1){
        cout << "Infinity" << endl;
        return 0;
    }

    sort(p+1, p+N+1);

    int cnt = 0;

    for(int i=1;i<N;i++){
        vector<long double> v;
        for(int j=i+1;j<=N;j++){
            if(p[i].first==p[j].first){
                int sgn = (p[j].second - p[i].second > 0) ? 1 : -1;
                v.push_back(PI / 2 * sgn);
            }else{
                v.push_back(atan2l(p[j].second - p[i].second, p[j].first - p[i].first));
            }
        }

        // cout << "*****" << i << "*****" << endl;
        // for(int j=0;j<v.size();j++){
        //     cout << v[j] << " ";
        // }
        // cout << endl;
        
        sort(v.begin(), v.end());
        int s = 0, pre = 0;
        long double tmp = v[0];
        for(s=0;s<v.size();){
            tmp = v[s];
            pre = s;
            while(s < v.size() && v[s] - tmp < EPS){
                s++;
            }
            if(s-pre==K-1) cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}