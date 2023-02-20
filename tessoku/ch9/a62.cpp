#include <bits/stdc++.h>
using namespace std;

int N, M, A[100009], B[100009];
vector<int> g[100009];
bool visited[100009];

void dfs(int pos){
    visited[pos] = true;
    for(int next: g[pos]){
        if(!visited[next]){
            dfs(next);
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

    dfs(1);
    bool cont = true;
    for(int i=1;i<=N;i++) cont = cont && visited[i];
    if(cont) cout << "The graph is connected." << endl;
    else cout << "The graph is not connected." << endl;
    return 0;
}