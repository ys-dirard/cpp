#include <bits/stdc++.h>
using namespace std;

int N, M;
int A[100009], B[100009];
vector<vector<int>> g(100009, vector<int>());
vector<bool> visited(100009, false);
deque<int> ans;

// トポロジカルソート(dfs版)、サイクルがなく可能であれば(DAGであれば)trueを返す、サイクルがあればfalseを返す
// トポロジカルソートはDAGのでの概念
// スタートのposは葉からスタートする必要がある
bool dfs(int pos, int par){
    bool no_cycle = true;
    if(visited[pos]) return false;
    visited[pos] = true;
    for(int i=0;i<g[pos].size();i++){
        if(g[pos][i] != par){
            no_cycle &= dfs(g[pos][i], pos);
        }
    }
    ans.push_front(pos);
    return no_cycle;
};

int main(){
    cin >> N >> M;
    for(int i=1;i<=M;i++){
        cin >> A[i] >> B[i];
        // A[i] -> B[i] に辺を張る
        g[A[i]].push_back(B[i]);
    }

    bool no_cycle = dfs(1, -1);
    if(no_cycle) cout << "DAG" << endl;
    else cout << "cycle" << endl;
    for(int i=0;i<ans.size();i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}