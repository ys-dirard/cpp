#include <bits/stdc++.h>
using namespace std;

// 通常のセグメントツリー (1-origin)
// Range Minimum Query
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
			dat[pos] = min(dat[pos * 2], dat[pos * 2 + 1]);
		}
	}

	// クエリ 2 に対する処理
	// u は現在のセル番号、[a, b) はセルに対応する半開区間、[l, r) は求めたい半開区間
	T query(T l, T r, T a, T b, T u) {
		if (r <= a || b <= l) return 1000000000; // 一切含まれない場合
		if (l <= a && b <= r) return dat[u]; // 完全に含まれる場合
		T m = (a + b) / 2;
		T AnswerL = query(l, r, a, m, u * 2);
		T AnswerR = query(l, r, m, b, u * 2 + 1);
		return min(AnswerL, AnswerR);
	}
};

int N, L, R, X[100009];
int dp[100009];
SegmentTree<int> Z;
 
int main() {
	// 入力
	cin >> N >> L >> R;
	for (int i = 1; i <= N; i++) cin >> X[i];
 
	// セグメント木の準備
	Z.init(N);
	dp[1] = 0;
	Z.update(1, 0);
 
	// 動的計画法
	for (int i = 2; i <= N; i++) {
		int posL = lower_bound(X + 1, X + N + 1, X[i] - R) - X;
		int posR = lower_bound(X + 1, X + N + 1, X[i] - L + 1) - X - 1;
		dp[i] = Z.query(posL, posR + 1, 1, Z.siz + 1, 1) + 1;
		Z.update(i, dp[i]);
	}
 
	// 答えを出力
	cout << dp[N] << endl;
	return 0;
}