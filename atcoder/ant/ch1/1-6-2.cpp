#include <bits/stdc++.h>
using namespace std;

// Ants
// 
// 長さL(cm)の竿の上をn匹の蟻が毎秒1cmで歩いている
// 蟻は竿の端に到着すると落下する
// ２匹の蟻は衝突すると反対に向きを変える
// すべての蟻が落ちるまでの最小時間と最大時間を求める
// (蟻ははじめどちらをむいているかはわからない)
// 
// 制約：
// 1<=L<=10^6
// 1<=n<=10^6
// 1<=xi<=L

// 衝突して向きを変える → すり抜けるに言い換える
// → 各蟻はa[i]秒 or L-a[i]秒後に落下(どちらかは最初の向き次第)

int n, L;
vector<int> a(1000001, 0);

int main(){
    // input1
    L = 10;
    n = 3;
    a = {2, 6, 7};
    // min = 4 (left, right, right)
    // max = 8 (right, right, right)
    
    int m = 0, M = 0;
    for(int i=0;i<n;i++){
        int tmp_m = (a[i] < L - a[i]) ? a[i] : (L - a[i]);
        int tmp_M = L - tmp_m;
        cout << tmp_m << " " << tmp_M << endl;

        if(tmp_m > m) m = tmp_m;
        if(tmp_M > M) M = tmp_M;
    }

    cout << "min = " << m << endl;
    cout << "max = " << M << endl;
}