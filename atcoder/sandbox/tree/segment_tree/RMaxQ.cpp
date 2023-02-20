#include <bits/stdc++.h>
using namespace std;

// 通常のセグメントツリー (1-origin)
// posを0-originにするにはinitのwhileを<から<=(こっちはいらないかも？)とupdate内のpos = の-1をなくす
// Range Maximum Query
template <typename T>
class SegmentTree {
public:
	vector<T> dat;
    T siz = 1;

	// 要素 dat の初期化を行う（最初は全部ゼロ）
	void init(T N) {
		siz = 1;
		while (siz < N) siz *= 2;
		dat = vector<T>(siz*2, 0);
	}

	// クエリ 1 に対する処理
	void update(T pos, T x) {
		pos = pos + siz - 1;
		dat[pos] = x;
		while (pos >= 2) {
			pos /= 2;
			dat[pos] = max(dat[pos * 2], dat[pos * 2 + 1]);
		}
	}

	// クエリ 2 に対する処理
	// u は現在のセル番号、[a, b) はセルに対応する半開区間、[l, r) は求めたい半開区間
	T query(T l, T r, T a, T b, T u) {
		if (r <= a || b <= l) return -1000000000; // 一切含まれない場合
		if (l <= a && b <= r) return dat[u]; // 完全に含まれる場合
		T m = (a + b) / 2;
		T AnswerL = query(l, r, a, m, u * 2);
		T AnswerR = query(l, r, m, b, u * 2 + 1);
		return max(AnswerL, AnswerR);
	}
};

int N, Q;
int Query[100009], pos[100009], x[100009], l[100009], r[100009];
SegmentTree<int> Z;

int main() {
	// 入力
	cin >> N >> Q;
	for (int i = 1; i <= Q; i++) {
		cin >> Query[i];
		if (Query[i] == 1) cin >> pos[i] >> x[i];
		if (Query[i] == 2) cin >> l[i] >> r[i];
	}

	// クエリ処理
	Z.init(N);
	for (int i = 1; i <= Q; i++) {
		if (Query[i] == 1) {
			Z.update(pos[i], x[i]);
		}
		if (Query[i] == 2) {
			// 最初のセルに対応する半開区間は [1, siz + 1)
			int Answer = Z.query(l[i], r[i], 1, Z.siz + 1, 1);
			cout << Answer << endl;
		}
	}
	return 0;
}