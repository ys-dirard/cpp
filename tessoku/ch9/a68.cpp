#include <bits/stdc++.h>
using namespace std;

struct Edge{
    int to, cap, rev;
};


class MaximumFlow{
public:
    int size_ = 0;
    bool used[409];
    vector<Edge> g[409];

    void init(int N){
        size_ = N;
        for(int i=0;i<size_;i++) g[i].clear();
    }

    void add_edge(int a, int b, int c){
        int ca = g[a].size();
        int cb = g[b].size();
        g[a].push_back(Edge{b, c, cb});
        g[b].push_back(Edge{a, 0, ca});
    }

    int dfs(int pos, int goal, int F){
        if(pos==goal) return F;
        used[pos] = true;

        for(int i=0;i<g[pos].size();i++){
            if(g[pos][i].cap==0) continue;

            if(used[g[pos][i].to]==true) continue;

            int flow = dfs(g[pos][i].to, goal, min(g[pos][i].cap, F));

            if(flow > 0){
                g[pos][i].cap -= flow;
                g[g[pos][i].to][g[pos][i].rev].cap += flow;
                return flow;
            }
        }
        return 0;
    }

    int max_flow(int s, int t){
        int total = 0;
        while(true){
            for(int i=0; i<=size_; i++) used[i] = false;

            int F = dfs(s, t, 100000000);

            if(F==0) break;
            total += F;
        }
        return total;
    }
};

int N, M, A[409], B[409], C[409];

int main(){
    cin >> N >> M;
    for(int i=1;i<=M;i++) cin >> A[i] >> B[i] >> C[i];

    MaximumFlow mf;
    mf.init(N);
    for(int i=1;i<=M;i++) mf.add_edge(A[i], B[i], C[i]);

    int ans = mf.max_flow(1, N);
    cout << ans << endl;
    return 0;
}