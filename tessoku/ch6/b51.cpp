#include <bits/stdc++.h>
using namespace std;

string S;
stack<int> ind;

int main(){
    cin >> S;
    for(int i=0;i<S.size();i++){
        if(S[i]=='('){
            ind.push(i+1);
        }else if(S[i]==')'){
            cout << ind.top() << " " << i+1 << endl;
            ind.pop();
        }
    }
    return 0;
}