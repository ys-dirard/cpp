#include <bits/stdc++.h>
using namespace std;

int N, A[209];

int main(){
    cin >> N;
    for(int i=1;i<=N;i++) cin >> A[i];

    int ans = 10000000;
    for(int i=1;i<=N;i++){
        int tmp = 0;
        while(A[i] % 2 == 0){
            A[i] = A[i] / 2;
            tmp++;
        }
        ans = min(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}