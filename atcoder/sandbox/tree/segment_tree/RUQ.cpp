#include <bits/stdc++.h>
using namespace std;

// 遅延評価セグメントツリー (1-origin)
// Range Updated Query (+ Range Maximum Query)
// 区間更新、区間加算等の区間に対する更新が O(log N) でできる
// ・Range Minimum Query への変更方法
//   1. function fx の return を変更する
//   2. dat、lazy の初期値を INF にする？
// ・区間更新への変更方法：
//   1. update_ 内の lazy[k] = x -> lazy[k] += x に変更 
template <typename T>
class SegmentTree {
private:
    function<T(T, T)> fx = [](T x1, T x2) -> T {return max(x1, x2);};
	vector<T> dat;
    vector<T> lazy;
    T siz = 1;
    const T e = 0; // 初期化用1
    const T INF = numeric_limits<T>::max(); // 初期化用2
    
    void push(int k) {
        if(lazy[k] == e) return; // 更新するものがなければreturn
		if (k < siz) { // 葉でなければ子に伝播
			lazy[k * 2] = fx(lazy[k * 2], lazy[k]);
			lazy[k * 2 + 1] = fx(lazy[k * 2 + 1], lazy[k]);
		}
		dat[k] = fx(dat[k], lazy[k]);
		lazy[k] = e;
	}
	void update_(int a, int b, int x, int k, int l, int r) {
		push(k);
		if (r <= a || b <= l) return;
		if (a <= l && r <= b) {
			lazy[k] = x; // 区間加算ならここを+=にすればよい?
			push(k);
			return;
		}
		update_(a, b, x, k * 2, l, (l + r) >> 1);
		update_(a, b, x, k * 2 + 1, (l + r) >> 1, r);
		dat[k] = fx(dat[k * 2], dat[k * 2 + 1]);
	}
	T query_(int a, int b, int k, int l, int r) {
		push(k);
		if (r <= a || b <= l) return e;
		if (a <= l && r <= b) return dat[k];
		T lc = query_(a, b, k * 2, l, (l + r) >> 1);
		T rc = query_(a, b, k * 2 + 1, (l + r) >> 1, r);
		return fx(lc, rc);
	}
    // Range Minimum Queryなら fx を min にして dat[k] > x を dat[k] < x にするとよい
    int find_rightest_(int a, int b, T x, int k, int l, int r){
        push(k);
        if (dat[k] < x || r <= a || b <= l) {  // 自分の値がxより小さい or [a,b)が[l,r)の範囲外ならreturn a-1
            return a-1;
        } else if (k >= siz) {  // 自分が葉ならその位置をreturn
            return (k - siz);
        } else {
            int vr = find_rightest_(a, b, x, 2 * k + 1, (l + r) >> 1, r);
            if (vr != a-1) {  // 右の部分木を見て a-1 以外ならreturn
                return vr;
            } else {  // 左の部分木を見て値をreturn
                return find_rightest_(a, b, x, 2 * k, l, (l + r) >> 1);
            }
        }
    }
    int find_leftest_(int a, int b, T x, int k, int l, int r){
        push(k);
        if (dat[k] < x || r <= a || b <= l) {  // 自分の値がxより小さい or [a,b)が[l,r)の範囲外ならreturn b
            return b;
        } else if (k >= siz) {  // 自分が葉ならその位置をreturn
            return (k - siz);
        } else {
            int vl = find_leftest_(a, b, x, 2 * k, l, (l + r) >> 1);
            if (vl != b) {  // 左の部分木を見て b 以外ならreturn
                return vl;
            } else {  // 右の部分木を見て値をreturn
                return find_leftest_(a, b, x, 2 * k + 1, (l + r) >> 1, r);
            }
        }
    }

public:
	// 要素 dat の初期化を行う（最初は全部ゼロ）
	void init(T N) {
		siz = 1;
		while (siz < N) siz *= 2;
		dat = vector<T>(siz*2, e);
		lazy = vector<T>(siz*2, e);
	}

	// [l, r) の値を更新
	void update(int l, int r, int x) {
		update_(l, r, x, 1, 0, siz);
	}

    // [l, r) の最大値を取得
	T query(int l, int r) {
		return query_(l, r, 1, 0, siz);
	}

    // [a, b) で x 以上の要素を持つ最右位置を求める、見つからなかったら a-1 を返す (O(log N))
    int find_rightest(int a, int b, T x){
        return find_rightest_(a, b, x, 1, 0, siz);
    }

    // [a, b) で x 以上の要素を持つ最左位置を求める、見つからなかったら b を返す (O(log N))
    int find_leftest(int a, int b, T x){
        return find_leftest_(a, b, x, 1, 0, siz);
    }
};

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int W, N;
	cin >> W >> N;
	SegmentTree<int> seg;
    seg.init(W+1);
	for (int i = 0; i < N; ++i) {
		int L, R;
		cin >> L >> R;
		int height = seg.query(L, R+1) + 1;
		seg.update(L, R+1, height);
		cout << height << '\n';
	}
    
    // // [1, W+1) 内で 2 以上となる中で最左のインデックスを返す
    // cout << seg.find_leftest(1, W+1, 2) << endl;
	
    return 0;
}