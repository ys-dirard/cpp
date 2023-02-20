#include <bits/stdc++.h>
using namespace std;
#define PI 3.1415926535

// O(N^3)はTLE

class Point{
public:
    double x, y;
    Point(double x=0, double y=0): x(x), y(y) {}
};

double dist(Point a, Point b){
    return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

double mid_angle(Point a, Point b, Point c){
    double d1 = dist(a, b);
    double d2 = dist(b, c);
    double d3 = dist(c, a);
    // cout << d1 << " " << d2 << " " << d3 << endl;

    double cos_b = (d1*d1 + d2*d2 - d3*d3) / (2.0 * d1 * d2);
    // cout << cos_b << endl;
    return acos(cos_b) * 180 / PI;
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
    for(int i=1;i<=N-2;i++){
        for(int j=i+1;j<=N-1;j++){
            for(int k=j+1;k<=N;k++){
                double theta1 = mid_angle(p[i], p[j], p[k]);
                double theta2 = mid_angle(p[j], p[k], p[i]);
                ans = max({ans, theta1, theta2, 180 - (theta1 + theta2)});
                // cout << theta << endl;
            }
        }
    }

    cout << fixed << setprecision(15) << ans << endl;
    return 0;
}