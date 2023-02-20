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
    return a.x * b.y - a.y * b.x;
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

// 反射(直線(Segment)に対し、点Pと対称な点の座標を返す)
Point reflection(Segment s, Point p){
    return p + (projection(s, p) - p) * 2.0;
}

// 2点間の距離
double get_distance(Point p1, Point p2){
    return (p1 - p2).abs();
}

// 点と直線の距離
double get_distance(Line l, Point p){
    return abs(cross(l.p2 - l.p1, p - l.p1)) / (l.p2 - l.p1).abs();
}

// 点と線分の距離
double get_distance_SP(Segment s, Point p){
    if( dot(s.p2 - s.p1, p - s.p1) < 0.0) return (p - s.p1).abs();
    if( dot(s.p1 - s.p2, p - s.p2) < 0.0) return (p - s.p2).abs();
    return get_distance(s, p);
}

static const int COUNTER_CLOCKWISE = 1;
static const int CLOCKWISE = -1;
static const int ONLINE_BACK = 2;
static const int ONLINE_FRONT = -1;
static const int ON_SEGMENT = 0;

// counter clockwise(p0, p1にたいしてp2がどの位置にあるか)
int ccw(Point p0, Point p1, Point p2){
    Vector a = p1 - p0;
    Vector b = p2 - p0;
    if(cross(a, b) > EPS) return COUNTER_CLOCKWISE;
    if(cross(a, b) < -EPS) return CLOCKWISE;
    if(dot(a, b) < -EPS) return ONLINE_BACK;
    if(a.norm() < b.norm()) return ONLINE_FRONT;

    return ON_SEGMENT;
}

// 線分と線分が交わるか？(短点を指定)
bool intersect(Point p1, Point p2, Point p3, Point p4){
    return (ccw(p1, p2, p3) * ccw(p1, p2, p4) <= 0 && ccw(p3, p4, p1) * ccw(p3, p4, p2) <= 0);
}

// 線分と線分が交わるか？
bool intersect(Segment s1, Segment s2){
    return intersect(s1.p1, s1.p2, s2.p1, s2.p2);
}

// 円と直線が交点を持つか？
bool intersect(Circle c, Line l){
    return get_distance(l, c.c) <= c.r;
}

// 線分と線分の距離
double get_distance_SS(Segment s1, Segment s2){
    if(intersect(s1, s2)) return 0.0;
    return min({get_distance(s1, s2.p1), 
                get_distance(s1, s2.p2), 
                get_distance(s2, s1.p1), 
                get_distance(s2, s1.p2)}
                );
}

// 線分の交点の座標を返す(交わることが確定している場合のみ使用可能)
Point get_cross_point(Segment s1, Segment s2){
    Vector base = s1.p2 - s1.p1;
    double d1 = abs(cross(base, s2.p1 - s1.p1));
    double d2 = abs(cross(base, s2.p2 - s1.p1));

    double t = d1 / (d1 + d2);

    Point x = s2.p1 + (s2.p2 - s2.p1) * t;
    return x;
}

// 円と線分の交点を返す
vector<Point> get_cross_point_CL(Circle c, Line l){
    vector<Point> vec;
    double d = get_distance(l, c.c);
    if(d > c.r) return vec;

    double t = sqrt(c.r * c.r - d * d);
    Vector e = (l.p2 - l.p1) / (l.p2 - l.p1).abs();

    Point H = projection(l, c.c);

    vec.push_back(H + e * t);
    vec.push_back(H - e * t);

    sort(vec.begin(), vec.end());
    return vec;
}

int main(){
    int q, cx, cy, r, x0, y0, x2, y2;
    cin >> cx >> cy >> r;
    Circle c(Point(cx, cy), r);

    cout << fixed << setprecision(15);
    cin >> q;
    for(int i=0;i<q;i++){
        cin >> x0 >> y0 >> x2 >> y2;
        Line l(Point(x0, y0), Point(x2, y2));
        vector<Point> ans = get_cross_point_CL(c, l);
        for(int i=0;i<ans.size();i++){
            if(i) cout << " ";
            cout << ans[i].x << " " << ans[i].y;
        }
        cout << endl;
    }
    return 0;
}