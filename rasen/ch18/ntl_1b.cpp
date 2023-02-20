#include <bits/stdc++.h>
using namespace std;

const long long mod = 1'000'000'007;
long long m, n;

long long power(long long m, long long n, long long mod){
    long long ans = 1LL;

    for(int i=0;i<30;i++){
        if(n & (1<<i)){
            ans *= m;
            ans %= mod;
        }
        m = m*m;
        m %= mod;
    }

    return ans;
}

int main(){
    cin >> m >> n;
    cout << power(m, n, mod) << endl;
    return 0;
}