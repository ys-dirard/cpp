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

ll n;
ll v[100009];
map<ll, ll> odd, even;

int main(){
    /* #region cin cout settings */
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    /* #endregion */
    cin >> n;
    rep(i, 1, n+1){
        cin >> v[i];
        if(i%2==1){
            odd[v[i]]++;
        }else{
            even[v[i]]++;
        }
    }

    ll odd1 = 0, odd2 = 0, even1 = 0, even2 = 0;
    ll odd1n = -1, even1n = -1;
    for(auto itr=odd.begin();itr!=odd.end();itr++){
        if(itr->second >= odd1){
            odd2 = odd1;
            odd1 = itr->second;
            odd1n = itr->first;
        }
        else if(itr->second > odd2){
            odd2 = itr->second;
        }
    }
    for(auto itr=even.begin();itr!=even.end();itr++){
        if(itr->second >= even1){
            even2 = even1;
            even1 = itr->second;
            even1n = itr->first;
        }else if(itr->second > even2){
            even2 = itr->second;
        }
    }

    if(odd.size()==1 && even.size()==1 && odd1n==even1n){
        cout << n/2 << endl;
        return 0;
    }

    ll ans = 1e9;
    if(odd1n==even1n){
        chmin(ans, n-(odd1+even2));
        chmin(ans, n-(odd2+even1));
        cout << ans << endl;
        // if((odd1+even2)>(odd2+even1)){
        //     cout << n - (odd1+even2) << endl;
        // }else{
        //     cout << n - (odd2+even1) << endl;
        // }
    }else{
        cout << n - (odd1 + even1) << endl;
    }
    return 0;
}