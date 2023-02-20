// 472,610,987

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>

struct edge{
    ll to, cost;
};

class UnionFind{
public:
    vector<int> parent, siz;

    void init(int N){
        parent.resize(N, -1);
        siz.resize(N, 1);
    }

    int root(int x){
        if(parent[x] == -1){
            return x;
        }else{
            return parent[x] = root(parent[x]);
        }
    }

    void unite(int x, int y){
        int rx = root(x), ry = root(y);
        if(rx == ry) return;
        if(siz[rx] > siz[ry]){
            parent[ry] = rx;
            siz[rx] += siz[ry];
        }else{
            parent[rx] = ry;
            siz[ry] += siz[rx];
        }
    }

    bool same(int x, int y){
        return root(x) == root(y);
    }
};

ll N, M, D, K;
ll u[3009], v[3009], w[3009];
ll x[1009], y[1009];
priority_queue<pll> pq; // (cost, edge_idx)
UnionFind uf;
ll cont_idx[1009];
vector<edge> g[1009];
vector<vector<vector<ll>>> dist; // dist[d][s][t]: d:day, s:start, t:goal

// [a, b]の整数をランダムに発生させる関数
ll randint(ll a, ll b){
    return a + rand() % (b - a + 1);
}

double randdouble(){
    return 1.0 * rand() / RAND_MAX;
}

void reset(ll N, ll D){
    dist.resize(D+1, vector<vector<ll>>(N+1, vector<ll>(N+1, 1e9)));
}

void rand_perm(vector<ll>& p){
    ll n_edge = p.size();
    for(ll i=0;i<n_edge;i++){
        ll r = randint(i, n_edge-1);
        swap(p[i], p[r]);
    }
}

// a日目とb日目をランダムに変更
vector<ll> rand_perm_ab(ll a, ll b, vector<vector<ll>>& v){
    vector<ll> res;
    int do_per_day = min(K, M / D + 1);
    for(int i=0;i<v[a].size();i++) res.push_back(v[a][i]);
    for(int i=0;i<v[b].size();i++) res.push_back(v[b][i]);

    rand_perm(res);

    return res;
}

// Dijkstra法
// 計算量O(|E| log |V|)
void dijkstra(ll s, ll d){
    // first=最短距離, second=頂点番号
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
    dist[d][s][s] = 0;
    pq.push({0, s});

    while(!pq.empty()){
        pair<long long, long long> p = pq.top();
        pq.pop();
        ll v = p.second;
        if(dist[d][s][v] < p.first) continue;
        // まだ使われていない頂点から距離が最小のモノを探す
        for(ll i=0;i<g[v].size();i++){
            edge e = g[v][i];
            if(dist[d][s][e.to] > dist[d][s][v] + e.cost){
                dist[d][s][e.to] = dist[d][s][v] + e.cost;
                pq.push({dist[d][s][e.to], e.to});
            }
        }
    }
}

ll get_dist_sum(ll d){
    ll res = 0LL;
    for(int i=1;i<=N;i++){
        for(int j=i;j<=N;j++){
            res += dist[d][i][j];
        }
    }
    return res;
}

int main(){
    int TIME_LIMIT = 5.5 * CLOCKS_PER_SEC; // 5.95秒, CLOCKS_PER_SEC: 1秒が何ミリ秒かを表す
    int ti = clock();
    // input
    cin >> N >> M >> D >> K;
    for(int i=1;i<=M;i++){
        cin >> u[i] >> v[i] >> w[i];
        g[u[i]].push_back({v[i], w[i]});
        g[v[i]].push_back({u[i], w[i]});
        pq.push({w[i], i});
    }
    for(int i=1;i<=N;i++){
        cin >> x[i] >> y[i];
    }

    // uf.init(N+1);
    // for(int i=1;i<=M;i++){

    // }

    int do_per_day = K; //max(K, M / D + 1);
    int n = 0;
    vector<int> ans(M+1);
    while(!pq.empty()){
        pll tmp = pq.top();
        pq.pop();
        ll idx = tmp.second;
        ans[idx] = n / do_per_day + 1;
        n++;
    }
    // cout << "fin" << endl;

    // index
    // int do_per_day = min(K, M / D + 1);
    // vector<ll> idx(M);
    // iota(idx.begin(), idx.end(), 1);
    // rand_perm(idx);
    // vector<vector<ll>> idx_list(D+1, vector<ll>());
    // for(int i=0;idx.size();i++){
    //     idx_list[i / do_per_day + 1].push_back(idx[i]);
    // }

    // search
    // while(clock() - ti < TIME_LIMIT){
    //     ll a = randint(1, D-1);
    //     ll b = randint(1, D-1);
    //     if(a==b) continue;
    //     else if(a>b) swap(a, b);


    // }

    // idx2ans
    // int do_per_day = min(K, M / D + 1);
    // vector<int> ans(M+1);
    // for(int i=0;i<idx.size();i++){
    //     int day = i / do_per_day + 1;
    //     ans[idx[i]] = day;
    // }

    // print ans
    for(int i=1;i<=M;i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}