#include <bits/stdc++.h>
using namespace std;

int n, r, c;
pair<int, int> mat[109];
int dp[109][109];

int main(){
    cin >> n;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++) dp[i][j] = (1<<30);
    }
    for(int i=1;i<=n;i++){
        cin >> r >> c;
        mat[i] = {r, c};
    }
    for(int i=0;i<=n;i++) dp[i][i] = 0;
    
    for(int sum=1;sum<n;sum++){
        for(int i=1;i<=n;i++){
            int l = i;
            int r = i+sum;
            if(r>n) break;
            for(int m=l;m<r;m++){
                // cout << "l: " << l << ", m: " << m << ", r: " << r << endl;
                int x = mat[l].first;
                int y = mat[m].second;
                int z = mat[r].second;
                dp[l][r] = min(dp[l][r], dp[l][m]+dp[m+1][r]+x*y*z);
                // cout << dp[l][m]+dp[m+1][r]+x*y*z << endl;
                // cout << dp[l][r] << endl;
            }
        }
    }

    // cout << setw(10);
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         cout << setw(10) << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << dp[1][n] << endl;
    return 0;
}