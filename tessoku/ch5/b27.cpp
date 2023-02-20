#include <bits/stdc++.h>
using namespace std;

long long A, B;

long long gcd(long long a, long long b){
    long long x = max(a, b);
    long long y = min(a, b);
    while(y > 0){
        long long r = x % y;
        x = y;
        y = r;
    }
    return x;
}

long long lcm(long long a, long long b){
    long long r = gcd(a, b);
    return a * b / r;
}

int main(){
    cin >> A >> B;
    cout << lcm(A, B) << endl;
    return 0;
}