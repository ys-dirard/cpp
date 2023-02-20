#include <bits/stdc++.h>
using namespace std;
#define ll long long

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
		dat = vector<T>(siz*2, -1000000000);
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

int W, N;
ll dp[509][10009];
SegmentTree<ll> st;
ll L[509], R[509], V[509];

int main(){
    cin >> W >> N;
    for(int i=1;i<=N;i++){
        cin >> L[i] >> R[i] >> V[i];
    }

    // for(int i=0;i<=N;i++){
    //     for(int j=0;j<=W;j++){
    //         dp[i][j] = -(1<<30);
    //     }
    // }

    st.init(W);
    for(int i=1;i<=N;i++){
        for(int j=W;j>=1;j--){
            ll tmp = -1000000000, l, r;
            if(j-L[i] < 0) continue;
            else r = j-L[i]+1;
            if(j-R[i] < 0){
                l = 0;
            }else{
                l = j-R[i];
            }

            if(l==0){
                tmp = max(tmp, V[i]);
                tmp = max(tmp, st.query(1, r, 1, st.siz+1, 1) + V[i]);
            }else{
                tmp = max(tmp, st.query(l, r, 1, st.siz+1, 1) + V[i]);
            }
            
            if(tmp >= 0 && st.query(j, j+1, 1, st.siz+1, 1) < tmp){
                st.update(j, tmp);
            }
        }
    }

    // for(int i=1;i<=W;i++){
    //     cout << st.query(i, i+1, 1, st.siz+1, 1) << endl;
    // }

    ll ans = st.query(W, W+1, 1, st.siz+1, 1);
    if(ans > 0) cout << ans << endl;
    else cout << -1 << endl;
    return 0;
}