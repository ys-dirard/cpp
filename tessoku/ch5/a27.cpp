#include <bits/stdc++.h>
using namespace std;

int A, B;

int gcd(int a, int b){
    int x = max(a, b);
    int y = min(a, b);
    while(y > 0){
        int r = x % y;
        x = y;
        y = r;
    }
    return x;
}

int main(){
    cin >> A >> B;
    cout << gcd(A, B) << endl;
    return 0;
}