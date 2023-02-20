#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll N;
ll A[100009];
ll S = 0;

int main(){
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> A[i];
        S += A[i];
    }
    if(S % 10 != 0){
        cout << "No" << endl;
        return 0;
    }

    ll target = S / 10;
    ll l = 0, r = 0;
    ll tmp = 0;
    // cout << "target: " << target << endl;
    while(l!=N){
        // cout << "l: " << l << ", r: " << r << ", tmp: " << tmp << endl;
        if(tmp<target){
            r++;
            r %= N;
            tmp += A[r];
        }else if(tmp>target){
            tmp -= A[++l];
        }else{
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}