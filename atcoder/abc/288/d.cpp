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

ll N, K, Q;
ll A[200009];
ll l[200009], r[200009];
ll S[200009];

int main(){
    /* #region cin cout settings */
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    /* #endregion */
    cin >> N >> K;
    for(int i=1;i<=N;i++){
        cin >> A[i];
    }
    cin >> Q;
    for(int i=1;i<=Q;i++){
        cin >> l[i] >> r[i];
    }

    // S[0] = -1111111;
    for(int i=1;i<=N;i++){
        if((i-1)/K == 0){
            S[i] = A[i];
        }else{
            S[i] = S[i - K] + A[i];
        }
    }
    // for(int i=1;i<=N;i++){
    //     cout << S[i] << " ";
    // }
    // cout << endl;

    for(int i=1;i<=Q;i++){
        // cout << "i=" << i << endl;
        set<ll> st;
        for(int j=r[i]-K+1;j<=r[i];j++){
            ll val = S[j] - S[j - K * ((j - l[i]) / K)] + A[j - K * ((j - l[i]) / K)];
            // cout << val << " ";
            st.insert(val);
        }
        // cout << endl;
        // cout << st.size() << endl;
        // for(auto itr=st.begin();itr!=st.end();itr++){
        //     cout << *itr << " ";
        // }
        // cout << endl;
        if(st.size()==1) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}