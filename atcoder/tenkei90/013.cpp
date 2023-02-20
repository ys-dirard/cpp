#include <bits/stdc++.h>
using namespace std;

int N, M;
int A[100009], B[100009], C[100009];
vector<pair<int, int>> g[100009];
int dist_front[100009];
int dist_back[100009];
bool det[100009];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void init(int t){
    for(int i=1;i<=N;i++){
        det[i] = false;
        if(t==0){
            dist_front[i] = 1<<30;
        }else{
            dist_back[i] = 1<<30;
        }
    }
    pq = decltype(pq)();
}

int main(){
    cin >> N >> M;
    for(int i=1;i<=M;i++){
        cin >> A[i] >> B[i] >> C[i];
        g[A[i]].push_back({B[i], C[i]});
        g[B[i]].push_back({A[i], C[i]});
    }

    // from 1
    init(0);
    pq.push({0, 1});
    while(!pq.empty()){
        pair<int, int> pr = pq.top();
        pq.pop();
        int pos = pr.second;
        int cost = pr.first;
        if(det[pos]) continue;
        det[pos] = true;
        dist_front[pos] = cost;

        for(int i=0;i<g[pos].size();i++){
            pair<int, int> next = g[pos][i];
            int next_pos = next.first;
            if (det[next_pos]) continue;
            int next_cost = next.second + cost;
            pq.push({next_cost, next_pos});
        }
    }
    // cout << dist_front[7] << endl;

    // from N
    init(1);
    pq.push({0, N});
    while(!pq.empty()){
        pair<int, int> pr = pq.top();
        pq.pop();
        int pos = pr.second;
        int cost = pr.first;
        if(det[pos]) continue;
        det[pos] = true;
        dist_back[pos] = cost;

        for(int i=0;i<g[pos].size();i++){
            pair<int, int> next = g[pos][i];
            int next_pos = next.first;
            if (det[next_pos]) continue;
            int next_cost = next.second + cost;
            pq.push({next_cost, next_pos});
        }
    }
    // cout << dist_back[3] << endl;
    
    for(int i=1;i<=N;i++){
        cout << (dist_front[i] + dist_back[i]) << endl;
    }
    return 0;
}