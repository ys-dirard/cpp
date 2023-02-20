#include <bits/stdc++.h>
using namespace std;

int Q, q_type;
string x;
stack<string> books;

int main(){
    cin >> Q;
    for(int i=1;i<=Q;i++){
        cin >> q_type;
        if(q_type==1){
            cin >> x;
            books.push(x);
        }else if(q_type==2){
            cout << books.top() << endl;
        }else if(q_type==3){
            books.pop();
        }
    }
    return 0;
}