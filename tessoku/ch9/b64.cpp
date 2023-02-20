#include <bits/stdc++.h>
using namespace std;

int N, M, A[100009], B[100009], C[100009], cur[100009];
bool decision[100009];
vector<pair<int, int>> g[100009];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

int main(){
    cin >> N >> M;
    for(int i=1;i<=M;i++){
        cin >> A[i] >> B[i] >> C[i];
        g[A[i]].push_back(make_pair(C[i], B[i]));
        g[B[i]].push_back(make_pair(C[i], A[i]));\
    }

    for(int i=1;i<=N;i++){
        decision[i] = false;
        cur[i] = (1 << 30);
    }

    cur[1] = 0;
    q.push(make_pair(0, 1));

    while(!q.empty()){
        pair<int, int> tmp = q.top();
        q.pop();
        if(decision[tmp.second]) continue;
        decision[tmp.second] = true;

        for(int i=0;i<g[tmp.second].size();i++){
            cur[g[tmp.second][i].second] = min(cur[g[tmp.second][i].second], cur[tmp.second]+g[tmp.second][i].first);
            q.push(make_pair(cur[g[tmp.second][i].second], g[tmp.second][i].second));
        }
    }

    vector<int> ans;
    int pos = N, cu = cur[N];
    ans.push_back(N);
    while(pos>1){
        for(int i=0;i<g[pos].size();i++){
            if(cur[g[pos][i].second] == cu - g[pos][i].first){
                cu = cur[g[pos][i].second];
                pos = g[pos][i].second;
                ans.push_back(pos);
            }
        }
    }
    reverse(ans.begin(), ans.end());

    for(int i=0;i<ans.size();i++) cout << ans[i] << " ";
    cout << endl;
    return 0;
}