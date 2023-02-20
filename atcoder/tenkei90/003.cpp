#include <bits/stdc++.h>
using namespace std;

int N;
int A[100009], B[100009];
vector<int> g[100009];
int kakutei[100009];
int dist[100009];
int type = 0;

// 頂点N個、辺N-1本で連結な木ならサイクルは存在しない！
void dfs(int pos, int par, int rt){
    kakutei[pos] = rt;
    dist[pos] = dist[par] + 1;

    for(int i=0;i<g[pos].size();i++){
        if(g[pos][i] != par && kakutei[g[pos][i]] == -1){
            dfs(g[pos][i], pos, rt);
        }
    }
}

void init(){
    for(int i=1;i<=N;i++){
        kakutei[i] = -1;
        dist[100009] = 0;
        type = 0;
    }
}

int max_pos(){
    int d = 0;
    int pos = -1;
    for(int i=1;i<=N;i++){
        if(d<dist[i]){
            d = dist[i];
            pos = i;
        }
    }
    return pos;
}

int main(){
    cin >> N;
    for(int i=1;i<N;i++){
        cin >> A[i] >> B[i];
        g[A[i]].push_back(B[i]);
        g[B[i]].push_back(A[i]);
    }
    init();

    dist[1] = 0;
    kakutei[1] = 0;
    for(int i=0;i<g[1].size();i++){
        if(kakutei[g[1][i]] == -1){
            type++;
            dfs(g[1][i], 1, type);
        }
    }
    int pos = max_pos();

    init();
    dist[pos] = kakutei[pos] = 0;
    for(int i=0;i<g[pos].size();i++){
        if(kakutei[g[pos][i]] == -1){
            type++;
            dfs(g[pos][i], pos, type);
        }
    }
    pos = max_pos();
    // cout << pos << endl;
    cout << dist[pos] + 1 << endl;

    // vector<int> dist_per_type(type+1, 0);
    // for(int i=1;i<=N;i++){
    //     // cout << i << ": dist=" << dist[i] << ", kakutei=" << kakutei[i] << endl;
    //     dist_per_type[kakutei[i]] = max(dist_per_type[kakutei[i]], dist[i]);
    // }
    // sort(dist_per_type.begin(), dist_per_type.end(), greater<int>());
    // cout << (dist_per_type[0] + dist_per_type[1] + 1) << endl;
    return 0;
}