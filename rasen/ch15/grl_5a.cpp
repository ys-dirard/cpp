#include <bits/stdc++.h>
using namespace std;

int n, s, t, w;
int dist[100009];
bool kakutei[100009];
vector<pair<int, int>> g[100009];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main(){
    cin >> n;
    for(int i=1;i<n;i++){
        cin >> s >> t >> w;
        g[s].push_back({t, w});
        g[t].push_back({s, w});
    }

    dist[0] = 0;
    pq.push({0, 0});
    while(!pq.empty()){
        pair<int, int> tmp = pq.top();
        pq.pop();

        kakutei[tmp.second] = true;
        dist[tmp.second] = tmp.first;

        for(int i=0;i<g[tmp.second].size();i++){
            if(!kakutei[g[tmp.second][i].first]){
                pq.push({tmp.first + g[tmp.second][i].second, g[tmp.second][i].first});
            }
        }
    }

    int most_far = 0, max_dist = 0;
    for(int i=0;i<n;i++){
        if(dist[i] > max_dist){
            most_far = i;
            max_dist = dist[i];
        }
    }

    // for(int i=0;i<n;i++){
    //     cout << i << ": " << dist[i] << endl;
    // }
    // cout << "most far: " << most_far << endl;

    dist[most_far] = 0;
    pq.push({0, most_far});
    for(int i=0;i<n;i++) kakutei[i] = false;
    while(!pq.empty()){
        pair<int, int> tmp = pq.top();
        pq.pop();

        kakutei[tmp.second] = true;
        dist[tmp.second] = tmp.first;

        for(int i=0;i<g[tmp.second].size();i++){
            if(!kakutei[g[tmp.second][i].first]){
                pq.push({tmp.first + g[tmp.second][i].second, g[tmp.second][i].first});
            }
        }
    }

    max_dist = 0;
    for(int i=0;i<n;i++){
        if(dist[i] > max_dist){
            most_far = i;
            max_dist = dist[i];
        }
    }

    cout << max_dist << endl;
    return 0;
}