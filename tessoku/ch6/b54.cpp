#include <bits/stdc++.h>
using namespace std;

long long N, A[100009];
set<int> keys;
map<int, long long> cnt;

int main(){
    cin >> N;
    for(int i=1;i<=N;i++){
        cin >> A[i];
    }
    for(int i=1;i<=N;i++){
        keys.insert(A[i]);
        cnt[A[i]]++;
    }
    long long ans = 0LL;
    for(int i: keys){
        if(cnt[i]>1){
            ans += cnt[i]*(cnt[i]-1LL)/2LL;
        }
    }
    cout << ans << endl;
    return 0;
}