#include <bits/stdc++.h>
using namespace std;

int N, M, A[100009], B[100009];
vector<int> g[100009];
bool visited[100009];
vector<int> path, ans;

void dfs(int pos){
    if(pos==N){
        ans = path;
        return;
    }
    visited[pos] = true;
    for(int next: g[pos]){
        if(!visited[next]){
            path.push_back(next);
            dfs(next);
            path.pop_back();
        }
    }
}

int main(){
    cin >> N >> M;
    for(int i=1;i<=M;i++){
        cin >> A[i] >> B[i];
        g[A[i]].push_back(B[i]);
        g[B[i]].push_back(A[i]);
    }

    path.push_back(1);
    dfs(1);

    for(int i=0;i<ans.size();i++){
        if(i>=1) cout << " ";
        cout << ans[i];
    }
    cout << endl;
    return 0;
}