#include <bits/stdc++.h>
using namespace std;

long long N, K, A[200009], B[200009];
vector<int> pool;

int main(){
    cin >> N >> K;
    for(int i=1;i<=N;i++){
        cin >> A[i] >> B[i];
        pool.push_back(B[i]);
        pool.push_back(A[i]-B[i]);
    }

    sort(pool.begin(), pool.end(), greater<int>());
    long long ans = 0;
    for(int i=0;i<K;i++){
        ans += pool[i];
    }
    cout << ans << endl;
    return 0;
}