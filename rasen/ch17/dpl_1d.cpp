#include <bits/stdc++.h>
using namespace std;

int n;
int a[100009];
int L[100009];

int main(){
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n+1;i++) L[i] = 1<<30;

    for(int i=1;i<=n;i++){
        int pos = lower_bound(L+1, L+n+1, a[i]) - L;
        L[pos] = a[i]; 
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        if(L[i]<(1<<30)) ans = i;
    }
    cout << ans << endl;
    return 0;
}