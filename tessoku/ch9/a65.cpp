#include <bits/stdc++.h>
using namespace std;

int N, A[100009];
vector<int> g[100009];
int dp[100009];

int main(){
    cin >> N;
    for(int i=2;i<=N;i++){
        cin >> A[i];
        g[A[i]].push_back(i);
    }
    
    for(int i=N;i>0;i--){
        int tmp = 0;
        for(int j=0;j<g[i].size();j++){
            tmp += dp[g[i][j]] + 1;
        }
        dp[i] = tmp;
    }

    for(int i=1;i<=N;i++) cout << dp[i] << " ";
    cout << endl;
    return 0;
}