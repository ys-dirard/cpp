#include <bits/stdc++.h>
using namespace std;

long long N,K;
long long dp[32][300009];
long long power10[30];

int main(){
    cin >> N >> K;
    for(int i=0;i<=N;i++){
        dp[0][i] = i;
    }

    power10[0] = 1;
    for(int j=1;j<11;j++){
        power10[j] = power10[j-1]*10;
    }

    for(int i=1;i<=N;i++){
        long long tmp = 0;
        for(int k=0;k<11;k++){
            tmp += (i / power10[k]) % 10;
        }
        dp[1][i] = dp[0][dp[0][i-tmp]];
    }

    for(int j=2;j<32;j++){
        for(int i=1;i<=N;i++){
            long long tmp = 0;
            for(int k=0;k<11;k++){
                tmp += (i / power10[k]) % 10;
            }
            dp[j][i] = dp[j-1][dp[j-1][i]];
        }
    }

    for(int i=1;i<=N;i++){
        long long pos = i;
        for(int j=0;j<32;j++){
            if(K & (1 << j)) pos = dp[j+1][pos];
        }
        cout << pos << endl;
    }
    return 0;
}