#include <bits/stdc++.h>
using namespace std;

int N, S, A[69];
bool dp[69][10009];
vector<int> R;

int main(){
    cin >> N >> S;
    for (int i=1; i<=N; i++) cin >> A[i];

    for (int i=1; i<=N; i++) {
        for (int j=0; j<=S; j++) {
            dp[i][j] = false;
        }
    }

    dp[0][0] = true;
    for (int i=1; i<=N; i++) {
        for (int j=0; j<=S; j++) {
            if (A[i] <= j) {
                dp[i][j] = dp[i-1][j] | dp[i-1][j-A[i]];
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    
    if (dp[N][S]) {
        int tmp_i = N, tmp_S = S;
        while(tmp_i > 0 && tmp_S > 0) {
            if (dp[tmp_i-1][tmp_S]){
                tmp_i = tmp_i - 1;
            } else {
                R.push_back(tmp_i);
                tmp_S = tmp_S - A[tmp_i];
                tmp_i = tmp_i - 1;
            }
        }
        reverse(R.begin(), R.end());
        cout << R.size() << endl;
        for (int i=0; i<R.size(); i++) cout << R[i] << " ";
    } else {
        cout << -1 << endl;
    }
    return 0;
}