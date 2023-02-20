#include <bits/stdc++.h>
using namespace std;

// cable master

// 長さがそれぞれLiである紐がN本ある
// これらの紐を切って、同じ長さの紐をK本
// 切るときの最長の長さを求める

int N, K;
double L[10009];

bool solve(double m){
    int ans = 0;
    for(int i=0;i<N;i++){
        ans += (int)(L[i] / m);
    }
    return ans >= K;
}

// ok: 解が存在する範囲
// ng: 解が存在しない範囲
// 半開区間(ng, ok] or [ok, ng)を考える
// 解であるかどうかはsolve関数(別途用意)で判定
// -> mが解であればtrueを返す
double binary_search(double ok, double ng){
    double mid;
    while(abs(ok - ng) > 1e-3){
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
    cin >> N >> K;
    for(int i=0;i<N;i++){
        cin >> L[i];
    }
    double ok = 0.00;
    double ng = 100000;
    double ans = binary_search(ok, ng);
    cout << fixed << setprecision(2) << ans << endl;
    return 0;
}