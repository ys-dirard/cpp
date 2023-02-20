#include <bits/stdc++.h>
using namespace std;
#define ll long long

// マンハッタン距離について
// 点(x, y)を45°回転して√2倍した座標を(X, Y)とすると
// (X, Y) = (x+y, x-y)となる。
// 
// |x| = max(-x, x)
// max(a, b) + max(c, d) = max(a+c, a+d, b+c, b+d)
// max(a, b, -b, -a) = max(|a|, |b|)
// を使うと
// 
// d_ij = |x_j - x_i| + |y_j - y_i|
//      = max(x_j - x_i, x_i - x_j) + max(y_j - y_i, y_i - y_j)
//      = max((x_j - x_i) + (y_j - y_i), (x_j - x_i) + (y_i - y_j), (x_i - x_j) + (y_j - y_i), (x_i - x_j) + (y_i - y_j))
//      = max((x_j + y_j) - (x_i + y_i), (x_j - y_j) - (x_i - y_i), (x_i - y_i) - (x_j - y_j), (x_i + y_i) - (y_j + y_j))
//      = max(X_j - X_i, Y_j - Y_i, Y_i - Y_j, X_i - X_j)
//      = max(|X_j - X_i|, |Y_j - Y_i|)
//
// よってマンハッタン距離の最大は
// max_(i<j) (d_ij) 
//   = max_(i<j) (max(|X_j - X_i|, |Y_j - Y_i|)) 
//   = max(max(X) - min(X), max(Y) - min(Y))
// となる。

// 今回みたいに一点が固定されてクエリがQ個与えられるような状況だと、
// 与えられた点に対して max(|X_i - X_fix|, |Y_i - Y_fix|) を考える。
// これは、X, Y を事前にソートしておいて
// max(|X_min - X_fix|, |Y_min - Y_fix|, |X_max - X_fix|, |Y_max - Y_fix|)
// で求めることができる (O(1))

// マンハッタン距離の最小について (O(N log N))
// 準備：
// l:     現在までの点で l 以下のマンハッタン距離をもつ二点は無いような中で最大の値
// S:     頂点の (Y, X) を入れるset、二分探索のため座標を反転させている
// P_in:  X座標が小さい順に出てくる (X, Y) を持つpriority_queue、Sに入れる頂点を管理
// P_out: X座標が小さい順に出てくる (X, Y) を持つpriority_queue、Sから消す頂点を管理
// 
// algorithm (O(N log N)):
// 1. 45°回転 ＋ 座標の√2倍 ((x, y) -> (X, Y))
// 2. P_in から頂点Aを取り出す
// 3. P_out の top(頂点B) とAのX座標を比較
//    l より離れているならBをSから消去
//    l 以下になるか P_out が空になるまで 4. を繰り返す
// 4. S上で二分探索してマイナス方向とプラス方向で最もY座標が近い頂点をそれぞれ取る
//    そして、Aとのマンハッタン距離を計算して小さいほうを m とする
//    m が l 以下なら l = m - 1 で更新する
// 5. S と P_out に A を入れる
// 6. P_in が空なら終了し、l + 1 を返す
//    空でないなら 2. に戻る
// 
// お気持ち：
// マンハッタン距離は max(|X_j - X_i|, |Y_j - Y_i|) と書ける
// つまり、マンハッタン距離が l より大きい ⇔ |X_j - X_i| > l or |Y_j - Y_i| > l
// |X_j - X_i| > l を満たすものは 3. で除去され、残りは |X_j - X_i| ≤ l を満たす
// 4. では l の値を更新してギリギリ |X_j - X_i| > l or |Y_j - Y_i| > l を満たすようにする
// こうして得られた l は全ての (i, j) において |X_j - X_i| > l or |Y_j - Y_i| > l を満たす
// 最大の l なので、l = L_min - 1を満たす！

ll N, Q;
ll x[100009], y[100009], q[100009];
ll X[100009], Y[100009];
ll X_min = (1<<30), Y_min = (1<<30), X_max = -(1<<30), Y_max = -(1<<30);

int main(){
    cin >> N >> Q;
    for(int i=1;i<=N;i++){
        cin >> x[i] >> y[i];
        X[i] = (x[i] + y[i]);
        Y[i] = (x[i] - y[i]);
        if(X_min > X[i]) X_min = X[i];
        if(Y_min > Y[i]) Y_min = Y[i];
        if(X_max < X[i]) X_max = X[i];
        if(Y_max < Y[i]) Y_max = Y[i];
    }
    for(int i=1;i<=Q;i++){
        cin >> q[i];
    }

    for(int i=1;i<=Q;i++){
        ll ans = max({abs(X[q[i]] - X_min), 
                      abs(Y[q[i]] - Y_min), 
                      abs(X[q[i]] - X_max), 
                      abs(Y[q[i]] - Y_max)});
        cout << ans << endl;
    }
    return 0;
}