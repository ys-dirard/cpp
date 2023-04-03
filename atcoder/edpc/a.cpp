#include <bits/stdc++.h>
using namespace std;

int N;
int h[100009];
int dp[100009];

int main(){
    cin >> N;
    for(int i=1;i<=N;i++){
        cin >> h[i];
    }

    for(int i=2;i<=N;i++){
        if(i>2){
            dp[i] = min(dp[i-1]+abs(h[i]-h[i-1]), dp[i-2]+abs(h[i]-h[i-2]));
        }else{
            dp[i] = dp[i-1]+abs(h[i]-h[i-1]);
        }
    }
    cout << dp[N] << endl;
    return 0;
}