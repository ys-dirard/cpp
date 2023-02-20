#include <bits/stdc++.h>
using namespace std;

int X, Y;
stack<int> sx, sy;

int main(){
    cin >> X >> Y;
    while(X>1 || Y>1){
        sx.push(X);
        sy.push(Y);
        if (X>Y){
            X = X - Y;
        }else{
            Y = Y - X;
        }
    }

    cout << sx.size() << endl;
    while(!sx.empty()){
        cout << sx.top() << " " << sy.top();
        sx.pop();
        sy.pop();
        cout << endl;
    }
    return 0;
}