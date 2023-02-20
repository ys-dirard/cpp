#include <bits/stdc++.h>
using namespace std;

int v, e, s, t;
vector<int> g[10009];
bool kakutei[10009];
int to_count[10009];
vector<int> ts;


void dfs(int s){
    // if(kakutei[s]) return;
    kakutei[s] = true;

    for(int i=0;i<g[s].size();i++){
        if(kakutei[g[s][i]]) continue;

        dfs(g[s][i]);
    }
    ts.push_back(s);
}

int main(){
    for(int i=0;i<v;i++){
        kakutei[i] = false;
        to_count[i] = 0;
    }
    cin >> v >> e;
    for(int i=0;i<e;i++){
        cin >> s >> t;
        g[s].push_back(t);
        to_count[s]++;
    }

    for(int i=0;i<v;i++){
        if(!kakutei[i]){
            dfs(i);
        }
    }

    reverse(ts.begin(), ts.end());
    for(int i=0;i<ts.size();i++){
        cout << ts[i] << endl;
    }
    return 0;
}