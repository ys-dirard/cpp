#include <bits/stdc++.h>
using namespace std;

int Q, q, x;
set<int> S;

int main(){
    cin >> Q;
    for(int i=1;i<=Q;i++){
        cin >> q >> x;
        if(q==1){
            S.insert(x);
        }else{
            auto itr = S.lower_bound(x);
            if(S.empty()){
                cout << -1 << endl;
            }else if(itr==S.begin()){
                cout << *itr - x << endl;
            }else if(itr==S.end()){
                cout << x - *(--itr) << endl;
            }else{
                cout << min({(*itr)-x, x - *(--itr)}) << endl;
            }
        }
    }
    return 0;
}