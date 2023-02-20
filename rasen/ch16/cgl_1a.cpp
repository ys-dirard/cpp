#include <bits/stdc++.h>
using namespace std;

#define EPS (1e-10)
#define equals(a, b) (fabs((a) - (b)) < EPS)

class Point{
    public:
    double x, y;

    Point(double x = 0.0, double y = 0.0): x(x), y(y){}

    Point operator + (Point p){ return Point(x + p.x, y + p.y);}
    Point operator - (Point p){ return Point(x - p.x, y - p.y);}
    Point operator * (double a){ return Point(a * x, a * y);}
    Point operator / (double a){ return Point(x / a, y / a);}

    double norm(){
        return x * x + y * y;
    }

    double abs(){
        return sqrt(norm());
    }

    // xを見て、同じならyも観る
    bool operator < (const Point &p) const{
        return x != p.x ? x < p.x : y < p.y;
    }

    bool operator == (const Point &p) const{
        return fabs(x - p.x) < EPS && fabs(y - p.y) < EPS;
    }
};

typedef Point Vector;

// 線分(通る2点で表す)
class Segment{
    public:
    Point p1, p2;
    Segment(Point p1 = Point(0.0, 0.0), Point p2 = Point(0.0, 0.0)): p1(p1), p2(p2){}
};

typedef Segment Line;

class Circle{
    public:
    Point c;
    double r;
    Circle(Point c = Point(0, 0), double r = 0.0): c(c), r(r){}
};

typedef vector<Point> Polygon;

double dot(Vector a, Vector b){
    return a.x * b.x + a.y * b.y;
}

double cross(Vector a, Vector b){
    return a.x * b.y + a.y * b.x;
}

// 直交判定
bool is_orthogonal(Vector a, Vector b){
    return equals(dot(a, b), 0.0);
}

bool is_orthogonal(Point a1, Point a2, Point b1, Point b2){
    return is_orthogonal(a1 - a2, b1 - b2);
}

bool is_orthogonal(Segment s1, Segment s2){
    return equals(dot(s1.p2 - s1.p1, s2.p2 - s2.p1), 0.0);
}

// 平行判定
bool is_Parallel(Vector a, Vector b){
    return equals(cross(a, b), 0.0);
}

bool is_Parallel(Point a1, Point a2, Point b1, Point b2){
    return is_Parallel(a1 - a2, b1 - b2);
}

bool is_Parallel(Segment s1, Segment s2){
    return equals(cross(s1.p2 - s1.p1, s2.p2 - s2.p1), 0.0);
}

// 射影(点から直線におろした推薦の足の座標)
Point projection(Segment s, Point p){
    Vector base = s.p2 - s.p1;
    double r = dot(p - s.p1, base) / base.norm();
    return s.p1 + base * r;
}

int main(){
    int q, x, y, x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    Segment s(Point(x1, y1), Point(x2, y2));
    
    cin >> q;
    cout << fixed << setprecision(15);
    for(int i=0;i<q;i++){
        cin >> x >> y;
        Point p = Point(x, y);
        Point proj = projection(s, p);
        cout << proj.x << " " << proj.y << endl;
    }
    return 0;
}