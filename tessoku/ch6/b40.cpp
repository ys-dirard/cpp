#include <bits/stdc++.h>
using namespace std;

int N;
long long A[200009];
long long cnt[109];

int main(){
    cin >> N;
    for (int i=1;i<=N;i++) {
        cin >> A[i];
        cnt[A[i] % 100] += 1LL;
    }
    long long ans = 0;
    for (int i=0;i<=50;i++){
        if (i==0 || i==50){
            ans += cnt[i]*(cnt[i]-1LL)/2LL;
        } else {
            long long tmp = 1LL << 30LL;
            tmp = cnt[i]*cnt[100-i];
            ans += tmp;
        }
    }
    std::cout << ans << endl;
    return 0;
}