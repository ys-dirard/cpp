#include <bits/stdc++.h>
using namespace std;

// Face The Right Way (POJ No.3276)
// 反転

// N頭の牛が並んでいる
// 各牛は前か後ろを向いている
// 農夫ジョンは自動牛回転機を購入する
// この機械は1回の操作でちょうど頭の
// 連続する牛の向きを反転できるが
// Kを購入時に指定する必要がある
// すべての牛を前向きにするための
// 操作の最小回数とKの値を求める

// input
// N=7
// BBFBFBB
// output
// K=3
// M=3
// (1~3, 3~5, 5~7の順に反転)

// 各K(1~N)操作の最小回数を求める
// 操作は順番によらないので前から処理すればよい
// →最悪でN-K+1回の操作が必要
// →O(NK(N-K+1))=O(N^3)

// f[i]=区間[i, i+K-1]を反転させたなら1、そうでなければ0
// とすると、牛iに注目している段階において、牛iの向きは
// Σ_(j=i-K+1)^(i-1) f[j]
// が奇数ならもとと逆向き、偶数ならもとと同じ向きである
// Σ_(j=(i+1)-K+1)^i f[j] = Σ_(j=i-K+1)^(i-1) f[j] + f[i] - f[i-K+1]
// (S[i] = S[i-1] + f[i] - f[i-K+1])
// なので、この和は毎回定数時間で更新可能
// これによりO(N^2)になる

int N;
int dir[5009]; // 0:F, 1:B

int f[5009]; // 区間[i, i+K-1]を反転させたかどうか

// Kを固定したときの最小操作回数を求める
// 解が存在しないなら-1
int calc(int K){
    memset(f, 0, sizeof(f));

    int res = 0;
    int sum = 0; // fの和

    for(int i=0;i+K<=N;i++){
        // 区間[i, i+K-1]に注目
        if((dir[i]+ sum) % 2 == 1){
            // 前を向かせる
            res++;
            f[i] = 1;
        }
        sum += f[i];
        if(i-K+1 >= 0){
            sum -= f[i-K+1];
        }
    }

    // 残りの牛が前を向いているかを確認
    for(int i=N-K+1;i<N;i++){
        if((dir[i]+sum)%2 == 1){
            // 解無し
            return -1;
        }
        if(i-K+1 >= 0){
            sum -= f[i-K+1];
        }
    }
    return res;
}

void solve(){
    int K=1, M=N;
    for(int k=1;k<=N;k++){
        int m = calc(k);
        if(m >= 0 && M > m){
            M = m;
            K = k;
        }
    }
    cout << K << " " << M << endl;
}

int main(){
    string s;
    cin >> N >> s;
    for(int i=0;i<N;i++){
        if(s[i]=='F'){
            dir[i] = 0;
        }else{
            dir[i] = 1;
        }
    }

    solve();
    return 0;
}