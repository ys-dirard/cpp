#include <bits/stdc++.h>
using namespace std;

int n, u, k, G[109][109];
vector<int> adj[109];
int tmp;

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> u >> k;
        for(int j=0;j<k;j++){
            cin >> tmp;
            adj[u].push_back(tmp);
            G[u][tmp] = 1;
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(j>1) cout << " ";
            cout << G[i][j];
        }
        cout << endl;
    }
    return 0;
}