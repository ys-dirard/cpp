#include <bits/stdc++.h>
using namespace std;

int N, A, B;

int main(){
    cin >> N >> A >> B;
    int ans = 0;
    int power10[5] = {1, 10, 100, 1000, 10000};

    for(int i=1;i<=N;i++){
        int tmp = 0;
        for(int j=0;j<5;j++){
            tmp += (i / power10[j]) % 10;
        }
        if(A <= tmp && tmp <= B) ans += i;
    }
    cout << ans << endl;
    return 0;
}