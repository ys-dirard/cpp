#include <bits/stdc++.h>
using namespace std;

int n, q;
int A[29], ms[209];

bool solve(int i, int m){
    if(A[i]==m) return true;
    else if(i==n) return false;

    bool ans1 = solve(i+1, m);
    bool ans2 = solve(i+1, m - A[i]);

    if(ans1 || ans2) return true;
    else return false;
}

int main(){
    cin >> n;
    for(int i=1;i<=n;i++) cin >> A[i];
    cin >> q;
    for(int i=1;i<=q;i++) cin >> ms[i];

    for(int i=1;i<=q;i++){
        if(solve(1, ms[i])){
            cout << "yes" << endl;
        }else{
            cout << "no" << endl;
        }
    }
    return 0;
}