#include <bits/stdc++.h>
using namespace std;

int N, Q;
string S;
int L[200009], R[200009];
long long Hf[200009], Hr[200009], power100[200009];
long long mod = 2147483647;

long long a2d(char x){
    return x - 'a' + 1;
}

long long calc_hash_f(int l, int r){
    long long val = Hf[r] - (Hf[l-1] * power100[r-l+1] % mod);
    if (val < 0) val += mod;
    return val;
}

long long calc_hash_r(int l, int r){
    long long val = Hr[r] - (Hr[l-1] * power100[r-l+1] % mod);
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

    Hf[0] = 0;
    Hr[0] = 0;
    for(int i=1;i<=N;i++){
        Hf[i] = (Hf[i-1]*100LL + a2d(S[i-1])) % mod;
        Hr[i] = (Hr[i-1]*100LL + a2d(S[N-i])) % mod;
    }

    for(int i=1;i<=Q;i++){
        cin >> L[i] >> R[i];
        if (calc_hash_f(L[i], R[i]) == calc_hash_r(N-R[i]+1, N-L[i]+1)) cout << "Yes" << endl;
        else cout << "No" << endl;

    }
    return 0;
}