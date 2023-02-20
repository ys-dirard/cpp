#include <bits/stdc++.h>
using namespace std;

int N, K, A[309], B[309];

int main(){
    cin >> N >> K;
    for (int i=1;i<=N; i++){
        cin >> A[i] >> B[i];
    }

    int ans = 0;
    for (int i=1;i<=100;i++){
        for (int j=1;j<=100;j++){
            int tmp=0;
            for (int k=1;k<=N;k++){
                if ((i <= A[k] && A[k] <= i + K) && (j <= B[k] && B[k] <= j + K)){
                    tmp += 1;
                }
            }
            ans = max(ans, tmp);
        }
    }
    cout << ans << endl;
    return 0;
}