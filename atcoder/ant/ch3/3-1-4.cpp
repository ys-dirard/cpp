#include <bits/stdc++.h>
using namespace std;

// 平均最大化

// 重さと価値がそれぞれw_i, v_iである品がNこある
// この中からちょうどk個選んだ時の単位重さ当たりの
// 価値の最大値を求める

// input
// n=3, k=2
// (w, v) = {(2, 2), (5, 3), (2, 1)}
// output
// 0.75 (0と2を選ぶ)

// C(x) = 単位重さ当たりの価値をx以上にできるか？
// 選び方の一例をSとする
// この時、単位重さ当たりの価値は(Σはi in S)
// Σv_i / Σw_i >= x
// Σ(v_i - w_i*x) >= 0

// もとの問題は貪欲法で解けないが、
// 変形後の式を考え,
// ソートしておき大きいほうから選ぶ貪欲法で解ける！

int n, k;
double w[10009], v[10009];
double wv[10009];

bool solve(double m){
    for(int i=0;i<n;i++){
        wv[i] = v[i] - w[i] * m;
    }
    sort(wv, wv+n);
    reverse(wv, wv+n);

    double ans = 0;
    for(int i=0;i<k;i++){
        ans += wv[i];
    }

    return ans >= 0;
}

// ok: 解が存在する範囲
// ng: 解が存在しない範囲
// 半開区間(ng, ok] or [ok, ng)を考える
// 解であるかどうかはsolve関数(別途用意)で判定
// -> mが解であればtrueを返す
double binary_search(double ok, double ng){
    double mid;
    while(abs(ok - ng) > 1e-5){
        mid = (ok + ng) / 2;

        if(solve(mid)){
            ok = mid;
        }else{
            ng = mid;
        }
    }
    return mid;
}

int main(){
    cin >> n >> k;
    for(int i=0;i<n;i++){
        cin >> w[i] >> v[i];
    }

    double ok = 0;
    double ng = 1e9;

    double ans = binary_search(ok, ng);
    cout << fixed << setprecision(2) << ans << endl;
    return 0;
}