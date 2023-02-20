#include <bits/stdc++.h>
using namespace std;

int Q, q, x;
set<int> num;

int main(){
    cin >> Q;
    for(int i=1;i<=Q;i++){
        cin >> q >> x;
        if(q==1){
            num.insert(x);
        }else if(q==2){
            num.erase(x);
        }else{
            auto ind = num.lower_bound(x);
            if (ind == num.end()){
                cout << -1 << endl;
                continue;
            }
            cout << *ind << endl; 
        }
    }
    return 0;
}