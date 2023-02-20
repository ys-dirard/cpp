#include <bits/stdc++.h>
using namespace std;

int N, A[200009];
long long counts[109];

int main(){
    cin >> N;
    for(int i=1;i<=N;i++){
        cin >> A[i];
        counts[A[i]] += 1;
    }
    long long ans = 0;
    for (int i=1; i<=100;i++){
        if (counts[i]>=3) ans += counts[i]*(counts[i]-1LL)*(counts[i]-2LL)/6LL;
    }
    cout << ans << endl;
    return 0;
}