#include <bits/stdc++.h>
using namespace std;

int N,M,A[100009],B[100009];
bool visited[100009];
vector<int> g[100009];
queue<int> q;
int path[100009];

int main(){
    cin >> N >> M;
    for(int i=1;i<=M;i++){
        cin >> A[i] >> B[i];
        g[A[i]].push_back(B[i]);
        g[B[i]].push_back(A[i]);
    }
    for(int i=1;i<=N;i++) path[i] = -1;

    path[1] = 0;
    visited[1] = true;
    q.push(1);
    while(!q.empty()){
        int pos = q.front();
        q.pop();

        for(int next: g[pos]){
            if(!visited[next]){
                path[next] = path[pos] + 1;
                visited[next] = true;
                q.push(next);
            }
        }
    }

    for(int i=1;i<=N;i++) cout << path[i] << endl;
    return 0;
}