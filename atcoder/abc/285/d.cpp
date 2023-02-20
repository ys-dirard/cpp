/* #region convenient */
#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;


int N;
string S[100009], T[100009];
map<string, string> mp;
map<string, bool> visited;

bool dfs(string s, string st){
    visited[s] = true;
    if(mp[s] == "") return true;
    if(mp[s] == st) return false;
    // visited[s] = true;
    return dfs(mp[s], st);
}

int main(){
    /* #region cin cout settings */
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    /* #endregion */
    cin >> N;
    for(int i=1;i<=N;i++){
        cin >> S[i] >> T[i];
        mp[S[i]] = T[i];
    }

    bool flg = true;
    for(int i=1;i<=N;i++){
        if(visited[S[i]]) continue;

        flg = flg & dfs(mp[S[i]], S[i]);
        
    }
    if(flg) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}