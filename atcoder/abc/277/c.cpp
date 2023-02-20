/* #region convenient */
#include <bits/stdc++.h>
#define rep(i,s,n) for(int i = s; i < n; i++)
#define ll long long
#define P pair<ll, ll>
using namespace std;
/* #endregion*/

int N, A[200009], B[200009];
map<int, vector<int>> m;
map<int, bool> vis;
queue<int> q;
int ans = 1;

int dfs(int pos){
    vis[pos] = true;
    if(m[pos].size() == 0) return pos;
    
    for(int i=0;i<m[pos].size();i++){
            if(!vis[m[pos][i]]){
                // cout << "next: " << m[pos][i] << endl;
                ans = max(ans, dfs(m[pos][i]));
            }
        }
}

int main(){
    /* #region cin cout settings */
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    /* #endregion */
    cin >> N;
    rep(i, 1, N+1){
        cin >> A[i] >> B[i];
        m[A[i]].push_back(B[i]);
        m[B[i]].push_back(A[i]);
    }

    q.push(1);
    while(!q.empty()){
        int pos = q.front();
        q.pop();
        if(vis[pos]) continue;
        vis[pos] = true;
        if(ans < pos) ans = pos;

        int sz = m[pos].size();
        for(int i=0;i<sz;i++){
            int nt = m[pos][i];
            if(!vis[nt]){
                // cout << "next: " << m[pos][i] << endl;
                q.push(nt);
            }
        }
    }
    // dfs(1);
    cout << ans << endl;
    return 0;
}