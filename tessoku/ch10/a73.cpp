#include <bits/stdc++.h>
using namespace std;

int N, M;
long long A[100009], B[100009], C[100009], D[100009];
vector<pair<long long, long long>> g[8009];
priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> q;
bool decided[8009];
long long dist[8009];

int main(){
    cin >> N >> M;
    for(int i=1;i<=M;i++){
        cin >> A[i] >> B[i] >> C[i] >> D[i];
        long long margin = 0LL;
        if(D[i]==1) margin = 1LL;
        g[A[i]].push_back(make_pair(B[i], 10000LL*C[i]-margin));
        g[B[i]].push_back(make_pair(A[i], 10000LL*C[i]-margin));
    }

    q.push(make_pair(0, 1));
    while(!q.empty()){
        pair<long long, long long> tmp = q.top();
        q.pop();
        if(decided[tmp.second]==true) continue;
        decided[tmp.second] = true;
        dist[tmp.second] = tmp.first;

        for(int i=0;i<g[tmp.second].size();i++){
            if(decided[g[tmp.second][i].first]==true) continue;
            q.push(make_pair(dist[tmp.second]+g[tmp.second][i].second, g[tmp.second][i].first));
        }
    }
    long long distance = ceil(1.0 * dist[N] / 10000);
    cout << distance << " " << 10000 * distance - dist[N] << endl;
    return 0;
}