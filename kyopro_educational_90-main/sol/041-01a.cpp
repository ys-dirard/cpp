#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Point {
	long long px, py;
};

Point operator+(const Point& a1, const Point& a2) {
	return Point{ a1.px + a2.px, a1.py + a2.py };
}

Point operator-(const Point& a1, const Point& a2) {
	return Point{ a1.px - a2.px, a1.py - a2.py };
}

bool operator<(const Point& a1, const Point& a2) {
	if (a1.px < a2.px) return true;
	if (a1.px > a2.px) return false;
	if (a1.py < a2.py) return true;
	return false;
}

// �_ p1 �� p2 �̊O�ς����߂�
long long crs(Point p1, Point p2) {
	return p1.px * p2.py - p1.py * p2.px;
}

long long N;
long long ly[100009], ry[100009];
Point G[100009];
vector<Point> V;

int main() {
	// Step #1. ����
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> G[i].px >> G[i].py;
	sort(G + 1, G + N + 1);
	V.push_back(G[1]);
	V.push_back(G[2]);
	V.push_back(G[3]);

	// Step #2. �e x �ɑ΂��鉺�[�Ə�[�����߂�
	for (int i = 0; i <= 1000; i++) { ly[i] = (1LL << 30); ry[i] = -(1LL << 30); }
	for (int i = 0; i < V.size(); i++) {
		long long ax = V[(i + 0) % V.size()].px, ay = V[(i + 0) % V.size()].py;
		long long bx = V[(i + 1) % V.size()].px, by = V[(i + 1) % V.size()].py;
		if (ax > bx) { swap(ax, bx); swap(ay, by); }
		if (ax == bx) {
			ly[ax] = min({ ly[ax], ay, by });
			ry[ax] = max({ ry[ax], ay, by });
		}
		else {
			for (int i = ax; i <= bx; i++) {
				long long v1 = (ay * (bx - i) + by * (i - ax)) / (bx - ax);
				long long v2 = (ay * (bx - i) + by * (i - ax) + (bx - ax) - 1LL) / (bx - ax);
				ly[i] = min(ly[i], v2);
				ry[i] = max(ry[i], v1);
			}
		}
	}

	// Step #3. ���������߂�
	long long Answer = 0;
	for (int i = 0; i <= 1000; i++) {
		if (ly[i] <= ry[i]) Answer += (ry[i] - ly[i] + 1);
	}
	cout << Answer - N << endl;
	return 0;
}