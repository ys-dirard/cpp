#include <bits/stdc++.h>
using namespace std;

int Q, q;
string x;
queue<string> names;


int main(){
    cin >> Q;
    for(int i=1;i<=Q;i++){
        cin >> q;
        if(q==1){
            cin >> x;
            names.push(x);
        }else if(q==2){
            cout << names.front() << endl;
        }else if(q==3){
            names.pop();
        }
    }
    return 0;
}