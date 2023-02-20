#include <bits/stdc++.h>
using namespace std;
#define PI 3.1415926535

class Point{
public:
    double x, y;
    Point(double x=0, double y=0): x(x), y(y) {}
};

double angle(Point o, Point a){
    double dx = a.x - o.x;
    double dy = a.y - o.y;

    if(dx==0){
        double agl = (dy>0)?90.0:270.0;
        return agl;
    }else{
        double agl = atan(dy / dx) * 180.0 / PI;
        if(agl < 0 && dx > 0) agl += 360.0;
        else if(dx < 0) agl += 180.0;
        return agl;
    }
}

int N;
double x[2009], y[2009];
Point p[2009];

int main(){
    cin >> N;
    for(int i=1;i<=N;i++){
        cin >> x[i] >> y[i];
        p[i] = Point(x[i], y[i]);
    }

    double ans = 0;
    for(int i=1;i<=N;i++){
        Point m = p[i];
        vector<double> angles;
        for(int j=1;j<=N;j++){
            if(j==i) continue;
            double agl = angle(m, p[j]);
            angles.push_back(agl);
        }

        sort(angles.begin(), angles.end());
        for(int j=1;j<=N;j++){
            if(j==i) continue;
            double agl = angle(m, p[j]);
            double target = (agl - 180.0 > 0)?(agl - 180.0):(agl + 180.0);
            int pos = lower_bound(angles.begin(), angles.end(), target) - angles.begin();
            // cout << target << " " << angles[pos] << " " << agl-angles[pos] << endl;
            if(pos==0 || pos==angles.size()){
                ans = max(ans, min(abs(agl-angles[0]), 360.0 - abs(agl-angles[0])));
                ans = max(ans, min(abs(agl-angles[angles.size()-1]), 360.0 - abs(agl-angles[angles.size()-1])));
            }else{
                ans = max(ans, min(abs(agl-angles[pos]), 360.0 - abs(agl-angles[pos])));
                ans = max(ans, min(abs(agl-angles[pos-1]), 360.0 - abs(agl-angles[pos-1])));
            }
            // cout << ans << endl;
        }
    }

    cout << fixed << setprecision(15) << ans << endl;
    return 0;
}