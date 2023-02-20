#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll K;
ll ans = 0;
vector<ll> divs;

void add_div(ll K){
    double rK = sqrt(K);
    for(ll i=1;i<=rK;i++){
        ll k = K;
        if(k % i == 0){
            divs.push_back(i);
            if(i != k / i) divs.push_back(k/i);
        }
    }
}

int main(){
    cin >> K;
    add_div(K);
    double rK = sqrt(K);
    double cK = cbrt(K);
    
    for(int i=0;i<divs.size();i++){
        if(divs[i] > cK) continue;
        ll k = K / divs[i];
        for(int j=i;j<divs.size();j++){
            if(k % divs[j] != 0 || divs[j]>rK) continue;
            else if(divs[j] <= (k / divs[j])){
                ans++;
                // cout << divs[i] << " " << divs[j] << " " << k / divs[j] << endl;
            }
        }
    }
    cout << ans << endl;

    return 0;
}