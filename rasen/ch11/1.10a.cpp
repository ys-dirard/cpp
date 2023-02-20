#include <bits/stdc++.h>
using namespace std;

int n;
long long fib[50];

int main(){
    fib[0] = fib[1] = 1;
    cin >> n;
    for(int i=2;i<=n;i++){
        fib[i] = fib[i-1] + fib[i-2];
    }
    cout << fib[n] << endl;
    return 0;
}