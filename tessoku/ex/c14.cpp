#include <bits/stdc++.h>

#define rep(i,s,n) for(int i = s; i < n; i++)
#define ll long long
#define P pair<ll, ll>

using namespace std;

int N, M, A[100009], B[100009], C[100009];
bool kakutei[100009];
int dist[100009];
vector<pair<int, int>> g[100009];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

int main(){
    cin >> N >> M;
    rep(i, 1, M+1){
        cin >> A[i] >> B[i] >> C[i];
        g[A[i]].push_back(make_pair(B[i], C[i]));
        g[B[i]].push_back(make_pair(A[i], C[i]));
    }

    dist[1] = 0;
    q.push(make_pair(0, 1));
    while(!q.empty()){
        pair<int, int> tmp = q.top();
        q.pop();
        int pos = tmp.second;
        int cost = tmp.first;
        if(kakutei[pos]) continue;

        kakutei[pos] = true;
        dist[pos] = cost;
        for(int i=0;i<g[pos].size();i++){
            q.push(make_pair(cost+g[pos][i].second, g[pos][i].first));
        }
    }

    // cout << dist[N] << endl;
    vector<int> path;
    set<int> pl;
    queue<int> qp;

    int ps = N;
    path.push_back(ps);
    pl.insert(ps);
    qp.push(ps);
    while(!qp.empty()){
        int tp = qp.front();
        qp.pop();
        // cout << "\ntp\n" << endl;
        for(int i=0;i<g[tp].size();i++){
            if(dist[g[tp][i].first] + g[tp][i].second == dist[tp]){
                // ps = g[ps][i].first;
                // path.push_back(ps);
                pl.insert(g[tp][i].first);
                qp.push(g[tp][i].first);
            }
        }
    }
    // reverse(path.begin(), path.end());
    // for(int i=0;i<path.size();i++){
    //     cout << path[i] << " ";
    // }
    // cout << endl;
    cout << pl.size() << endl;
    return 0;
}