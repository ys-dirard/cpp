#include <bits/stdc++.h>
using namespace std;

int N, M, A[19], X[109], Y[109], Z[109];
int dist[2009];
vector<int> g[2009];

int get_next(int pos, int idx){
    int State[19];

    for(int i=1;i<=N;i++){
        int wari = (1 << (i-1));
        State[i] = (pos / wari) % 2;
    }
    State[X[idx]] = 1 - State[X[idx]];
    State[Y[idx]] = 1 - State[Y[idx]];
    State[Z[idx]] = 1 - State[Z[idx]];

    int ret = 0;
    for(int i=1;i<=N;i++){
        if(State[i]==1) ret += (1 << (i-1));
    }
    return ret;
}

int main(){
    cin >> N >> M;
    for(int i=1;i<=N;i++) cin >> A[i];
    for(int i=1;i<=M;i++) cin >> X[i] >> Y[i] >> Z[i];

    for(int i=0;i<(1<<N);i++){
        for(int j=1;j<=M;j++){
            int next = get_next(i, j);
            g[i].push_back(next);
        }
    }

    int goal = (1<<N)-1;
    int start = 0;
    for(int i=1;i<=N;i++) start += A[i] * (1<<(i-1));

    queue<int> q;
    for(int i=0;i<(1<<N);i++) dist[i] = -1;
    dist[start] = 0;
    q.push(start);

    while(!q.empty()){
        int pos = q.front();
        q.pop();

        for(int i=0;i<g[pos].size();i++){
            int next = g[pos][i];
            if(dist[next] == -1){
                dist[next] = dist[pos]+1;
                q.push(next);
            }
        }
    }

    cout << dist[goal] << endl;
    return 0;
}