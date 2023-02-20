#include <bits/stdc++.h>
using namespace std;

// くじ引き
// 
// 数字が書かれた紙がn枚ある
// 紙を取り出し、元に戻すを4回行う
// 4回の合計がm枚になれば勝ち
// 
// 紙に書かれている数を
// k1, k2, ..., kn
// とするとき、勝てる可能性があるかを判定する
// 
// 制約：
// 1<=n<=50
// 1<=m<=10^8
// 1<=ki<=10^8

// 愚直にやるとO(n^4)なので1<=n<=50であればOK！
// 1<=n<=1000ならどうする？
// 半分全列挙でO(n^2 log n)で解ける
// → 二回までのパターンを出しておいて、residual = m - val(n^2回までの値)が2回までの値に存在するか？を判定

int n, m;
vector<int> k(51, 0);

int main(){
    // input1
    n = 3;
    m = 10; 
    k = {1, 3, 5};
    // Yes

    // input2
    n = 3;
    m = 9; 
    k = {1, 3, 5};
    // No

    // cout << k[0] << k[1] << k[2] << k[3] << endl;

    vector<int> lst; // ２回までで可能性があるものリスト
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            lst.push_back(k[i]+k[j]);
        }
    }
    sort(lst.begin(), lst.end());

    // 半分全列挙
    bool flg = false;
    for(int i=0;i<lst.size();i++){
        int pos = lower_bound(lst.begin(), lst.end(), m-lst[i]) - lst.begin();
        if(lst[i]+lst[pos]==m){
            flg = true;
            break;
        }
    }

    if(flg) cout << "Yes" << endl;
    else cout << "No" << endl;
}