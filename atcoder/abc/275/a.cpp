#include <bits/stdc++.h>

#define rep(i,s,n) for(int i = s; i < n; i++)
#define ll long long
#define P pair<ll, ll>

using namespace std;

ll N, H[109];
ll idx=0,maxh=0; 

int main(){
    cin >> N;
    rep(i, 1, N+1){
        cin >> H[i];
        if(maxh < H[i]){
            idx = i;
            maxh = H[i];
        }
    }
    cout << idx << endl;
    return 0;
}