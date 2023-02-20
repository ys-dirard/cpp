#include <bits/stdc++.h>
using namespace std;

int main(){
    int W, H, x, y;
    cin >> W >> H >> x >> y;
    double mx = 1.0 * W / 2;
    double my = 1.0 * H / 2;
    double eps = 1e-10;

    double area = 1.0 * W * H / 2;
    bool multi = (abs(mx - x) < eps) && (abs(my - y) < eps);

    cout << fixed << setprecision(15) << area << " " << multi << endl;
}