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

// 円と円が交点を持つか？
bool intersect(Circle c1, Circle c2){
    double d = (c1.c - c2.c).abs();
    return d > (c1.r + c2.r) || d < abs(c1.r - c2.r);
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

// Vectorの偏角を返す
double arg(Vector p){
    return atan2(p.y, p.x);
}


// 極座標から直交座標のベクトル(点)に変換
Vector polar(double a, double r){
    return Point(cos(r) * a, sin(r) * a);
}

// 円と円の交点の座標を返す
vector<Point> get_cross_point(Circle c1, Circle c2){
    vector<Point> vec;
    if(intersect(c1, c2)) return vec;
    double d = (c1.c - c2.c).abs();
    double a = acos((c1.r * c1.r + d * d - c2.r * c2.r) / (2 * c1.r * d));
    double t = arg(c2.c - c1.c);
    vec.push_back(c1.c + polar(c1.r, t + a));
    vec.push_back(c1.c + polar(c1.r, t - a));
    sort(vec.begin(), vec.end());
    return vec;
}

// 点の内包(多角形)、0:外部, 1:辺上, 2:内部
// 点からx軸正の方向に伸ばした半直線が辺と奇数回交差すると内部、偶数回で外部
int contains(Polygon g, Point p){
    int n = g.size();
    bool x = false;

    for(int i=0;i<n;i++){
        Point a = g[i] - p, b = g[(i + 1) % n] - p;
        if(abs(cross(a, b)) < EPS && dot(a, b) < EPS) return 1;
        if(a.y > b.y) swap(a, b);
        if(a.y < EPS && EPS < b.y && cross(a, b) > EPS) x = !x;
    }
    return (x ? 2 : 0);
}

// 凸包(Andrewのアルゴリズム)
// 凸包の辺上の点を含める場合は!=CLOCKWISEを==COUNTER_CLOCKWISEにする
// 凸包の下側の要素から反時計回りに点を返す
Polygon andrew_scan(Polygon s){
    Polygon u, l;
    if(s.size() < 3) return s;

    sort(s.begin(), s.end());

    // 上側初期化
    u.push_back(s[0]);
    u.push_back(s[1]);
    
    // 下側初期化
    l.push_back(s[s.size() - 1]);
    l.push_back(s[s.size() - 2]);

    // 上側を求める
    for(int i=2;i<s.size();i++){
        for(int n=u.size();n>=2 && ccw(u[n-2], u[n-1], s[i]) != CLOCKWISE;n--){
            u.pop_back();
        }
        u.push_back(s[i]);
    }

    // 下側を求める
    for(int i=s.size()-3;i>=0;i--){
        for(int n=l.size();n>=2 && ccw(l[n-2], l[n-1], s[i]) != CLOCKWISE;n--){
            l.pop_back();
        }
        l.push_back(s[i]);
    }

    reverse(l.begin(), l.end());
    for(int i=u.size()-2;i>=1;i--){
        l.push_back(u[i]);
    }
    
    return l;
}

#define BOTTOM 0
#define LEFT 1
#define RIGHT 2
#define TOP 3

class EndPoint{
    public:
    Point p;
    int seg, st; // 入力線分のID, 端点の種類
    EndPoint(){};
    EndPoint(Point p, int seg, int st): p(p), seg(seg), st(st){}

    bool operator < (const EndPoint &ep) const{
        // y座標が小さい順に整列
        if(p.y == ep.p.y){
            return st < ep.st;
        }else{
            return p.y < ep.p.y;
        }
    }
};

// EndPoint EP[2 * 100000]; // 端点のリスト

// 線分交差問題：マンハッタン幾何
int manhattanIntersection(vector<Segment> S){
    int n = S.size();
    vector<EndPoint> EP(2*n);

    for(int i=0, k=0;i<n;i++){
        // 端点p1, p2が左下を基準に並ぶように調整
        if(S[i].p1.y == S[i].p2.y && S[i].p1.x > S[i].p2.x){
            swap(S[i].p1, S[i].p2);
        }else if(S[i].p1.y > S[i].p2.y){
            swap(S[i].p1, S[i].p2);
        }

        if(S[i].p1.y == S[i].p2.y){ // 水平成分を端点リストに追加
            EP[k++] = EndPoint(S[i].p1, i, LEFT);
            EP[k++] = EndPoint(S[i].p2, i, RIGHT);
        }else{ // 垂直成分を端点リストに累加
            EP[k++] = EndPoint(S[i].p1, i, BOTTOM);
            EP[k++] = EndPoint(S[i].p2, i, TOP);
        }
    }

    sort(EP.begin(), EP.end()); // 端点のy座標に関して昇順に整列

    set<int> BT; // 二分探索木
    BT.insert(1000000001); // 番兵を設置
    int cnt = 0;

    for(int i=0;i<2*n;i++){
        if(EP[i].st == TOP){
            BT.erase(EP[i].p.x); // 上端点を削除
        }else if(EP[i].st == BOTTOM){
            BT.insert(EP[i].p.x); // 下端点を追加
        }else if(EP[i].st == LEFT){
            set<int>::iterator b = BT.lower_bound(S[EP[i].seg].p1.x); // O(log n)
            set<int>::iterator e = BT.upper_bound(S[EP[i].seg].p2.x); // O(log n)
            cnt += distance(b, e); // bとeの距離(点の数)を加算、O(k)
        }
    }

    return cnt;
}

int main(){
    int n, x1, y1, x2, y2;
    cin >> n;
    vector<Segment> S;
    for(int i=0;i<n;i++){
        cin >> x1 >> y1 >> x2 >> y2;
        S.push_back(Segment(Point(x1, y1), Point(x2, y2)));
    }

    int num_cross_points = manhattanIntersection(S);
    cout << num_cross_points << endl;
    return 0;
}