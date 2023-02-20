#include <bits/stdc++.h>
using namespace std;

int N, T[109], D[109];
vector<pair<int, int>> v;
int dp[109][1449];

int main(){
    cin >> N;
    for(int i=1;i<=N;i++){
        cin >> T[i] >> D[i];
        v.push_back(make_pair(D[i], T[i]));
    }
    sort(v.begin(), v.end());

    for(int i=0;i<=N;i++){
        for(int j=0;j<=1440;j++) dp[i][j] = -1;
    }

    dp[0][0] = 0;
    for(int i=1;i<=N;i++){
        for(int j=0;j<=1440;j++){
            if(v[i-1].second <= j && j <= v[i-1].first){
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-v[i-1].second]+1);
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    int ans = 0;
    for(int j=0;j<=1440;j++){
        ans = max(ans, dp[N][j]);
    }
    cout << ans << endl;
    return 0;
}