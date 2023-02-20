#include <bits/stdc++.h>
using namespace std;

long long A, B, C, N;

int main(){
    cin >> N >> A >> B >> C;
    int M = 9999;
    int ans = M;
    for(int i=0;i<=M;i++){
        for(int j=0;j<=M-i;j++){
            if(A*i+B*j<=N && (N - (A*i+B*j))%C==0){
                int k = (N - (A*i+B*j))/C;
                // cout << "k: " << k << endl;
                // cout << i+j+k << endl;
                ans = min(ans, i+j+k);
            }
        }
    }
    cout << ans << endl;
    return 0;
}