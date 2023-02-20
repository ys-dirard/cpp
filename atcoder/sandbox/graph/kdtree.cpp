#include <bits/stdc++.h>
using namespace std;

static const int NIL = -1;

class Node{
public:
    int location;
    int p, l, r;
};

class Point{
public:
    int id, x, y;
    Point(){}
    Point(int id, int x, int y): id(id), x(x), y(y){}
    bool operator < (const Point &p) const {
        return id < p.id;
    }

    void print(){
        printf("%d\n", id);
    }
};

int n, x, y, q, sx, tx, sy, ty;
Point P[500009];
Node T[500009];
// P = {1, 3, 5, 6, 10, 13, 14, 16, 19, 21}
// -> T = {13, 5, 3, 1, 10, 6, 19, 16, 14, 21}
// T[t].location = {5, 2, 1, 0, 4, 3, 8, 7, 6, 9}
int np;

bool lessX(const Point &p1, const Point &p2){
    return p1.x < p2.x;
}

bool lessY(const Point &p1, const Point &p2){
    return p1.y < p2.y;
}

int makeKDTree(int l, int r, int depth){
    if(!(l < r)) return NIL;

    int mid = (l+r)/2;
    int t = np++;
    
    if(depth % 2 == 0){
        sort(P+l, P+r, lessX);
    }else{
        sort(P+l, P+r, lessY);
    }

    T[t].location = mid;
    T[t].l = makeKDTree(l, mid, depth+1);
    T[t].r = makeKDTree(mid+1, r, depth+1);

    return t;
}

void find(int v, int sx, int tx, int sy, int ty, int depth, vector<Point> &ans){
    int x = P[T[v].location].x;
    int y = P[T[v].location].y;

    if(sx <= x && x <= tx && sy <= y && y <= ty){
        ans.push_back(P[T[v].location]);
    }
    if(depth % 2 == 0){
        if(T[v].l != NIL && sx <= x) find(T[v].l, sx, tx, sy, ty, depth+1, ans);
        if(T[v].r != NIL && x <= tx) find(T[v].r, sx, tx, sy, ty, depth+1, ans);
    }else{
        if(T[v].l != NIL && sy <= y) find(T[v].l, sx, tx, sy, ty, depth+1, ans);
        if(T[v].r != NIL && y <= ty) find(T[v].r, sx, tx, sy, ty, depth+1, ans);
    }
}

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> x >> y;
        P[i].id = i;
        P[i].x = x;
        P[i].y = y;
        T[i].l = T[i].r = T[i].p = NIL;
    }

    np = 0;

    int root = makeKDTree(0, n, 0);

    cin >> q;
    vector<Point> ans;
    for(int i=0;i<q;i++){
        cin >> sx >> tx >> sy >> ty;
        ans.clear();
        find(root, sx, tx, sy, ty, 0, ans);
        sort(ans.begin(), ans.end());
        for(int j=0;j<ans.size();j++){
            ans[j].print();
        }
        cout << endl;
    }

    return 0;
}