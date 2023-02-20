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

ll N, M;
int A[100009];
bool D[100009];
set<int> st;

int main(){
    /* #region cin cout settings */
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    /* #endregion */
    cin >> N >> M;
    rep(i, 0, N){
        cin >> A[i];
        int tmp = A[i];
        for(int j=2;j<=sqrt(A[i]);j++){
            while(tmp % j == 0){
                tmp /= j;
                st.insert(j);
            }
        }
        if(tmp>1) st.insert(tmp);
        
    }
    rep(i, 0, M+1) D[i] = true;

    for(auto itr=st.begin();itr!=st.end();itr++){
        int n = *itr;
        // cout << "***" << n << endl;
        for(int j=n;j<=M;j+=n){
            D[j] = false;
        }
    }

    int ans = 0;
    rep(i, 1, M+1){
        ans += D[i];
    }

    cout << ans << endl;
    rep(i, 1, M+1){
        if(D[i]){
            cout << i << endl;
        }
    }
}

/*
別解

#include<bits/stdc++.h>
using namespace std;
int l;
string s,t;
vector<string> res;
void find(int fl){
  if(fl==0){
    res.push_back(t);
    return;
  }
  for(int i=0;i<l;i++){
    if(fl&(1<<i)){
      t.push_back(s[i]);
      find(fl^(1<<i)); 今回i番目を選ぶので、i番目は選んだこと(0)にする(事前のifでi番目のbitは1のものしか来ないので^で１になることはない)
      t.pop_back();
    }
  }
}
int main(){
  int k;
  cin >> s >> k;
  l=s.size();
  find((1<<l)-1);
  sort(res.begin(),res.end());
  unique(res.begin(),res.end());
  cout << res[k-1] << '\n';
  return 0;
}
*/