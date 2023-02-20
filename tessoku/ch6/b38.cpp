#include <bits/stdc++.h>
using namespace std;

int N, ret1[1 << 18], ret2[1 << 18];
string S;

int main(){
    cin >> N >> S;

    int contA = 1;
    ret1[0] = 1;
    for (int i=0; i<N-1; i++){
        if (S[i]=='A') contA += 1;
        else contA = 1;
        ret1[i+1] = contA;
    }

    int contB = 1;
    ret2[N-1] = 1;
    for (int i=N-2; i>=0; i--){
        if (S[i]=='B') contB += 1;
        else contB = 1;
        ret2[i] = contB;
    }

    long long ans = 0;
    for (int i=0; i<N; i++) ans += max(ret1[i], ret2[i]);
    cout << ans << endl;
    return 0;
}