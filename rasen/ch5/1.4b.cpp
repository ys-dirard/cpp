#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, S[1000009], q, T[50009];
    scanf("%d", &n);
    for(int i=1;i<=n;i++) scanf("%d", &S[i]);
    scanf("%d", &q);
    for(int i=1;i<=q;i++) scanf("%d", &T[i]);

    set<int> ans;
    for(int i=1;i<=q;i++){
        // int t = lower_bound(S+1, S+n+1, T[i]) - S;
        //     if(S[t]==T[i]) ans.insert(T[i]);
        
        int l=1, r=n;
        while(l<=r){
            int m = (l+r)/2;
            if(S[m]>T[i]){
                r = m-1;
            }else if(S[m]<T[i]){
                l = m+1;
            }else{
                ans.insert(T[i]);
                break;
            }
        }
    }
    cout << ans.size() << endl;
    return 0;
}