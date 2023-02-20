#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll A, B, C;

ll gcd(ll x, ll y){
    if(y==0) return x;
    return gcd(y, x % y);
}

int main(){
    cin >> A >> B >> C;
    ll gd = 1;
    gd = gcd(A, B);
    gd = gcd(gd, C);
    
    ll ans = 0;
    ans += (A / gd - 1) + (B / gd - 1) + (C / gd - 1);
    cout << ans << endl;
    return 0;
}