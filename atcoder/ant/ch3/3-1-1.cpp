#include <bits/stdc++.h>
using namespace std;

// lower bound

// 長さnの単調非減少な数列a0,... , a_(n-1)が与えられる
// ai>=kとなるような最小のiを求めよ
// 存在しない場合はnを出力する
// 
// 
// 

int n, a[1000009];
int k;

bool solve(int m){
    return a[m] >= k;
}

// ok: 解が存在する範囲
// ng: 解が存在しない範囲
// 半開区間(ng, ok] or [ok, ng)を考える
// 解であるかどうかはsolve関数(別途用意)で判定
int binary_search(int ok, int ng){
    int mid;
    while(abs(ok - ng) > 1){
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
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    cin >> k;

    int ok = n;
    int ng = -1;
    int ans = binary_search(ok, ng);
    cout << ans << endl;
    return 0;
}