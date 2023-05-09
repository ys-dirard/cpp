#include <bits/stdc++.h>
using namespace std;

bool solve(long long m){

}

// ok: 解が存在する範囲
// ng: 解が存在しない範囲
// 半開区間(ng, ok] or [ok, ng)を考える
// 解であるかどうかはsolve関数(別途用意)で判定
// -> mが解であればtrueを返す
long long bin_search(long long ok, long long ng){
    long long mid;
    while(abs(ok - ng) > 1){
        mid = (ok + ng) / 2;

        if(solve(mid)){
            ok = mid;
        }else{
            ng = mid;
        }
    }
    return ok;
}

int main(){
    return 0;
}