#include <bits/stdc++.h>

#define rep(i,s,n) for(int i = s; i < n; i++)
#define ll long long
#define P pair<ll, ll>

using namespace std;

ll N;


ll f(ll N){
    if(N==0) return 1LL;
    return f(N / 2) + f(N / 3);
}

int main(){
    // cin >> N;
    rep(i, 0, 200) cout << i << " " << f(i) << endl;
    return 0;
}