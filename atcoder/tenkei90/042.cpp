#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1000000007LL;

ll K;
ll dp[100009];

int main(){
    cin >> K;
    for(int i=0;i<=K;i++) dp[i] = 0;
    dp[0] = 1;
    
    for(int i=1;i<=K;i++){
        for(int j=1;j<=9;j++){
            if(i-j>=0){
                dp[i] += dp[i-j];
                dp[i] %= MOD;
            }
        }
    }

    if(K % 9 == 0) cout << dp[K] << endl;
    else cout << "0" << endl;
    return 0;
}