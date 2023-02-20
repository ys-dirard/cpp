#include <bits/stdc++.h>
using namespace std;

int Q, x, p;
priority_queue<int, vector<int>, greater<int>> prices;

int main(){
    cin >> Q;
    for(int i=1;i<=Q;i++){
        cin >> x;
        if(x==1){
            cin >> p;
            prices.push(p);
        }else if(x==2){
            cout << prices.top() << endl;
        }else if(x==3){
            prices.pop();
        }
    }
    return 0;
}