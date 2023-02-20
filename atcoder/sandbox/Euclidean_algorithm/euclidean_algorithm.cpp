#include <bits/stdc++.h>
using namespace std;

/* a と b (a >= b) の最大公約数を返す関数 O(log a)*/
long long GCD(long long a, long long b) {
    if (b == 0) return a;
    else return GCD(b, a % b);
}

// 返り値: a と b の最大公約数
// ax + by = gcd(a, b) を満たす (x, y) が格納される
/*
bx' + (a%b)y' = gcd(a, b) の解x', y'が求まっているとすると
a % b = a - (a/b)b なので
ay' + b(x' - (a/b)y') = gcd(a, b) となる。
-> a, bの係数が入れ替わり、bの方はさらにa/bを引く！

b=0の時は
a*1 + b*0 = a = gcd(a, b) である。

計算量はO(log max(a, b))
解の大きさは ab≠0 -> |x| <= b, |y| <=a である。
*/
long long extGCD(long long a, long long b, long long &x, long long &y) {
    // cout << "called: a=" << a << ", b=" << b << endl;
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long d = extGCD(b, a%b, y, x);
    y -= a/b * x;
    // cout << "ax+by=d: (" << a << ")*(" << x << ")+(" << b << ")*(" << y << ")=(" << d << ")" << endl;
    return d;
}

int main(){
    long long d, x, y;
    long long a = 111, b = 33;
    d = extGCD(a, b, x, y);
    cout << x << ", " << y << endl;
    cout << "ax+by=d: (" << a << ")*(" << x << ")+(" << b << ")*(" << y << ")=(" << d << ")" << endl;
    return 0;
}