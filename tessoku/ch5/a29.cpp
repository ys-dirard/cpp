#include <bits/stdc++.h>
using namespace std;

long long a, b;
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

int main(){
    cin >> a >> b;
    cout << power(a, b) << endl;
    return 0;
}