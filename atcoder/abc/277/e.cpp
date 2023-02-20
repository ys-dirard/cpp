/* #region convenient */
#include <bits/stdc++.h>
#define rep(i,s,n) for(int i = s; i < n; i++)
#define ll long long
#define P pair<ll, ll>
using namespace std;

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
/* #endregion*/

int N, M, K;
int u[200009], v[200009], a[200009], s[200009];
vector<P> g[400009];
vector<ll> dist(400009, 1<<30);
bool det[400009];
priority_queue<P, vector<P>, greater<P>> q;

int main(){
    /* #region cin cout settings */
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    /* #endregion */
    cin >> N >> M >> K;
    rep(i, 1, M+1){
        cin >> u[i] >> v[i] >> a[i];
        if(a[i]){
            g[u[i]].push_back(P(v[i], 1));
            g[v[i]].push_back(P(u[i], 1));
        }else{
            g[u[i]+N].push_back(P(v[i]+N, 1));
            g[v[i]+N].push_back(P(u[i]+N, 1));
        }
    }
    rep(i, 1, K+1){
        cin >> s[i];
        g[s[i]].push_back(P(s[i]+N, 0));
        g[s[i]+N].push_back(P(s[i], 0));
    }

    q.push(P(0, 1));
    while(!q.empty()){
        P tmp = q.top();
        q.pop();
        ll pos = tmp.second;
        if(det[pos]) continue;
        ll cost = tmp.first;
        det[pos] = true;
        dist[pos] = cost;

        for(int i=0;i<g[pos].size();i++){
            ll next_pos = g[pos][i].first;
            if(det[next_pos]) continue;
            ll next_cost = g[pos][i].second;
            q.push(P(cost + next_cost, next_pos));
        }
    }

    ll ans = min(dist[N], dist[N*2]);
    if(ans == (1<<30)) ans = -1;
    cout << ans << endl;
    return 0;
}