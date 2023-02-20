#include <bits/stdc++.h>
using namespace std;
#define PI 3.1415926535

double T, L, X, Y, E[1009];
int Q;

int main(){
    cin >> T >> L >> X >> Y >> Q;
    for(int i=1;i<=Q;i++) cin >> E[i];

    cout << fixed << setprecision(10);

    for(int i=1;i<=Q;i++){
        double xt = 0;
        double yt = -sin(2*PI*E[i]/T)*L/2;
        double zt = (1 - cos(2*PI*E[i]/T))*L/2;
        double a = sqrt((X-xt)*(X-xt) + (Y-yt)*(Y-yt) + (zt)*(zt));
        double b = sqrt((X-xt)*(X-xt) + (Y-yt)*(Y-yt));
        double c = sqrt((zt)*(zt));

        // cout << "x: " << a << endl;
        // cout << "y: " << b << endl;
        // cout << "z: " << c << endl;
        // cout << "tmp: " << (x*x+y*y-z*z)/(2*x*y) << endl;
        
        // double ans = 180 * acos((a*a+b*b-c*c)/(2*a*b));
        double ans = acos(b/a) * 180 / PI;
        cout << ans << endl;
    }
    return 0;
}