#include <bits/stdc++.h>
using namespace std;

// Physics Experiment (POJ No.3684)

// N個の半径Rセンチメートルのボールがある
// 上空Hメートルのところに筒を用意して
// ボールを縦にいれる
// (したからi番目のボールは下端がH+2Ri)
// 1秒ごとにボールを一つずつ落下させる
// 衝突は男性衝突とする
// 実験開始後T秒経過時点での各ボールの下端の高さを求める
// 重力加速度は10m/s^2とする

// ボールが1つの場合
// 床に衝突する時刻はt = sqrt(2H/g)であり
// kt<=Tとなる最大のkに対して
// y = H - 1/2 g(T - kt)^2 (k is even)
//   = H - 1/2 g(kt + t - T)^2 (k is odd)
// となる

// R=0の場合
// 衝突=すり抜けると解釈できる

// R>0の場合
// R=0での結果に+2Riすればよい

// input
// N=1
// H=10
// R=10
// T=100
// output
// 4.95

// input
// N=2
// H=10
// R=10
// T=100
// output
// 4.95 10.20

int N, H, R, T;
const double g = 10.0;
double y[109];

double calc(int T){
    if(T<0) return H;
    double t = sqrt(2*H/g);
    int k = (int)(T/t);
    if(k % 2 == 0){
        double d = T - k*t;
        return H - g * d * d / 2;
    }else{
        double d = k*t + t - T;
        return H - g * d * d / 2;
    }
}

void solve(){
    for(int i=0;i<N;i++){
        y[i] = calc(T-i);
    }
    sort(y, y+N);
    for(int i=0;i<N;i++){
        if(i) cout << " ";
        cout << fixed << setprecision(2) << y[i] + 2*R*i/100.0;
    }
    cout << endl;
}

int main(){
    cin >> N >> H >> R >> T;

    solve();
    return 0;
}