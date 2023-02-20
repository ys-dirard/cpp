#include <bits/stdc++.h>
using namespace std;

// 期待値の線形性
// E[X + Y] = E[X] + E[Y]
// 
// i, j (i<j) に対して転倒する確率を P[i, j] とする (x_i > x_j)
// 求める期待値に対して各 i, j (i<j)の組は
// E[i, j] = 1 * P[i, j] = P[i, j] だけ貢献する
// E[転倒数] = E[{[1, 2], [1, 3], ..., [N-1, N]}] (i, j 全ての組の集合)
//           = E[1, 2] + E[1, 3] + E[N-1, N]
//           = P[1, 2] + P[1, 3] + P[N-1, N]
// となる、期待値の線形性は貢献度を計算する方法に似ている
// 期待値の線形性は独立な思考でなくても成立する
// 
// 各 E[i, j] は X_i, X_j について全探索すれば求められる
// E[i, j] = (X_i, X_jを選んだ中で転倒する組み合わせ数) / (|X_i|*|X_j|)

int N, L[109], R[109];
double E[109][109];

int main(){
    cin >> N;
    for(int i=1;i<=N;i++){
        cin >> L[i] >> R[i];
    }
    for(int i=1;i<=N-1;i++){
        for(int j=1;j<=N;j++){
            E[i][j] = 0;
        }
    }

    double ans = 0;
    // (i, j) loop
    for(int i=1;i<=N-1;i++){
        for(int j=i+1;j<=N;j++){
            // (X_i, X_j) loop
            for(int k=L[i];k<=R[i];k++){
                for(int l=L[j];l<=R[j];l++){
                    if(k>l) E[i][j] += 1;
                }
            }
            E[i][j] /= 1.0 * (R[i] - L[i] + 1) * (R[j] - L[j] + 1);
            ans += E[i][j];
        }
    }

    cout << fixed << setprecision(15) << ans << endl;
    return 0;
}