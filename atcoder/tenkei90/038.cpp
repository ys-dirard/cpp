#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long

ull gcd(ull x, ull y){
    if(y==0) return x;
    return gcd(y, x%y);
}

bool check(ull x, ull y, ull m){
    // if(log10l(x)+log10l(y)-log10l(m) > 18ULL) return false; // logはやっぱり誤差が出るっぽい、、、。
    ull r = y / m;
    if(r > 1000000000000000000ULL / x) return false;
    return true;

}

ull A, B;

int main(){
    cin >> A >> B;
    ull gd = gcd(A, B);
    if(check(A, B, gd)) cout << (A / gd * B) << endl;
    else cout << "Large" << endl;
    return 0;
}