#include <bits/stdc++.h>
using namespace std;

int main(){
    // min / max ///////////////////////////////////////////////////////////////////
    cout << max({103, 168, 103}) << endl;

    // 例 2: {c[1], c[2], ..., c[N]} の最小値を出力する方法 1 つ目
    int N=5, c[100009]={19, 33, 11, 452, 2, 111}, minx = 2147483647;
    // cin >> N;

    // for (int i = 1; i <= N; i++) cin >> c[i];
    for (int i = 1; i <= N; i++) minx = min(minx, c[i]);
    cout << minx << endl;

    // 例 3: {c[1], c[2], ..., c[N]} の最小値を出力する方法 2 つ目 min_element(l, r)->[l, r)
    cout << *min_element(c + 1, c + N + 1) << endl;
    return 0;
}