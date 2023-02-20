#include <bits/stdc++.h>
using namespace std;
#define ll long long

// 巨大ナップザック

// 重さと価値がそれぞれwi, vi
// であるn個の品がある
// これらの品物を重さの総和が
// Wを超えないように選んだ時の
// 価値の総和の最小値を求めよ

// 通常のDP解法だとO(nW)よりTLE
// n<=40なので全探索でもO(2^40)でTLE
// 半分ならO(2^20)なので間に合う
// 半分から(w1, v1)の情報が得られたとすると
// もう片方から、w2<=W-w1の範囲から
// v2が最大になるように選べばよい

// 制約
// 1<=n<=40
// 1<=wi,vi<=10^15
// 1<=W<=10^15

// input
// n=4
// w={2,1,3,2}
// v={3,2,4,2}
// W=5
// output
// 7

const ll INF = 1LL<<60;

ll n, w[49], v[49], W;
// ll w1[1609], v1[1609];
pair<ll, ll> wv[1<<21];

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> w[i];
    }
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    cin >> W;

    int hn = n/2;
    // 前半半分の全列挙
    for(int i=0;i<(1<<hn);i++){
        ll sw = 0;
        ll sv = 0;
        for(int j=0;j<hn;j++){
            if((i >> j) & 1){
                sw += w[j];
                sv += v[j];
            }
        }
        wv[i] = {sw, sv};
    }

    // 無駄な要素を取り除く
    // m個が意味のあるものになる
    // 価値が大きくなるもののみを保存していく
    sort(wv, wv+(1<<hn));
    int m = 1;
    for(int i=1;i<(1<<hn);i++){
        if(wv[m-1].second < wv[i].second){
            wv[m++] = wv[i];
        }
    }

    // 後ろ半分
    ll res = 0;
    for(int i=0;i<(1<<(n-hn));i++){
        ll sw = 0;
        ll sv = 0;
        for(int j=0;j<(n-hn);j++){
            if((i>>j)&1){
                sw += w[hn+j];
                sv += v[hn+j];
            }
        }
        if(sw<=W){
            ll tv = (lower_bound(wv, wv+m, make_pair(W-sw, INF)) - 1)->second;
            res = max(res, sv+tv);
        }
    }

    cout << res << endl;
    return 0;
}