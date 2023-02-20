// 11,809,372

#include <bits/stdc++.h>
using namespace std;

int N, M, D, K;
int u[3009], v[3009], w[3009];
int x[1009], y[1009];
vector<int> g[1009];
vector<vector<int>> dist;

// [a, b]の整数をランダムに発生させる関数
int randint(int a, int b){
    return a + rand() % (b - a + 1);
}

double randdouble(){
    return 1.0 * rand() / RAND_MAX;
}

void reset(int N){
    dist.resize(N+1, vector<int>(N+1, 1e9));
}

void rand_perm(vector<int>& p){
    int n_edge = p.size();
    for(int i=0;i<n_edge;i++){
        int r = randint(i, n_edge-1);
        swap(p[i], p[r]);
    }
}

int main(){
    // input
    cin >> N >> M >> D >> K;
    for(int i=1;i<=M;i++){
        cin >> u[i] >> v[i] >> w[i];
    }
    for(int i=1;i<=N;i++){
        cin >> x[i] >> y[i];
    }

    // index
    vector<int> idx(M);
    iota(idx.begin(), idx.end(), 1);

    // for(int i=0;i<idx.size();i++){
    //     cout << idx[i] << " ";
    // }
    // cout << endl;
    rand_perm(idx);
    // for(int i=0;i<idx.size();i++){
    //     cout << idx[i] << " ";
    // }
    // cout << endl;

    // idx2ans
    vector<int> ans(M+1);
    for(int i=0;i<idx.size();i++){
        int day = i / K + 1;
        ans[idx[i]] = day;
    }

    // print ans
    for(int i=1;i<=M;i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}