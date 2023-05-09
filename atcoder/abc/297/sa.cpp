#include <bits/stdc++.h>
using namespace std;
#define ll long long

int N;
string S[100];

ll dfs(ll n, ll cnt){
    if(n==0) return cnt;

    if(S[n]=="AND"){
        return dfs(n-1, cnt);
    }else{
        return dfs(n-1, (1LL<<n) + cnt);
    }
}


int main(){
    cin >> N;
    for(int i=1;i<=N;i++){
        cin >> S[i];
    }
    ll ans = dfs(N, 1);
    cout << ans << endl;
    return 0;
}