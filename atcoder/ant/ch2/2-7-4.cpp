#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// millionaire

// はじめxドル持っており、Mラウンドにわたりかけをする
// 毎ラウンド、持っているドルを好きなだけ掛けられる
// 書ける額は小数でもよい、また0$でも全額でもよい
// 各ラウンドは確率Pで勝ち、勝てば掛けた額が倍になって得られ、
// 負ければ失われる
// 最後に$1000000以上持っていれば持ち帰れる
// 最善の戦略を取ったときに持ち帰れる確率は？

// M=1 -> x<500000なら0, 500000<=x<1000000ならp, x=1000000なら1である
// M=2 -> x<250000なら0, 250000<=x<500000ならp^2, 500000<=x<750000ならp^2+p(1-p),750000<=x<1000000ならp^2+2*p(1-p), x=1000000なら1である
// Mについて、2^M+1通りを考えればよい

// input
// M=1, P=0.5, X=500000
// output
// 0.500000

// input
// M=3, P=0.75, X=600000
// output
// 0.843750

const int MAX_M = 15;

int M;
double P, X;
double dp[2][((1<<MAX_M)+1)];

double solve(int M, double P, double X){
    int n = (1<<M);

    double *prev = dp[0];
    double *nex = dp[1];
    memset(prev, 0, sizeof(double) * (n+1));
    prev[n] = 1.0;

    for(int r=0;r<M;r++){
        for(int i=0;i<=n;i++){
            int jub = min(i, n-i);
            double t = 0.0;
            for(int j=0;j<=jub;j++){
                t = max(t, P*prev[i+j]+(1-P)*prev[i-j]);
            }
            nex[i] = t;
        }
        swap(prev, nex);
    }

    int i = (ll)X * n / 1000000;

    return prev[i];
}

int main(){
    cin >> M >> P >> X;

    double ans = solve(M, P, X);
    cout << fixed << setprecision(15) << ans << endl;
    return 0;
}