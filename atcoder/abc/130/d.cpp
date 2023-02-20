#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll N, K;
ll a[100009];
ll s[100009];

int main(){
    cin >> N >> K;
    for(int i=1;i<=N;i++){
        cin >> a[i];
        s[i] = (1<<30);
    }

    s[0] = 0;
    for(int i=1;i<=N;i++){
        s[i] = s[i-1] + a[i];
    }

    // 二分探索
    ll cnt = 0LL;
    for(int i=1;i<=N;i++){
        ll pos = lower_bound(s+i, s+N+1, K+s[i-1]) - s;
        if(pos <= N) cnt += (N - pos + 1);
    }

    // 尺取り法
    ll cnt2 = 0LL;
    int l = 1, r = 1;
    s[N+1] = (1LL<<60);
    while(l<=N){
        while(s[r]-s[l-1]<K){
            r++;
        }
        cnt2 += (N - r + 1);
        l++;
    }

    cout << cnt2 << endl;
    return 0;
}