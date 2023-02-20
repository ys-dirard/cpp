#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, S[100009], q, T[509];
    cin >> n;
    for(int i=1;i<=n;i++) cin >> S[i];
    cin >> q;
    for(int i=1;i<=q;i++) cin >> T[i];

    set<int> ans;
    for(int i=1;i<=q;i++){
        for(int j=1;j<n;j++){
            if(S[j]==T[i]) ans.insert(S[j]);
        }
    }
    cout << ans.size() << endl;
    return 0;
}