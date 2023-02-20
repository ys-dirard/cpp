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

int H, W;
bool A[1009][1009];
int cnt = 0;

int main(){
    /* #region cin std::cout settings */
    ios::sync_with_stdio(0);
    cin.tie(0);
    std::cout.tie(0);
    /* #endregion */
    cin >> H >> W;
    for(int i=1;i<=H;i++){
        for(int j=1;j<=W;j++){
            cin >> A[i][j];
        }
    }

    bool pre_changed = false;
    bool changed = false;
    for(int i=1;i<H;i++){
        changed = false;
        for(int j=1;j<=W;j++){
            for(int k=0;k<2;k++){
                bool side = false;
                if(j==1){
                    side = (A[i][j] != A[i][j+1]);
                }else if(j==W){
                    side = (A[i][j] != A[i][j-1]);
                }else{
                    side = (A[i][j] != A[i][j-1] && A[i][j] != A[i][j+1]);
                }
                if(side && ((A[i][j] ^ pre_changed) !=(A[i+1][j] ^ changed))){
                    if(!changed){
                        // std::cout << i << endl;
                        changed = true;
                        cnt++;
                    }else{
                        std::cout << -1 << endl;
                        return 0;
                    }
                    
                }
                
            }
        }
        if(i!=H-1) pre_changed = changed;
    }

    // last row check
    for(int j=1;j<=W;j++){
        bool side;
        if(j==1){
            side = (A[H][j] != A[H][j+1]);
        }else if(j==W){
            side = (A[H][j] != A[H][j-1]);
        }else{
            side = (A[H][j] != A[H][j-1] && A[H][j] != A[H][j+1]);
        }

        if(side && ((A[H][j] ^ changed) !=(A[H-1][j] ^ pre_changed))){
            cout << -1 << endl;
            return 0;
        }        
    }

    std::cout << min(cnt, H-cnt) << endl;
}