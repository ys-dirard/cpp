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

class UnionFind{
public:
    vector<int> parent, siz;

    void init(int N){
        parent.resize(N, -1);
        siz.resize(N, 1);
    }

    int root(int x){
        if(parent[x] == -1){
            return x;
        }else{
            return parent[x] = root(parent[x]);
        }
    }

    void unite(int x, int y){
        int rx = root(x), ry = root(y);
        if(rx == ry) return;
        if(siz[rx] > siz[ry]){
            parent[ry] = rx;
            siz[rx] += siz[ry];
        }else{
            parent[rx] = ry;
            siz[ry] += siz[rx];
        }
    }

    bool same(int x, int y){
        return root(x) == root(y);
    }
};

string S;
bool hit[10];
set<int> cols;
UnionFind uf;

int main(){
    /* #region cin cout settings */
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    /* #endregion */
    cin >> S;
    bool flg = true;
    uf.init(11);

    for(int i=0;i<S.size();i++){
        hit[i] = 1 - (S[i]-'0');
    }
    if(hit[6]) cols.insert(0);
    if(hit[3]) cols.insert(1);
    if(hit[1] & hit[7]) cols.insert(2);
    if(hit[0] & hit[4]) cols.insert(3);
    if(hit[2] & hit[8]) cols.insert(4);
    if(hit[5]) cols.insert(5);
    if(hit[9]) cols.insert(6);

    if(S[0]=='1'){
        cout << "No" << endl;
        return 0;
    }

    for(int i=0;i<7;i++){
        for(int j=i+2;j<7;j++){
            if(cols.count(i) == 0 && cols.count(j) == 0){
                bool sp = false;
                for(int k=i+1;k<j;k++){
                    sp |= cols.count(k) == 1;
                }
                if(sp){
                    cout << "Yes" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "No" << endl;
    // for(int i=0;i<6;i++){
    //     if(cols.count(i) == 0 && cols.count(i+1) == 0){
    //         uf.unite(i, i+1);
    //     }
    // }
    // if(S[0]=='0' && !uf.same(0, 6) && cols.size() > 0){
    //     flg = true;
    // }else{
    //     flg = false;
    // }
    // yesno(flg);
    return 0;
}