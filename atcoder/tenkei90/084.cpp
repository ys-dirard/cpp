#include <bits/stdc++.h>
using namespace std;

int N;
string S;

int main(){
    cin >> N >> S;
    int l = 0, r = 1;
    long long ans = 0LL;
    
    while(l!=N-1){
        while(S[l]==S[r] && r<N-1){
            r++;
        }
        if(S[l] != S[r]){
            ans += N - r;
        }
        l++;
    }
    cout << ans << endl;
    return 0;
}