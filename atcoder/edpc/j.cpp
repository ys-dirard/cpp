#include <bits/stdc++.h>
using namespace std;

int N;
int a[309];
double dp[309][309][309];
int cnt[4];

int main(){
    cin >> N;
    for(int i=1;i<=N;i++){
        cin >> a[i];
        cnt[a[i]]++;
    }

    for(int k=0;k<=N;k++){
        for(int j=0;j<=N;j++){
            for(int i=0;i<=N;i++){
                if(i+j+k==0) continue;
                double exp = 1.0 * N / (i+j+k);
                if(i>0) exp += dp[i-1][j][k] * i / (i+j+k);
                if(j>0) exp += dp[i+1][j-1][k] * j / (i+j+k);
                if(k>0) exp += dp[i][j+1][k-1] * k / (i+j+k);
                dp[i][j][k] = exp;
            }
        }
    }

    cout << fixed << setprecision(15) << dp[cnt[1]][cnt[2]][cnt[3]] << endl;
    return 0;
}