#include <bits/stdc++.h>
#include <cmath>
using namespace std;
#define p pair<double, double>

int n;
p s = {0, 0}, g = {100, 0};
const double pi = 3.141592653589793;

void koch(p l, p r, int cnt){
    if(cnt>n) return;
    p s = {(2*l.first+r.first)/3, (2*l.second+r.second)/3};
    p t = {(l.first+2*r.first)/3, (l.second+2*r.second)/3};
    p s2u = {
        (t.first - s.first)*cos(pi/3) - (t.second - s.second)*sin(pi/3),
        (t.first - s.first)*sin(pi/3) + (t.second - s.second)*cos(pi/3)
    };
    p u = {s.first + s2u.first, s.second + s2u.second};

    // if(l.first==0 && r.first==100) cout << l.first << " " << l.second << endl;
    koch(l, s, cnt+1);
    cout << s.first << " " << s.second << endl;
    koch(s,u, cnt+1);
    cout << u.first << " " << u.second << endl;
    koch(u, t, cnt+1);
    cout << t.first << " " << t.second << endl;
    koch(t, r, cnt+1);
    // if(l.first==0 && r.first==100) cout << r.first << " " << r.second << endl;
}

int main(){
    cin >> n;
    cout << fixed << setprecision(10);
    cout << s.first << " " << s.second << endl;
    koch(s, g, 1);
    cout << g.first << " " << g.second << endl;
    return 0;
}