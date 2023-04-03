#include <bits/stdc++.h>
using namespace std;

/* #region modint */
constexpr int mod = 1000000007;
class mint {
public:
    long long x;
    constexpr mint(long long x=0) : x((x%mod+mod)%mod) {}
    constexpr mint operator-() const { 
      return mint(-x);
    }
    constexpr mint& operator+=(const mint& a) {
        if ((x += a.x) >= mod) x -= mod;
        return *this;
    }
    constexpr mint& operator-=(const mint& a) {
        if ((x += mod-a.x) >= mod) x -= mod;
        return *this;
    }
    constexpr mint& operator*=(const mint& a) {
        (x *= a.x) %= mod;
        return *this;
    }
    constexpr mint operator+(const mint& a) const {
        mint res(*this);
        return res+=a;
    }
    constexpr mint operator-(const mint& a) const {
        mint res(*this);
        return res-=a;
    }
    constexpr mint operator*(const mint& a) const {
        mint res(*this);
        return res*=a;
    }
    constexpr mint pow(long long t) const {
        if (!t) return 1;
        mint a = pow(t>>1);
        a *= a;
        if (t&1) a *= *this;
        return a;
    }

    // for prime mod
    constexpr mint inv() const {
        return pow(mod-2);
    }
    constexpr mint& operator/=(const mint& a) {
        return (*this) *= a.inv();
    }
    constexpr mint operator/(const mint& a) const {
        mint res(*this);
        return res/=a;
    }
};
ostream& operator<<(ostream& os, const mint& m){
    os << m.x;
    return os;
}
/* #endregion */

// 通常のセグメントツリー (1-origin)
// Range Sum Query
template <typename T>
class SegmentTree {
public:
	vector<T> dat;
    int siz = 1;

	// 要素 dat の初期化を行う（最初は全部ゼロ）
	void init(int N) {
		siz = 1;
		while (siz <= N) siz *= 2;
		dat = vector<T>(siz*2, 0);
	}

	// pos番目の値を更新
	void update(int pos, T x) {
		pos = pos + siz - 1;
		dat[pos] = x;
		while (pos >= 2) {
			pos /= 2;
			dat[pos] = dat[pos * 2] + dat[pos * 2 + 1];
		}
	}

	// 区間[l, r) 内の合計を返す
	// u は現在のセル番号、[a, b) はセルに対応する半開区間、[l, r) は求めたい半開区間
	T query(int l, int r, int a, int b, int u) {
		if (r <= a || b <= l) return 0; // 一切含まれない場合
		if (l <= a && b <= r) return dat[u]; // 完全に含まれる場合
		int m = (a + b) / 2;
		T AnswerL = query(l, r, a, m, u * 2);
		T AnswerR = query(l, r, m, b, u * 2 + 1);
		return AnswerL + AnswerR;
	}
};

int N, K;
int a[109];
mint dp[109][100009];
SegmentTree<mint> z;

int main(){
    cin >> N >> K;
    for(int i=1;i<=N;i++){
        cin >> a[i];
    }
    z.init(K+1);

    dp[0][0] = 1;
    z.update(1, 1);
    for(int i=1;i<=N;i++){
        for(int j=0;j<=K;j++){
            int l = max(0, j-a[i]);

            dp[i][j] = z.query(l+1, j+2, 1, K+2, 1);
        }

        for(int j=0;j<=K;j++){
            z.update(j+1, dp[i][j]);
        }
    }
    cout << dp[N][K] << endl;
    return 0;
}