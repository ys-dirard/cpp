#include <bits/stdc++.h>
using namespace std;

// フェルマーの小定理
// if n is prime number, a^(n-1) === 1 (mod n)
// -> /a = *a^(n-2) (mod n)

long long H, W;
const long long wari = 1000000007;

long long power(long long a, long long b){
    long long ans = 1;
    long long p = a;
    for (int i=0; i < 30; i++){
        if ((b / (1<<i)) % 2 == 1){
            ans *= p;
            ans = ans % wari;
        }
        p = (p * p) % wari;
    }
    return ans;
}

long long factorial(long long n){
    long long ans = 1;
    for (int i=2; i<=n; i++){
        ans *= i;
        ans = ans % wari;
    }
    return ans;
}

long long combination(long long n, long long r){
    long long top, bottom;
    top = factorial(n);
    bottom = (factorial(r) * factorial(n-r)) % wari;
    return (top * power(bottom, wari-2)) % wari;
}

int main(){
    cin >> H >> W;
    cout << combination(H+W-2, H-1) << endl;
    return 0;
}