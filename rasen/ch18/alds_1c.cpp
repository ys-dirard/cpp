#include <bits/stdc++.h>
using namespace std;

bool is_prime(int x){
    if(x==1) return false;
    bool flg = true;
    double rx = sqrt(x);

    for(int i=2;i<=rx;i++){
        if(x % i == 0) flg = false;
    }
    return flg;
}

int main(){
    int n, x;
    cin >> n;

    int ans = 0;
    for(int i=0;i<n;i++){
        cin >> x;
        ans += is_prime(x);
    }
    cout << ans << endl;
    return 0;
}