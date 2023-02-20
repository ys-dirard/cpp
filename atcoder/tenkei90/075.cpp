#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll N;

ll get_n_div(ll x){
    double rx = sqrt(x);
    ll res = 0;
    for(int i=2;i<=rx;i++){
        while(x % i == 0){
            res++;
            x /= i;
        }
    }
    if(x>1) res++;

    return res;
}

int main(){
    cin >> N;
    ll n_div = get_n_div(N);
    // cout << n_div << endl;
    ll ans = 0;
    n_div--;
    while(n_div>0){
        ans++;
        n_div /= 2;
    }
    cout << ans << endl;
    return 0;
}