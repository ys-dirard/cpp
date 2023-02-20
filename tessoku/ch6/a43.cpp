#include <bits/stdc++.h>
using namespace std;

int N, L, A[200009];
char B[200009];

int main(){
    cin >> N >> L;
    for(int i=1;i<=N;i++){
        cin >> A[i] >> B[i];
    }

    int ans = 0;
    for (int i=1;i<=N;i++){
        if (B[i]=='E') A[i] = L-A[i];
        ans = max(ans, A[i]);
    }
    cout << ans << endl;
    return 0;
}