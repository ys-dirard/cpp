/* #region convenient */
#include <bits/stdc++.h>
#define rep(i,s,n) for(int i = s; i < n; i++)
#define ll long long
#define P pair<ll, ll>
using namespace std;
/* #endregion*/

int N;
string S[59];
char fa[] = {'H', 'D', 'C', 'S'};
char sa[] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
set<char> f(begin(fa), end(fa));
set<char> s(begin(sa), end(sa));
set<string> ss;

int main(){
    /* #region cin cout settings */
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    /* #endregion */
    cin >> N;
    for(int i=1;i<=N;i++){
        cin >> S[i];
    }

    bool ans = true;
    for(int i=1;i<=N;i++){
        auto it1 = f.find(S[i][0]);
        if(it1 == f.end()) ans = false;

        auto it2 = s.find(S[i][1]);
        if(it2 == s.end()) ans = false;

        ss.insert(S[i]);
        if(ss.size() != i) ans = false;
    }
    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}