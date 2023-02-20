#include <bits/stdc++.h>
using namespace std;

int N, Q;
string S;
int a[200009], b[200009], c[200009], d[200009];
long long H[200009], power100[200009];
long long mod = 2147483647;

long long a2d(char x){
    return x - 'a' + 1;
}

long long calc_hash(int l, int r){
    long long val = H[r] - (H[l-1] * power100[r-l+1] % mod);
    if (val < 0) val += mod;
    return val;
}

int main(){
    cin >> N >> Q;
    cin >> S;
    power100[0] = 1;
    for(int i=1;i<=N;i++){
        power100[i] = (power100[i-1] * 100LL) % mod;
    }

    H[0] = 0;
    for(int i=1;i<=N;i++){
        H[i] = (H[i-1]*100LL + a2d(S[i-1])) % mod;
    }

    for(int i=1;i<=Q;i++){
        cin >> a[i] >> b[i] >> c[i] >> d[i];
        if (calc_hash(a[i], b[i]) == calc_hash(c[i], d[i])) cout << "Yes" << endl;
        else cout << "No" << endl;

    }
    return 0;
}