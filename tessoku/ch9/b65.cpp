#include <bits/stdc++.h>
using namespace std;

int N, T, A[100009], B[100009];
int ans[100009];

vector<int> g[100009];
bool visited[100009];

int dfs(int pos){
    visited[pos] = true;
    ans[pos] = 0;

    for(int i=0;i<g[pos].size();i++){
        int next = g[pos][i];
        if(!visited[next]){
            int ret = dfs(next);
            ans[pos] = max(ans[pos], ret + 1);
        }
    }

    return ans[pos];
}

int main(){
    cin >> N >> T;
    for(int i=1;i<N;i++){
        cin >> A[i] >> B[i];
        g[A[i]].push_back(B[i]);
        g[B[i]].push_back(A[i]);
    }

    dfs(T);

    for(int i=1;i<=N;i++){
        if(i>=2) cout << " ";
        cout << ans[i];
    }
    cout << endl;
    return 0;
}