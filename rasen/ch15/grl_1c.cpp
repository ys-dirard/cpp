#include <bits/stdc++.h>
using namespace std;

const long long INF = (1LL<<32);

long long v, e, s, t, d;
int mat[109][109];
long long dist[109][109];

int main(){
    cin >> v >> e;
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            if(i!=j) dist[i][j] = INF;
            else dist[i][j] = 0;
        }
    }

    for(int i=0;i<e;i++){
        cin >> s >> t >> d;
        dist[s][t] = d;
    }

    for(int k=0;k<v;k++){
        for(int i=0;i<v;i++){
            if(dist[i][k] >= INF) continue;
            for(int j=0;j<v;j++){
                if(dist[k][j] >= INF) continue;
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }

    bool negative_flg = false;
    for(int i=0;i<v;i++) negative_flg = negative_flg || (dist[i][i] < 0);
    if(negative_flg){
        cout << "NEGATIVE CYCLE" << endl;
        return 0;
    }

    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            if(j) cout << " ";
            if(dist[i][j] >= INF) cout << "INF";
            else cout << dist[i][j];
        }
        cout << endl;
    }
    return 0;
}