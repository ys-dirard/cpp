#include <bits/stdc++.h>
using namespace std;

// greedy

// とりあえず今取れる中から最善の手を選択する！！！

struct point{
    double x, y;
};

double dist(point a, point b){
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

int N;
double X[1009], Y[1009];
point p[1009];
bool visited[1009];

int main(){
    cin >> N;
    for(int i=1;i<=N;i++){
        cin >> X[i] >> Y[i];
        p[i] = {X[i], Y[i]};
    }

    double d;
    int cnt = 1;
    int pos = 1;
    vector<int> v;
    v.push_back(1);
    while(cnt < N){
        d = (1<<30);
        int min_id = -1;
        for(int i=2;i<=N;i++){
            if(visited[i]) continue;
            if(dist(p[pos], p[i]) < d){
                d = dist(p[pos], p[i]);
                min_id = i;
            }
        }
        pos = min_id;
        visited[pos] = true;
        v.push_back(pos);
        cnt++;
    }
    v.push_back(1);

    for(int i=0;i<N+1;i++) cout << v[i] << endl;
    return 0;
}