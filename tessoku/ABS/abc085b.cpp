#include <bits/stdc++.h>
using namespace std;

int N, d[109];

int main(){
    cin >> N;
    for(int i=1;i<=N;i++) cin >> d[i];
    sort(d+1, d+N+1);

    int ans = 0;
    for(int i=1;i<=N;i++){
        if(d[i]==d[i-1]) continue;
        else ans++;
    }
    cout << ans << endl;
    return 0;
}