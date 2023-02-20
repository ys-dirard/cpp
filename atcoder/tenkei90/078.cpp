#include <bits/stdc++.h>
using namespace std;

int N, M, a, b;
vector<int> g[100009];

int main(){
    cin >> N >> M;
    for(int i=1;i<=M;i++){
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
    int ans = 0;
    for(int i=1;i<=N;i++){
        sort(g[i].begin(), g[i].end());
        int pos = lower_bound(g[i].begin(), g[i].end(), i) - g[i].begin();
        if(pos==1) ans++;
    }
    cout << ans << endl;
    return 0;
}