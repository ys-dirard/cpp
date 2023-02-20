#include <bits/stdc++.h>
using namespace std;

int N, X, Y;
vector<int> to[200009];
vector<int> ans;

bool dfs(int v, int p=-1){
    if (v == X){
        ans.push_back(v);
        return true;
    }

    for (int u : to[v]){
        if (u == p) continue;
        if (dfs(u, v)) {
            ans.push_back(v);
            return true;
        }
    }

    return false;
}

int main(){
    cin >> N >> X >> Y;
    for (int i=1; i<N; i++){
        int u, v;
        cin >> u >> v;
        to[u].push_back(v);
        to[v].push_back(u);
    }

    dfs(Y);
    for (int i=0; i<ans.size(); i++) cout << ans[i] << " ";
    return 0;
}