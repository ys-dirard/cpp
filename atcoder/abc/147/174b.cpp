#include <bits/stdc++.h>
using namespace std;

struct point{
    double x, y;
};

double dist(point a, point b){
    return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

int N;
double D, x[200009], y[200009];
point p[200009];

int main(){
    cin >> N >> D;
    int ans = 0;
    for(int i=1;i<=N;i++){
        cin >> x[i] >> y[i];
        p[i] = point{x[i], y[i]};

        double d = dist(p[i], point{0, 0});
        ans += (d <= D);
    }
    cout << ans << endl;
    return 0;
}